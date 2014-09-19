#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
    private:
        TreeNode *last;
    public:
        void flatten(TreeNode *root){
            if(root==NULL) return;
            flatten(root->left);
            if(root->left!=NULL){
                TreeNode* tmpRight = root->right;
                root->right = root->left;
                root->left = NULL;
                TreeNode* tmp = root;
                while(tmp->right!=NULL) tmp=tmp->right; 
                tmp->right = tmpRight;
            }
            flatten(root->right);
        }
};

int main(int argc,char* argv[]){
    TreeNode* rt = new TreeNode(1);
    rt->left = new TreeNode(2);
    rt->right = new TreeNode(5);
    rt->left->left = new TreeNode(3);
    rt->left->right = new TreeNode(4);
    rt->right->right = new TreeNode(6);
    Solution sln;
    sln.flatten(rt);
    cout<<"Finished"<<endl;
    while(rt!=NULL)
    {
        cout<<rt->val<<endl;
        rt = rt->right;
    }
    return 0;
}
