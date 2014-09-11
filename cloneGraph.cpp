#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct UndirectedGraphNode{
    int label;
    vector<UndirectedGraphNode* > neighbors;
    UndirectedGraphNode(int x):label(x){}
};

class Solution{
    private:
        unordered_map<int, UndirectedGraphNode*> hashTable;
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
            if(node == NULL){
                return NULL;
            }
            if(hashTable[node->label]!=NULL){
                return hashTable[node->label];
            }
            UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
            int size = node->neighbors.size();
            for(int i=0;i<size;i++)
                if(node->neighbors[i]->label >= node->label)
                {
                    UndirectedGraphNode* newCloneNode; 
                    if(node->neighbors[i]->label != node->label)
                    {
                        newCloneNode = cloneGraph(node->neighbors[i]);
                    }
                    else
                    {
                        newCloneNode = cloneNode;
                    }
                    cloneNode->neighbors.push_back(newCloneNode);
                }
            hashTable[node->label]=cloneNode;
            return cloneNode;
        }
        void printGraph(UndirectedGraphNode* root){
            cout<<root->label<<":";
            int size = root->neighbors.size();
            for(int i=0;i<size;i++){
                cout<<root->neighbors[i]->label<<",";
            }
            cout<<endl;
            for(int i=0;i<size;i++){
                if(root->label<root->neighbors[i]->label){
                    printGraph(root->neighbors[i]);
                }
            }
        }
};
int main(int argc,char* argv[]){
    UndirectedGraphNode *p0= new UndirectedGraphNode(0);
    UndirectedGraphNode *p1= new UndirectedGraphNode(1);
    UndirectedGraphNode *p2= new UndirectedGraphNode(2);
    p0->neighbors.push_back(p1);
    p0->neighbors.push_back(p2);
    p1->neighbors.push_back(p2);
    p2->neighbors.push_back(p2);
    Solution sln;
    UndirectedGraphNode *cloneRoot = sln.cloneGraph(p0);
    sln.printGraph(cloneRoot);
    return 0;
}
