class Solution {
public:

    bool ismatching(std::vector<int>& arr1, std::vector<int>& arr2) {
       for (int i = 0; i < 26; ++i) {
            if (arr1[i] != arr2[i]) {
                return false; // If any count doesn't match, return false immediately.
            }
       }
       return true; // If the loop completes, all counts matched.
    }

    bool checkInclusion(std::string s1, std::string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        // Edge case: If s1 is longer than s2, s2 cannot contain a permutation of s1.
        if (len1 > len2) {
            return false;
        }

        // s1count: Stores frequencies of characters in s1 (constant).
        // s2count: Stores frequencies of characters in the current sliding window of s2.
        std::vector<int> s1count(26, 0);
        std::vector<int> s2count(26, 0);

        // Step 1: Populate counts for s1 and the initial window of s2 (first len1 characters).
        for (int i = 0; i < len1; ++i) {
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        // Step 2: Check if the initial window is a permutation.
        if (ismatching(s1count, s2count)) {
            return true;
        }

        // Step 3: Slide the window across s2.
        // 'right' pointer iterates from len1 up to len2-1.
        // 'left' pointer (implicit, at 'right - len1') points to the character leaving the window.
        for (int right = len1; right < len2; ++right) {
            // Add the new character (at 'right') to the window's counts.
            s2count[s2[right] - 'a']++;
            
            // Remove the character (at 'right - len1') from the window's counts.
            s2count[s2[right - len1] - 'a']--;

            // After each slide, check if the current window's counts match s1's counts.
            if (ismatching(s1count, s2count)) {
                return true; // Found a permutation!
            }
        }

        // If the loop completes and no permutation was found, return false.
        return false;
    }
};
