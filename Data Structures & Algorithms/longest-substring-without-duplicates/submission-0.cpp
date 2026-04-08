class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
       int n = s.length();
        if (n == 0) {
            return 0; // An empty string has a longest substring of length 0.
        }

        // 'char_set' will store the characters in the current sliding window.
        // Using an unordered_set provides O(1) average time complexity for
        // insertion, deletion, and lookup (checking for duplicates).
        std::unordered_set<char> char_set;

        int left = 0; // The left pointer of the sliding window
        int max_length = 0; // Stores the maximum length found so far

        // The 'right' pointer iterates through the string, expanding the window.
        for (int right = 0; right < n; ++right) {
            char current_char = s[right];

            // If the current character is already in the set, it means we have a duplicate.
            // We need to shrink the window from the 'left' until the duplicate is removed.
            while (char_set.count(current_char)) {
                char_set.erase(s[left]); // Remove the character at the left pointer
                left++;                   // Move the left pointer to the right
            }

            // Once the window is valid (no duplicates), add the current character to the set.
            char_set.insert(current_char);

            // Update the maximum length found.
            // The current window length is (right - left + 1).
            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;

    }
};
