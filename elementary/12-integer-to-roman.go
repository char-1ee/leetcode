package main

import "strings"

// hardcode
func intToRoman1(num int) string {
    var (
        ones = [...]string {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
        tens = [...]string {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
        hundreds = [...]string {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
        thousands = [...]string {"", "M", "MM", "MMM"}
    )
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10]   
}

// greedy
func intToRoman(num int) string {
    var (
        sb strings.Builder
        vals = [...]int {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
        syms = [...]string {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
    )
    
    for i := 0; i < len(vals); i++ {
        for num >= vals[i] {
            num -= vals[i]
            sb.WriteString(syms[i])
        }
    }
    return sb.String()
}