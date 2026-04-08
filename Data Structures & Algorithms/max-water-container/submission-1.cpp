class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n  = heights.size();
        int left = 0, right = n-1;
        int maxwater = 0;

        while(left<right){

          int height = min(heights[left], heights[right]);
          int width = right-left;

          maxwater = max(maxwater, (height*width));

          if(heights[left]<heights[right]){
            left++;
          }
          else right--;
          
        }

        return maxwater;

    }
};
