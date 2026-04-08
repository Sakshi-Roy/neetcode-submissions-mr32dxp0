class Solution {
public:
    int numDecodings(string s) {
        // recurrent relation :
        // dp[i]=(valid single? dp[i−1])+(valid pair? dp[i−2])

        int n = s.size();
        if(n==0) {return n;}
        int prev2 = 1; //dp[0] : represents an empty string // dp[i-2]
        int prev1 = (s[0]!='0')?1:0; //dp[1] : represents string Le =1 : dp[i-1]
        
        // for allstrings of length > 2
        for(int i= 2; i<=n; i++){
           int curr = 0; // store dp[i] :  no of ways to represent the code up to ith index
           
           // valid single
           if(s[i-1]!='0'){
            curr+=prev1;
           }
          // valid pair

          int twodigit = stoi(s.substr(i-2,2));
          if(twodigit>=10 && twodigit<=26){

            curr+=prev2;
          }
 
          //swap or shift

          prev2 =prev1;
          prev1 = curr; // curr = dp[size(based 0)+1]
    
        }

        return prev1; //dp[n]

    }
};
