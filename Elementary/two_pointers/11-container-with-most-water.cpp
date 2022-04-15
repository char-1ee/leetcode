class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), m = 0;
        for (int i = 0, j = n - 1; i < j;) {
            m = max(m, (j - i) * min(height[j], height[i]));
            height[i] < height[j] ? i++ : j--;
        }
        return m;
    }

    // a little bit optimization
    int maxArea2(vector<int>& height) {
        int n = height.size(), m = 0;
        for (int i = 0, j = n - 1; i < j;) {\
            int h = min(height[j], height[i]);
            m = max(m, (j - i) * h);
            while (i < j && height[i] == h) i++;
            while (i < j && height[j] == h) j--;
        }
        return m;
    }
};