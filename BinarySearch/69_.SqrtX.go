/* sqrt(x int, esp float64) float64: return sqrt root of int x in certian estimation */
func mSqrt(x int, esp float64) float64 {
	var left, right float64 = 0, x
	for right - left > esp {
		mid := left + (right - left) / 2.0
		if mid * mid < x {
			left = mid
		} else {
			right = mid
		}
	}
	return left + (right - left) / 2.0
}