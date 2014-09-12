#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int minCut(string s){
            string str;                    
            int size = s.length();
            vector<int>  minCut;
            for(int i=0;i<size;i++) {
                minCut.push_back(i);
            }
            str.push_back('^');
            for(int i=0;i<size-1;i++){
                str.push_back(s[i]);
                str.push_back('*');
            }
            str.push_back(s[size-1]);
            str.push_back('$');
            int mx = 0, id = 0, len = str.length();
            vector<int> p;
            p.push_back(0);
            for(int i=1;i<len;i++){
                int rd = 1; 
                if(mx>i){
                    rd=min(p[2*id-i],mx-i);
                }
                while(str[i+rd]==str[i-rd]){
                    rd++; 
                }
                if(mx<rd+i){
                    mx = rd+i; 
                    id = i;
                }
                p.push_back(rd);
            }
            cout<<"Start Dynamic Projecting..."<<endl;
            for(int j=0;j<size;j++){
                   int len = (j+1);
                   int px = 2*(j/2+!(len&1))+(len&1);
                   if(p[px]>=len){
                        minCut[j]=0;
                   }else{
                       for(int i=0;i<j;i++)
                       {
                           len = (j-i);
                           px = 2*((i+j+1)/2+!(len&1))+(len&1);
                           if(p[px]>=len){
                               minCut[j]=min(minCut[j],1+minCut[i]); 
                           }
                       }
                   }
            }
            return minCut[size-1];
        }
        void printOut(vector<vector<int> > ans,int size){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    cout<<i<<","<<j<<"="<<ans[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
};

int main(int argc,char* argv[]){
    Solution sln;
    cout<<sln.minCut(argv[1])<<endl;
    return 0;
}
