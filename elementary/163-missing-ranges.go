package main

import "fmt"

func findMissingRanges(nums []int, lower int, upper int) []string {
    var res []string
    var s string
    j := lower
    for _, num := range nums {
        if num > j {
            if num - 1 == j {
                s = fmt.Sprintf("%d", j);
            } else {
                s = fmt.Sprintf("%d->%d", j, num - 1);
            }
            res = append(res, s)
        }

        if num == upper {
            return res
        }
        j = num + 1
    }
    if j <= upper {
        if j == upper {
            s = fmt.Sprintf("%d", upper);
        } else {
            s = fmt.Sprintf("%d->%d", j, upper);
        }
        res = append(res, s);
    }
    return res
}