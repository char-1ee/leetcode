package main

import (
	"fmt"
	"sync"
)

type ZeroEvenOdd struct {
	n int
	ch0 chan struct{}	// zero
	ch1 chan struct{}	// odd
	ch2 chan struct{}	// even
}

func NewZeroEveneOdd(n int) *ZeroEvenOdd {
	rt := &ZeroEvenOdd{
		n: n,
		ch0: make(chan struct{}, 1),
		ch1: make(chan struct{}, 1),
		ch2: make(chan struct{}, 1),
	}
	rt.ch0 <- struct{}{}
	return rt
}

func (p *ZeroEvenOdd) zero(printNumber func(int)) {
	for i := 0; i < p.n; i++ {
		<-p.ch0
		printNumber(0)
		if i % 2 == 0 {
			p.ch1 <- struct{}{}
		} else {
			p.ch2 <- struct{}{}
		}
	}
}

func (p *ZeroEvenOdd) odd(printNumber func(int)) {
	for i := 1; i <= p.n; i += 2 {
		<-p.ch1
		printNumber(i)
		p.ch0 <- struct{}{}
	}
}

func (p *ZeroEvenOdd) even(printNumber func(int)) {
	for i := 2; i <= p.n; i += 2 {
		<- p.ch2
		printNumber(i)
		p.ch0 <- struct{}{}
	}

}

func main() {
	var wg sync.WaitGroup
	wg.Add(3)
	n := 6
	p := NewZeroEveneOdd(n)
	printNumber := func(n int) {
		fmt.Print(n)
	}

	go func() {
		defer wg.Done()
		p.zero(printNumber)
	}()
	go func() {
		defer wg.Done()
		p.even(printNumber)
	}()
	go func() {
		defer wg.Done()
		p.odd(printNumber)
	}()
	
	wg.Wait()
	fmt.Println()
}