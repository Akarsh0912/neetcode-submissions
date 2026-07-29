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
    bool isCheck(TreeNode* root1,TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if(root1 != nullptr && root2 == NULL){
            return false;
        }
        if(root1 == nullptr && root2 != nullptr){
            return false;
        }
        if(root1 -> val != root2->val){
            return false;
        }

        bool left = isCheck(root1->left,root2->left);
        bool right = isCheck(root1->right,root2->right);
        bool answer = (left && right);
        return answer;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isCheck(p,q);
    }
};
