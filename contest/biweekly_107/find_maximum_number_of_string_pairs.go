func maximumNumberOfStringPairs(words []string) int {
	res := 0
	st := make(map[string]struct{})
	for _, word := range words {
		if _, ok := st[word]; ok {
			res += 1
		} else {
			s := string([]byte{word[1], word[0]})
			st[s] = struct{}{}
		}
	}
	return res
}