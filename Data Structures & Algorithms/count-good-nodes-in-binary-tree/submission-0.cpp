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
    int countNode(TreeNode* node,int ans,int currMax){
        if(node==nullptr){
            return 0;
        }

        int rootAns = 0;
        if(node->val >= currMax){
            rootAns = 1;
            currMax = node->val;
        }

        int lAns = countNode(node->left,ans,currMax);
        int rAns = countNode(node->right,ans,currMax);

        return lAns+rAns+rootAns;
    }
    int goodNodes(TreeNode* root) {
        return countNode(root,0,INT_MIN);
    }
};
