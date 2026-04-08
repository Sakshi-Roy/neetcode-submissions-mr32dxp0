class Solution {
public:
    int maxProfit(vector<int>& prices) {
        	int profit = 0;
            int n = prices.size();
            int minprice = INT_MAX;
            int pot_profit = 0;
            int maxprofit = 0;
            for(int i =0; i<n; i++){

                minprice = min(minprice, prices[i]);
                

                    pot_profit = prices[i]-minprice;
                

                maxprofit = max(maxprofit, pot_profit);

            }
       return maxprofit;
    }
};
