class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0, maxlen = 0 , maxfreq = 0;

        for(int right = 0; right<s.size(); right++){
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq , freq[s[right]-'A']);

            // check if no. of replacements in a window are
            // not more than k

            while((right-left+1)-maxfreq > k){

                    freq[s[left]-'A']--;
                    left++;
            }

            maxlen = max(maxlen, (right-left+1));
        }

        return maxlen;
        
    }
};
