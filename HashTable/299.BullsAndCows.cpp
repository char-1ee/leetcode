class Solution {
public:
    /** Two passes */
    string getHint(string secret, string guess) {
        int A = 0, B = 0, size = secret.size();
        int map[58] = {0}; // or map[256]
        for (int i = 0; i < size; ++i) {
            if (secret[i] == guess[i]) ++A;
            else ++map[secret[i]];
        }
        for (int j = 0; j < size; ++j) {
            if (secret[j] != guess[j] && map[guess[j]]) { // in case {"11","10"} where there is duplicate in most front
                ++B;
                --map[guess[j]];
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }

    /** One pass */
    string getHint2(string secret, string guess) {
        int m[256] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++ cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};