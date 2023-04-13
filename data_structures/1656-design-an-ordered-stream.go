package main

type OrderedStream struct {
	ptr  int
	list []string
}

func Constructor(n int) OrderedStream {
	return OrderedStream{
		ptr:  1,
		list: make([]string, n+1),
	}
}

func (this *OrderedStream) Insert(idKey int, value string) []string {
	res := make([]string, 0)
	length := len(this.list)
	this.list[idKey] = value
	for ; this.ptr < length; this.ptr++ {
		if len(this.list[this.ptr]) == 0 {
			break
		}
		res = append(res, this.list[this.ptr])
	}
	return res
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Insert(idKey,value);
 */

// Extension question: what if initial capacity n is not given?
type OrderedStream2 struct {
	buffer map[int]string
	ptr    int
}

func Constructor(n int) OrderedStream2 {
	return OrderedStream2{
		ptr:    1,
		buffer: make(map[int]string),
	}
}

func (this *OrderedStream2) Insert(idKey int, value string) []string {
	ans := make([]string, 0)
	this.buffer[idKey] = value
	if idKey == this.ptr {
		for ; ; this.ptr++ {
			if v, ok := this.buffer[this.ptr]; ok {
				ans = append(ans, v)
			} else {
				return ans
			}
		}
	}
	return ans
}
