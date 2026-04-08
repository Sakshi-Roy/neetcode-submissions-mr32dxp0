class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        
        // If the string is empty, no replacement can be made, and length is 0.
        if (n == 0) {
            return 0;
        }

        // 'char_counts' stores the frequency of each uppercase English character (A-Z)
        // within the current sliding window.
        // Index 0 for 'A', 1 for 'B', ..., 25 for 'Z'.
        std::vector<int> char_counts(26, 0);

        int left = 0;           // Left pointer of the sliding window
        int max_length = 0;     // Stores the maximum length of a valid substring found so far
        int max_freq = 0;       // Stores the maximum frequency of any single character
                                // within the current valid sliding window.
                                // This max_freq only grows, it doesn't need to decrease
                                // when the window shrinks from the left.

        // The 'right' pointer expands the window by iterating through the string.
        for (int right = 0; right < n; ++right) {
            // Increment the count of the character at the 'right' pointer.
            char_counts[s[right] - 'A']++;

            // Update max_freq: This is the frequency of the most occurring character
            // in the current window (or potentially a character from a previous larger window).
            // This 'max_freq' helps determine how many characters need to be replaced.
            max_freq = std::max(max_freq, char_counts[s[right] - 'A']);

            // Calculate the current window length.
            int current_window_length = right - left + 1;

            // Check the window validity:
            // If (current_window_length - max_freq) > k, it means that to make
            // all characters in the current window the same as the 'max_freq' character,
            // we would need more than 'k' replacements. This window is invalid.
            if (current_window_length - max_freq > k) {
                // To make the window valid, we must shrink it from the 'left'.
                // Decrement the count of the character at the 'left' pointer.
                char_counts[s[left] - 'A']--;
                left++; // Move the left pointer forward
            }

            // After potentially shrinking the window (if it was invalid), the current
            // window [left, right] is now a valid candidate.
            // Update max_length with the maximum length found so far.
            // Note: max_length is always updated with (right - left + 1) because even if
            // the window shrunk, 'max_length' will still capture the largest window
            // that *was* valid up to this point.
            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;
    }
};
