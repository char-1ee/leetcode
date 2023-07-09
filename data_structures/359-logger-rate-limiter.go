type Logger struct {
	mp map[string]int
}

func Constructor() Logger {
	return Logger{
		mp: make(map[string]int),
	}
}

func (this *Logger) ShouldPrintMessage(timestamp int, message string) bool {
	if t, ok := this.mp[message]; ok && timestamp-t < 10 {
		return false
	}
	this.mp[message] = timestamp
	return true
}

/**
 * Your Logger object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.ShouldPrintMessage(timestamp,message);
 */