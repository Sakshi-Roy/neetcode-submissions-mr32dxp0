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
     int goodnodes =0;
   
   void dfs(TreeNode* node, int maxval){
     
     if(node == nullptr){
        return ;
     }

     if(node->val >= maxval){
        goodnodes++;
        maxval = node->val;
     }

        dfs(node->left, maxval);
        dfs(node->right, maxval);

   

   }
   
    int goodNodes(TreeNode* root) {
        
        goodnodes= 0;
        if(root==nullptr){
            return 0;
        }

        dfs(root, root->val);
        return goodnodes;
    }
};
