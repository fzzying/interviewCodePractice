#include<iostream>
#include<string>
using namespace std;

class Solution{
    private:
        string S,T;
    public:
        int numDistinct(string S,string T){
            S.insert(S.begin(),'$');
            T.insert(T.begin(),'$');
            const int sSize = S.size(), tSize = T.size();
            cout<<S<<endl;
            cout<<T<<endl;
            int X[2][tSize];
            for(int i=0;i<2;i++)
               for(int j=0;j<tSize;j++)
                   X[i][j]=0;
            X[0][0]=1;
            for(int i=1;i<sSize;i++){
               int id = i & 1; 
               for(int j=0;j<tSize;j++){
                   if(S[i]==T[j]){
                        X[id][j]=X[1-id][j]+X[1-id][j-1];
                   }else{
                        X[id][j]=X[1-id][j];
                   }
               }
               for(int w=0;w<tSize;w++)
               {
                   cout<<X[id][w]<<"\t";
                   X[1-id][w]=0;
               }
               cout<<endl;
            }
            return X[(sSize-1)&1][tSize-1];
        }
};

int main(int argc,char* argv[]){
    Solution sln;
    cout<<sln.numDistinct(string(argv[1]),string(argv[2]))<<endl;
    return 0;
}
