package main

import (
	"sync"
	"time"
	"fmt"
)

type Executor struct {
	ch1 chan struct{}
	ch2 chan struct{}
}

func NewExecutor() *Executor {
	return &Executor{
		ch1: make(chan struct{}),
		ch2: make(chan struct{}),
	}
}

func (e *Executor) first() {
	fmt.Println("First")
	e.ch1 <- struct{}{}
}

func (e *Executor) second() {
	<-e.ch1
	fmt.Println("Second")
	e.ch2 <- struct{}{}
}

func (e *Executor) third() {
	<-e.ch2
	fmt.Println("Third")
}

func main() {
	executor := NewExecutor()
	var wg sync.WaitGroup
	wg.Add(3)

	go func() {
		defer wg.Done()
		time.Sleep(100 * time.Millisecond)
		executor.first()
	}()

	go func() {
		defer wg.Done()
		time.Sleep(200 * time.Millisecond)
		executor.second()
	}()

	go func() {
		defer wg.Done()
		executor.third()
	}()

	wg.Wait()
}