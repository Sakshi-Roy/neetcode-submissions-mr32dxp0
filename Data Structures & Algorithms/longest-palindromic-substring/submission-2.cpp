class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0;       // starting index of best palindrome
        int maxLen = 1;      // length of best palindrome

        // iterate over each character as center
        for (int center = 0; center < n; center++) {

            // --- Odd length palindromes ---
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }

            // --- Even length palindromes ---
            left = center, right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
