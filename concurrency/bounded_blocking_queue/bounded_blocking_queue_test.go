package queue

import (
    "sync"
    "testing"
    "time"
)

// TestBasicOperations tests basic enqueue and dequeue operations
func TestBasicOperations(t *testing.T) {
    q := NewBoundedBlockingQueue(3)
    
    q.Enqueue(1)
    q.Enqueue(2)
    q.Enqueue(3)
    
    if size := q.Size(); size != 3 {
        t.Errorf("Expected size 3, got %d", size)
    }
    
    // Test dequeue
    if val := q.Dequeue(); val != 1 {
        t.Errorf("Expected 1, got %d", val)
    }
    if val := q.Dequeue(); val != 2 {
        t.Errorf("Expected 2, got %d", val)
    }
    
    if size := q.Size(); size != 1 {
        t.Errorf("Expected size 1, got %d", size)
    }
}

// TestConcurrentAccess tests multiple producers and consumers
func TestConcurrentAccess(t *testing.T) {
    q := NewBoundedBlockingQueue(5)
    var wg sync.WaitGroup
    
    // Track dequeued values to verify all enqueued values are received
    receivedValues := make(map[int]bool)
    var receivedMutex sync.Mutex
    
    // Start 3 producers
    for i := 0; i < 3; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            for j := 0; j < 3; j++ {
                value := id*100 + j
                q.Enqueue(value)
            }
        }(i)
    }
    
    // Start 2 consumers
    for i := 0; i < 2; i++ {
        wg.Add(1)
        go func() {
            defer wg.Done()
            for j := 0; j < 4; j++ {
                value := q.Dequeue()
                receivedMutex.Lock()
                receivedValues[value] = true
                receivedMutex.Unlock()
            }
        }()
    }
    
    wg.Wait()
    
    // Verify size
    if size := q.Size(); size != 1 { // 9 enqueued - 8 dequeued = 1
        t.Errorf("Expected final size 1, got %d", size)
    }
    
    // Verify number of unique values received
    if len(receivedValues) != 8 { // Should have received 8 unique values
        t.Errorf("Expected 8 unique values, got %d", len(receivedValues))
    }
}

// TestBlockingBehavior tests that the queue blocks when full/empty
func TestBlockingBehavior(t *testing.T) {
    q := NewBoundedBlockingQueue(2)
    
    // Fill the queue
    q.Enqueue(1)
    q.Enqueue(2)
    
    // Test blocking on full queue
    enqueued := make(chan bool)
    go func() {
        // This should block
        q.Enqueue(3)
        enqueued <- true
    }()
    
    // Verify that enqueue is blocked
    select {
    case <-enqueued:
        t.Error("Enqueue should have blocked on full queue")
    case <-time.After(100 * time.Millisecond):
        // This is expected
    }
    
    // Dequeue to allow the blocked enqueue to proceed
    q.Dequeue()
    
    // Verify that enqueue proceeded
    select {
    case <-enqueued:
        // This is expected
    case <-time.After(100 * time.Millisecond):
        t.Error("Enqueue should have proceeded after dequeue")
    }
}

// TestStressTest performs rapid concurrent operations
func TestStressTest(t *testing.T) {
    q := NewBoundedBlockingQueue(10)
    var wg sync.WaitGroup
    numProducers := 5
    numConsumers := 5
    opsPerGoroutine := 100
    
    // Start producers
    for i := 0; i < numProducers; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            for j := 0; j < opsPerGoroutine; j++ {
                q.Enqueue(id*1000 + j)
            }
        }(i)
    }
    
    // Start consumers
    for i := 0; i < numConsumers; i++ {
        wg.Add(1)
        go func() {
            defer wg.Done()
            for j := 0; j < opsPerGoroutine; j++ {
                q.Dequeue()
            }
        }()
    }
    
    wg.Wait()
    
    // Verify final size
    if size := q.Size(); size != 0 {
        t.Errorf("Expected final size 0, got %d", size)
    }
}

// TestEmptyDequeue tests blocking behavior when queue is empty
func TestEmptyDequeue(t *testing.T) {
    q := NewBoundedBlockingQueue(2)
    
    // Test blocking on empty queue
    dequeued := make(chan bool)
    go func() {
        // This should block
        q.Dequeue()
        dequeued <- true
    }()
    
    // Verify that dequeue is blocked
    select {
    case <-dequeued:
        t.Error("Dequeue should have blocked on empty queue")
    case <-time.After(100 * time.Millisecond):
        // This is expected
    }
    
    // Enqueue to allow the blocked dequeue to proceed
    q.Enqueue(1)
    
    // Verify that dequeue proceeded
    select {
    case <-dequeued:
        // This is expected
    case <-time.After(100 * time.Millisecond):
        t.Error("Dequeue should have proceeded after enqueue")
    }
}