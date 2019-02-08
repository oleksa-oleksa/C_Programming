/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 Example:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rangeSumBST(struct TreeNode* root, int L, int R){
    
    int sum = 0;
    int sumLeft = 0;
    int sumRight = 0;
    
    if (root == NULL) {
        return 0;
    }
        
    // Value is greather than L and R, go left
    if (root->val > L && root->val > R) {
        sum += rangeSumBST(root->left, L, R);
    } 
    
    // Value is smaller than L and R, go right
    if (root->val < L && root->val < R) {
        sum += rangeSumBST(root->right, L, R);
    } 
        
    // Value is between L and R
    if (root->val >= L && root->val <= R) {
        sumLeft = rangeSumBST(root->left, L, R);
        sumRight = rangeSumBST(root->right, L, R);
        sum = root->val + sumLeft + sumRight;
    }
    
    return sum;
}

