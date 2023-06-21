type StringIterator struct {
	s        string
	currIdx  int
	currChar byte
	currCnt  int
}

func Constructor(compressedString string) StringIterator {
	return StringIterator{
		s:        compressedString,
		currIdx:  0,
		currChar: ' ',
		currCnt:  0,
	}
}

func (this *StringIterator) Next() byte {
	if !this.HasNext() {
		return ' '
	}
	if this.currCnt > 0 {
		this.currCnt -= 1
		return this.currChar
	} else {
		var i int
		var cnt string
		this.currChar = (this.s)[this.currIdx]
		for i = this.currIdx + 1; i < len(this.s) && (this.s)[i] >= '0' && (this.s)[i] <= '9'; i++ {
			cnt += string((this.s)[i])
		}
		this.currCnt, _ = strconv.Atoi(cnt)
		this.currCnt -= 1
		this.currIdx = i
		return this.currChar
	}

}

func (this *StringIterator) HasNext() bool {
	return this.currCnt > 0 || this.currIdx < len(this.s)
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * obj := Constructor(compressedString);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */