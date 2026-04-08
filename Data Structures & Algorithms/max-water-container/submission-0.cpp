class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0; int right = heights.size()-1;

        int result = 0;

        while(left<right){
        
          int current_width = right - left;

          int current_height = min(heights[right], heights[left]);
          
          int current_area = current_width*current_height;

          result = max(result, current_area);

          if(heights[left] < heights[right]){

            left++;
          }
else {
right--;
}
          
  

        }

        return result;
    }
};
