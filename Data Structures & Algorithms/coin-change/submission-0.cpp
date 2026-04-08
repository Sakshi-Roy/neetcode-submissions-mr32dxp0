class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // recurrence relation :
        // dp[x] = min |dp[x-c] +1| where x is the amount, 
        // c is element of coins and x-c>=0
       const int INF = 1e9;
        vector<int> dp(amount+1, INF);
        // define a base case
        dp[0] = 0; // no coins needed to express amnt =0;

        for(int x = 1; x<=amount; x++){
            for(int c : coins){
                if(x-c>=0){
                    dp[x] = min(dp[x], dp[x-c]+1);
                }

            }

        }

        return (dp[amount]==INF)?-1:dp[amount];
    }
};
