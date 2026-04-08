class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        int n = height.size();
        // left_max[i] will store the maximum height to the left of index i (including height[i])
        std::vector<int> left_max(n);
        // right_max[i] will store the maximum height to the right of index i (including height[i])
        std::vector<int> right_max(n);

        // Step 1: Populate the left_max array
        // The first element's left_max is itself
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = std::max(height[i], left_max[i - 1]);
        }

        // Step 2: Populate the right_max array
        // The last element's right_max is itself
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = std::max(height[i], right_max[i + 1]);
        }

        // Step 3: Calculate the total trapped water
        // For each bar i, the amount of water trapped above it is
        // min(left_max[i], right_max[i]) - height[i].
        // We sum this value for all bars.
        int total_trapped_water = 0;
        for (int i = 0; i < n; ++i) {
            total_trapped_water += std::min(left_max[i], right_max[i]) - height[i];
        }

        return total_trapped_water;
    }
};
