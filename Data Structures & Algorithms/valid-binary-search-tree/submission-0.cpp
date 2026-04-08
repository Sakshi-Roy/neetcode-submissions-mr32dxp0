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
    
    bool isValidBST(TreeNode* node, long long lowerBound, long long upperBound) {
        if (node == nullptr) {
            return true; // An empty tree is a valid BST
        }

        // Check if the current node's value is within the valid range
        if (node->val <= lowerBound || node->val >= upperBound) {
            return false;
        }

        // Recursively check the left subtree:
        // The left child's value must be > lowerBound and < current_node.val
        bool isLeftBST = isValidBST(node->left, lowerBound, node->val);

        // Recursively check the right subtree:
        // The right child's value must be > current_node.val and < upperBound
        bool isRightBST = isValidBST(node->right, node->val, upperBound);

        return isLeftBST && isRightBST;
    }

    // Main function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Start the validation from the root with an effectively infinite range
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
