package queue

import (
    "fmt"
    "sync"
    "time"
)

type BoundedBlockingQueue struct {
    queue []int
    capacity int
    size int

    mu sync.Mutex
    notFull *sync.Cond  // signaled when queue not full
    notEmpty *sync.Cond // signaled when queue not empty

    front int // head of queue
    rear int // tail of queue
}

func NewBoundedBlockingQueue(n int) *BoundedBlockingQueue {
    q := &BoundedBlockingQueue{
        queue: make([]int, n),
        capacity: n,
    }
    q.notFull = sync.NewCond(&q.mu)
    q.notEmpty = sync.NewCond(&q.mu)
    return q
}

func (q *BoundedBlockingQueue) Enqueue(element int) {
    q.mu.Lock()
    defer q.mu.Unlock()
    
    for q.capacity == q.size {
        q.notFull.Wait()
    }

    q.queue[q.rear] = element
    q.size ++
    q.rear = (q.rear + 1) % q.capacity

    q.notEmpty.Signal()
}

func (q *BoundedBlockingQueue) Dequeue() int {
    q.mu.Lock()
    defer q.mu.Unlock()

    for q.size == 0 {
        q.notEmpty.Wait()
    }

    element := q.queue[q.front]
    q.front = (q.front + 1) % q.capacity
    q.size -- 

    q.notFull.Signal()
    return element
}

func (q *BoundedBlockingQueue) Size() int {
    q.mu.Lock()
    defer q.mu.Unlock()
    return q.size
}

func (q *BoundedBlockingQueue) Peek() (int, bool) {
    q.mu.Lock()
    defer q.mu.Unlock()
    if q.size == 0 {
        return -1, false
    }
    return q.queue[q.front], true
}

func main() {
    // Create a queue with capacity 3
    queue := NewBoundedBlockingQueue(3)
    var wg sync.WaitGroup

    // Test 1: Basic enqueue/dequeue
    fmt.Println("Test 1: Basic operations")
    queue.Enqueue(1)
    queue.Enqueue(2)
    queue.Enqueue(3)
    fmt.Printf("After enqueuing 3 elements, size: %d\n", queue.Size())
    
    fmt.Printf("Dequeued: %d\n", queue.Dequeue())
    fmt.Printf("Dequeued: %d\n", queue.Dequeue())
    fmt.Printf("After dequeuing 2 elements, size: %d\n", queue.Size())

    // Test 2: Multiple producers and consumers
    fmt.Println("\nTest 2: Multiple producers and consumers")
    // Reset queue
    queue = NewBoundedBlockingQueue(5)

    // Start 3 producers
    for i := 0; i < 3; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            for j := 0; j < 3; j++ {
                value := id*100 + j
                queue.Enqueue(value)
                fmt.Printf("Producer %d enqueued: %d\n", id, value)
                time.Sleep(100 * time.Millisecond)
            }
        }(i)
    }

    // Start 2 consumers
    for i := 0; i < 2; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            for j := 0; j < 4; j++ {
                value := queue.Dequeue()
                fmt.Printf("Consumer %d dequeued: %d\n", id, value)
                time.Sleep(200 * time.Millisecond)
            }
        }(i)
    }

    // Test 3: Test blocking behavior
    fmt.Println("\nTest 3: Testing blocking behavior")
    wg.Add(1)
    go func() {
        defer wg.Done()
        fmt.Println("Attempting to enqueue to full queue...")
        queue.Enqueue(999) // This should block until there's space
        fmt.Println("Successfully enqueued 999")
    }()

    // Give some time for operations to show blocking behavior
    time.Sleep(1 * time.Second)
    fmt.Printf("Current queue size: %d\n", queue.Size())

    // Wait for all goroutines to complete
    wg.Wait()
    fmt.Printf("\nFinal queue size: %d\n", queue.Size())

    // Test 4: Rapid fire test
    fmt.Println("\nTest 4: Rapid fire test")
    queue = NewBoundedBlockingQueue(10)
    var rapidWg sync.WaitGroup

    // Start 5 rapid producers
    for i := 0; i < 5; i++ {
        rapidWg.Add(1)
        go func(id int) {
            defer rapidWg.Done()
            for j := 0; j < 10; j++ {
                queue.Enqueue(id*1000 + j)
            }
        }(i)
    }

    // Start 5 rapid consumers
    for i := 0; i < 5; i++ {
        rapidWg.Add(1)
        go func(id int) {
            defer rapidWg.Done()
            for j := 0; j < 10; j++ {
                queue.Dequeue()
            }
        }(i)
    }

    rapidWg.Wait()
    fmt.Printf("After rapid fire test, queue size: %d\n", queue.Size())
}