package elementary.palindrome;

class Solution {
    public boolean isValidPalindrome(String s, int k) {
            int memo[][] = new int[s.length()][s.length()];
    
            // Generate all combinations of `i` and `j` in the correct order.
            for (int i = s.length() - 2; i >= 0; i--)
                for (int j = i + 1; j < s.length(); j++) {
                    // Case 1: Character at `i` equals character at `j`
                    if (s.charAt(i) == s.charAt(j))
                        memo[i][j] = memo[i + 1][j - 1];
    
                    // Case 2: Character at `i` does not equal character at `j`.
                    // Either delete character at `i` or delete character at `j`
                    // and try to match the two pointers using recursion.
                    // We need to take the minimum of the two results and add 1
                    // representing the cost of deletion.
                    else
                        memo[i][j] = 1 + Math.min(memo[i + 1][j], memo[i][j - 1]);
                }
    
            // Return true if the minimum cost to create a palindrome by only deleting the letters
            // is less than or equal to `k`.
            return memo[0][s.length() - 1] <= k;
        }
    };
