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

    int result = -1;
    int count =0;
   
    void inorder(TreeNode* root, int k){
     
     if(root == nullptr  || result!=-1){
        return ;
     }

     // traverse the left subtree
     inorder(root->left, k);

     // process the root
     count++;
     if(count == k){
        result = root->val;
     }
     
     // traverse the right subtree

     inorder(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        
        count = 0; result = -1;
        inorder(root, k);

        return result;
    }
};
