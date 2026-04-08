class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
     int n = nums.size();
        std::vector<int> output(n); // Initialize output array with size n

        // Step 1: Calculate left products and store them in the output array.
        // For output[i], this will store the product of all elements to the left of nums[i].
        // output[0] should be 1 (as there are no elements to its left).
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = left_product;
            left_product *= nums[i];
        }
        // At the end of this loop, output will look like:
        // [1, nums[0], nums[0]*nums[1], nums[0]*nums[1]*nums[2], ...]

        // Step 2: Calculate right products and multiply with left products in the output array.
        // 'right_product' will accumulate the product of elements to the right.
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            // output[i] currently holds the product of elements to its left.
            // Multiply it by the product of elements to its right.
            output[i] *= right_product;
            // Update right_product for the next iteration (moving left).
            right_product *= nums[i];
        }
        // After this loop, output[i] will be (product of left) * (product of right)

        return output;
    }
};
