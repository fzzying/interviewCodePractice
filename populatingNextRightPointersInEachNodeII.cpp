#include<iostream>
#include<vector>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
    public:
        void connect(TreeLinkNode* root){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL) return;
            TreeLinkNode* head = root;
            while(head!=NULL){
                TreeLinkNode *LastNode,*nextNode=head->next;
                if(head->left!=NULL){
                    if(head->right!=NULL){
                        head->left->next=head->right; 
                        LastNode=head->right;
                    }else{
                        LastNode=head->left; 
                    }
                    head=head->left;
                }else{
                    LastNode=head->right; 
                    head=head->right;
                }
                while(nextNode!=NULL){
                    if(nextNode->left!=NULL){
                        LastNode->next=nextNode->left; 
                        if(nextNode->right!=NULL){
                            nextNode->left->next=nextNode->right; 
                            LastNode = nextNode->right;
                        }else{
                            LastNode = nextNode->left; 
                        }
                    }else
                    if(LastNode!=NULL)
                    {
                        LastNode->next=nextNode->right; 
                        LastNode=nextNode->right;
                    }
                    nextNode=nextNode->next; 
                }
            }
        }
};

int main(int argc,char* argv[])
{
    return 0;
}
