package main

import (
	"fmt"
	"sync"
)

type FooBar struct {
	n int
	fooCh chan struct{}
	barCh chan struct{}
}

func NewFooBar(n int) *FooBar {
	fb := &FooBar {
		n: n,
		fooCh: make(chan struct{}, 1),
		barCh: make(chan struct{}, 1),
	}
	fb.fooCh <- struct{}{}
	return fb
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		<-fb.fooCh
		printFoo()
		fb.barCh <- struct{}{}
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		<-fb.barCh
		printBar()
		fb.fooCh <- struct{}{}
	}
}

func main() {
	n := 3
	fb := NewFooBar(n)
	var wg sync.WaitGroup
	wg.Add(2)

	printFoo := func() {
		fmt.Println("foo")
	}
	printBar := func() {
		fmt.Println("bar")
	}

	go func() {
		defer wg.Done()
		fb.Foo(printFoo)
	}()

	go func() {
		defer wg.Done()
		fb.Bar(printBar)
	}()

	wg.Wait()
	fmt.Println("Done")
}