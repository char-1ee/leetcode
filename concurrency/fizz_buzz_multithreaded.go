package main

import (
	"fmt"
	"sync"
)

type FizzBuzz struct {
	n          int
	fizzCh     chan struct{}
	buzzCh     chan struct{}
	fizzBuzzCh chan struct{}
	numCh      chan int
	done       chan struct{}
}

func NewFizzBuzz(n int) *FizzBuzz {
	return &FizzBuzz{
		n:          n,
		fizzCh:     make(chan struct{}),
		buzzCh:     make(chan struct{}),
		fizzBuzzCh: make(chan struct{}),
		numCh:      make(chan int),
		done:       make(chan struct{}),
	}
}

func (fb *FizzBuzz) printFizz() {
	for {
		select {
		case <-fb.fizzCh:
			fmt.Println("fizz")
		case <-fb.done:
			return
		}
	}
}

func (fb *FizzBuzz) printBuzz() {
	for {
		select {
		case <-fb.buzzCh:
			fmt.Println("buzz")
		case <-fb.done:
			return
		}
	}
}

func (fb *FizzBuzz) printFizzBuzz() {
	for {
		select {
		case <-fb.fizzBuzzCh:
			fmt.Println("fizzbuzz")
		case <-fb.done:
			return
		}
	}

}

func (fb *FizzBuzz) printNumber() {
	for {
		select {
		case num := <-fb.numCh:
			fmt.Println(num)
		case <-fb.done:
			return
		}
	}
}

func (fb *FizzBuzz) master() {
	for i := 1; i <= fb.n; i++ {
		if i%3 == 0 && i%5 == 0 {
			fb.fizzBuzzCh <- struct{}{}
		} else if i%3 == 0 {
			fb.fizzCh <- struct{}{}
		} else if i%5 == 0 {
			fb.buzzCh <- struct{}{}
		} else {
			fb.numCh <- i
		}
	}
	close(fb.done)
}

func main() {
	var wg sync.WaitGroup
	wg.Add(4)
	n := 15
	fb := NewFizzBuzz(n)

	executor := func(wg *sync.WaitGroup, f func()) {
		defer wg.Done()
		f()
	}
    go fb.master()
	go executor(&wg, fb.printFizz)
	go executor(&wg, fb.printBuzz)
	go executor(&wg, fb.printFizzBuzz)
	go executor(&wg, fb.printNumber)

	wg.Wait()
	fmt.Printf("Done")
}
