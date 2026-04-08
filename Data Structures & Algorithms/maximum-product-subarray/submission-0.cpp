class Solution {
public:
     int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int tempPrevMax = prevMax; // store old value before updating

            prevMax = max({curr, tempPrevMax * curr, prevMin * curr});
            prevMin = min({curr, tempPrevMax * curr, prevMin * curr});

            ans = max(ans, prevMax);
        }

        return ans;
    }
};
