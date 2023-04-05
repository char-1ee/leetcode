package main

func wordPattern(pattern string, s string) bool {
    words := strings.Split(s, " ")
    if len(words) != len(pattern) {
        return false
    }
    
    m := make(map[string]byte)
    used := make([]bool, 26)
    for i, word := range words {
        c, ok := m[word]
        if !ok {
            if used[pattern[i] - 'a'] {
                return false
            }
            m[word] = pattern[i]
            used[pattern[i] - 'a'] = true
        } else {
            if c != pattern[i] {
                return false
            }
        }        
    }
    return true
}