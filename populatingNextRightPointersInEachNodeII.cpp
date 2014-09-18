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
            TreeLinkNode* head = root;
            while(head!=NULL){
                TreeLinkNode *LastNode=NULL, *nextNode=head;
                while(nextNode!=NULL&&nextNode->left==NULL&&nextNode->right==NULL){
                    nextNode=nextNode->next; 
                }
                if(nextNode==NULL){
                    head=NULL;   
                }else{
                    head=nextNode->left!=NULL?nextNode->left:nextNode->right; 
                    while(nextNode!=NULL){
                        if(nextNode->left!=NULL||nextNode->right!=NULL){
                            if(nextNode->left!=NULL&&nextNode->right!=NULL){
                                nextNode->left->next=nextNode->right;
                                if(LastNode!=NULL) {
                                    LastNode->next=nextNode->left;
                                }
                                LastNode=nextNode->right; 
                            }
                            if(nextNode->left==NULL&&nextNode->right!=NULL){
                                if(LastNode!=NULL) {
                                    LastNode->next=nextNode->right;
                                }
                                LastNode=nextNode->right; 
                            }
                            if(nextNode->left!=NULL&&nextNode->right==NULL){
                                if(LastNode!=NULL) {
                                    LastNode->next=nextNode->left;
                                }
                                LastNode=nextNode->left; 
                            }
                        }
                        nextNode=nextNode->next;
                    }
                }
            }
        }
};

int main(int argc,char* argv[])
{
    return 0;
}
