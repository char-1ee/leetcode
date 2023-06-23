func shiftingLetters(s string, shifts []int) string {
	ss, sum := []byte(s), 0
	for i := len(s) - 1; i >= 0; i-- {
		sum += shifts[i]
		ss[i] = byte('a' + (int(ss[i])-'a'+sum)%26)
	}
	return string(ss)
}