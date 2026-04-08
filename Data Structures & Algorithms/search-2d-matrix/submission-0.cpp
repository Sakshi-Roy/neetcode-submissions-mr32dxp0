class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // Get dimensions of the matrix
        int m = matrix.size();
        if (m == 0) { // Handle empty matrix case
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) { // Handle matrix with empty rows
            return false;
        }

        // Initialize binary search pointers for the conceptual 1D array
        int low = 0;
        int high = (m * n) - 1; // Total number of elements - 1

        // Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Convert the 1D 'mid' index to 2D (row, col) coordinates
            // row = mid / num_columns
            // col = mid % num_columns
            int row = mid / n;
            int col = mid % n;

            int current_value = matrix[row][col];

            if (current_value == target) {
                return true; // Target found
            } else if (current_value < target) {
                low = mid + 1; // Target is in the right half
            } else { // current_value > target
                high = mid - 1; // Target is in the left half
            }
        }

        // Target not found after search
        return false;
    }
};
