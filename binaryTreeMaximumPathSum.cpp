#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
    private:
        int maxVal;
        int maxSubTree(TreeNode* root){
            if(root==NULL) return 0;
            int leftMax = maxSubTree(root->left);
            int rightMax = maxSubTree(root->right);
            int maxCurrentNode=root->val;
            maxCurrentNode=max(maxCurrentNode,leftMax+root->val);
            maxCurrentNode=max(maxCurrentNode,rightMax+root->val);
            maxVal=max(maxVal,leftMax+rightMax+root->val);
            maxVal=max(maxVal,maxCurrentNode);
            return maxCurrentNode;
        }
    public:
        int maxPathSum(TreeNode *root){
            maxVal=INT_MIN;
            maxSubTree(root);
            return maxVal;
        }
};

int main(int argc,char* argv[]){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sln;
    cout<<sln.maxPathSum(root)<<endl;
    return 0;
}
