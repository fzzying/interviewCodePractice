#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    TreeNode *head; 
    vector<TreeNode *> ans;
    int num,tot;
    void generateTrees(TreeNode *&root,int i,int j){
        if(i>j) return;
        for(int k=i;k<=j;k++){
            TreeNode *root = new TreeNode(k);                
            num++;
            if(num==tot){
                ans.push_back(head);
            }
            else{
                generateTrees(root->left,i,k-1);   
                generateTrees(root->right,k+1,j);  
                num--;
                delete root;
            }
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        if(n==0) {
            ans.push_back(NULL);
            return ans;
        }
        if(n==1) {
            ans.push_back(new TreeNode(1));
            return ans;
        }
        tot = n;
        for(int i=1;i<=n;i++){
            TreeNode *root = new TreeNode(i);   
            head=root;
            num = 1;
            generateTrees(root->left,1,i-1);   
            generateTrees(root->right,i+1,n);   
            delete root;
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    Solution sln;
    sln.generateTrees(5);
    return 0;
}
