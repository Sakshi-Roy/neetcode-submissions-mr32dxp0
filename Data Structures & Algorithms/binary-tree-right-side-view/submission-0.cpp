/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int> result;

       if(root == nullptr){
        return result;
       }
       
       queue<TreeNode*> q;
       q.push(root);
      while(!q.empty()){
        
       int size = q.size();

       TreeNode* lastnode = nullptr;

       for(int i =0; i<size; ++i){

          lastnode = q.front(); q.pop();

          if(lastnode->left){
            q.push(lastnode->left);
          }

          if(lastnode->right){
            q.push(lastnode->right);
          }    
       }
       result.push_back(lastnode->val);
      }
        return result; 


    }
};
