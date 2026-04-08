class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> numset(nums.begin(), nums.end());
       int longest_sequence = 0;
        for(int num : nums){
          
          if(numset.count(num-1) == 0){
            int current_num = num;
            int current_num_length = 1;

          

          while(numset.count(current_num + 1)){
              current_num++;
              current_num_length++;
          }

           longest_sequence = max(current_num_length, longest_sequence);
        }
        }
       return longest_sequence;
    }
};
