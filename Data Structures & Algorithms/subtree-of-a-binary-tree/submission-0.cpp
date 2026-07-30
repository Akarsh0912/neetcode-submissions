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
    string preOrder(TreeNode* node){
        if(node == nullptr){
            return "null";
        }
        string str = "";
        str = str + to_string(node->val);
        str = str + preOrder(node->left);
        str = str + preOrder(node->right);
        return str;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if(root == nullptr){
                return false;
            }
            
            string rootStr = preOrder(root);
            cout<<"root sub "<<rootStr<<endl;

            string subRootStr = preOrder(subRoot);
            cout<<"sub str "<<subRootStr << endl;
            if(rootStr.contains(subRootStr)){
                return true;
            }
            else{
                return false;
            }
    }
};
