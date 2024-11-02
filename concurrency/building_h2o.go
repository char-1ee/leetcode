package main

import (
    "sync"
    "fmt"
)

type WaterBarrier struct {
    n int
    H chan int
    O chan int
    done chan struct{}
    barrier chan struct{}
}

func NewWaterBarrier(n int) *WaterBarrier {
    return &WaterBarrier{
        n: n,
        H: make(chan int),
        O: make(chan int),
        done: make(chan struct{}),
        barrier: make(chan struct{}),
    }
}

func (w *WaterBarrier) releaseHydrogen(i int) {
    w.H <- i
    <-w.barrier
}

func (w *WaterBarrier) releaseOxygen(i int) {
    w.O <- i
    <-w.barrier
}

func (w *WaterBarrier) formMolecules() {
    for {
        select {
        case <- w.done:
            return
        default:
            h1 := <-w.H
            h2 := <-w.H
            o := <-w.O
            fmt.Printf("Forming water molecule with O(%d) + H(%d) + H(%d)\n", o, h1, h2)
            w.barrier <- struct{}{}
            w.barrier <- struct{}{}
            w.barrier <- struct{}{}
        }
    }
}

func main() {
    n := 3
    w := NewWaterBarrier(n)
    var wg sync.WaitGroup

    go w.formMolecules()

    for i := 0; i < n * 2; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            fmt.Printf("Hydrogen %d ready\n", id)
            w.releaseHydrogen(id)
            fmt.Printf("Hydrogen %d done\n", id)
        }(i)
    }

    for i := 0; i < n; i++ {
        wg.Add(1)
        go func(id int) {
            defer wg.Done()
            fmt.Printf("Oxygen %d ready\n", id)
            w.releaseOxygen(id)
            fmt.Printf("Oxygen %d done\n", id)
        }(i)
    }

    wg.Wait()
    close(w.done)
    fmt.Println("All water molecules have been formed!")
}
