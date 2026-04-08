class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
      int n = nums.size();

        // Step 1: Sort the array. This is crucial for two reasons:
        // 1. It allows us to use the two-pointer approach efficiently.
        // 2. It makes it easy to skip duplicate elements to avoid duplicate triplets.
        std::sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array to fix the first number (nums[i]).
        // The loop goes up to n - 2 because we need at least two more numbers (j and k)
        // after nums[i].
        for (int i = 0; i < n - 2; ++i) {
            // Optimization 1: If the current number is positive, then sum of three positive numbers
            // cannot be zero. Since the array is sorted, we can break early.
            if (nums[i] > 0) {
                break;
            }

            // Optimization 2: Skip duplicate elements for 'nums[i]'.
            // If the current number is the same as the previous one, we've already
            // considered triplets starting with that value, so skip it to avoid
            // duplicate triplets in the result.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Use the two-pointer approach for the remaining two numbers.
            // 'left' starts right after 'i', and 'right' starts at the end of the array.
            int left = i + 1;
            int right = n - 1;
            int target_sum = -nums[i]; // We need nums[left] + nums[right] to equal -nums[i]

            while (left < right) {
                int current_sum = nums[left] + nums[right];

                if (current_sum == target_sum) {
                    // Found a triplet that sums to zero!
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Step 4: Skip duplicate elements for 'nums[left]' and 'nums[right]'.
                    // Increment 'left' while it's less than 'right' and the current
                    // element is the same as the next one, to avoid duplicate triplets.
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Decrement 'right' while it's less than 'right' and the current
                    // element is the same as the previous one, to avoid duplicate triplets.
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inwards to look for the next unique pair.
                    left++;
                    right--;
                } else if (current_sum < target_sum) {
                    // The sum is too small, need a larger sum. Move 'left' pointer to the right.
                    left++;
                } else { // current_sum > target_sum
                    // The sum is too large, need a smaller sum. Move 'right' pointer to the left.
                    right--;
                }
            }
        }

        return result;
    }
};
