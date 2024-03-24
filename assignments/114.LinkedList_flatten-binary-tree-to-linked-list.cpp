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


//  The function flatten(TreeNode* root) takes the root of the binary tree as its argument.

// It initializes a pointer cur to the root of the tree.

// It enters a while loop that continues until cur is not NULL. This loop is responsible for flattening the tree.

// Inside the loop:

// It checks if the current node cur has a left child (cur->left != NULL). If it does, it means there's a subtree rooted at cur->left that needs to be attached to the right side of the current node.
// It initializes a pointer prev to the left child of cur. This pointer will be used to find the rightmost node of the subtree rooted at cur->left.
// It enters another while loop that traverses to the rightmost node of the subtree rooted at cur->left.
// It attaches the right subtree of cur to the rightmost node found in the previous step (prev->right = cur->right).
// It attaches the left subtree of cur to the right of cur (cur->right = cur->left).
// After attaching the left subtree, it sets cur->left to NULL to maintain the flattened structure.
// Finally, it updates cur to its right child to continue the process for the next node in the tree.


class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode * cur= root;
        TreeNode * prev;

        while(cur!=NULL){
            if(cur->left!=NULL){
                prev = cur->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left = NULL;
            }
            cur=cur->right;
        }

    }
};