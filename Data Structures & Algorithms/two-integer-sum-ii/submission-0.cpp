class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
     // Initialize two pointers: 'left' at the beginning, 'right' at the end.
        int left = 0;
        int right = numbers.size() - 1;

        // Loop as long as the left pointer is before the right pointer.
        // The problem guarantees exactly one solution, so we don't need to worry about
        // not finding a pair.
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];

            if (current_sum == target) {
                // Found the pair! Return their 1-indexed positions.
                return {left + 1, right + 1};
            } else if (current_sum < target) {
                // The sum is too small. To increase the sum, move the left pointer
                // to a larger number.
                left++;
            } else { // current_sum > target
                // The sum is too large. To decrease the sum, move the right pointer
                // to a smaller number.
                right--;
            }
        }

        // This line should technically not be reached because the problem guarantees
        // that there will always be exactly one valid solution.
        return {}; // Return an empty vector in case (for compilation, though not expected)
    }
};
