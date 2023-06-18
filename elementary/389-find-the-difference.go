package main

func findTheDifference(s string, t string) byte {
    m := make([]int, 26)
    for _, c := range s {
        m[c - 'a']++
    }
    for _, c := range t {
        m[c - 'a']--
        if m[c - 'a'] < 0 {
            return byte(c)
        }
    }
    return 'a'
}

func findTheDifference_solution1(s string, t string) byte {
    var res byte = 0
    for _, c := range s {
        res -= byte(c)
    }
    for _, c := range t {
        res += byte(c)
    }
    return res
}