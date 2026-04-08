class Solution {
public:
 
    int robLinear(vector<int>& nums, int start, int end){ 

       int prev =0;
       int prev2 =0;
      
       for ( int i =start; i<=end; i++){
         int curr = max(prev, prev2 + nums[i]);
         prev2 =prev;
         prev = curr;

       }
       return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){return 0;}
        if(n == 1){return nums[0];}
        if (n == 2) return max(nums[0], nums[1]);

        // ignoring the last house
        // range 0 to n-2

       int case1 = robLinear(nums, 0, n-2);

       // ignoring the first house
       // range 1 to n-1

       int case2 = robLinear(nums, 1, n-1);
       return max(case1, case2);

    }
};
