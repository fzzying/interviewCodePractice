#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        s1.insert(s1.begin(),'$');
        s2.insert(s2.begin(),'$');
        s3.insert(s3.begin(),'$');
        int size1 = s1.length();
        int size2 = s2.length();
        int size3 = s3.length();
        if(size1+size2-2!=size3-1) return false;
        bool X[2][size2];
        for(int i=0;i<size2;i++){
            X[0][i]=true;
            X[1][i]=false;
        }
        X[1][0]=true;
        int id = 1;
        for(int i=1;i<size3;i++){
            int size = min(size2,i+1);
            for(int j=1;j<size;j++){
                  X[id][j] = (X[1-id][j] && s3[i]==s1[i-j]) || (X[1-id][j-1] && s3[i]==s2[j]);
            }
            id = id ^ 1;
        }
        return X[1-id][size2-1];
    }
};

int main(int argc,char* argv[]){
    Solution sln;  
    cout<<sln.isInterleave("aa", "ab", "aaba")<<endl<<"ANS"<<endl;
    return 0;
}
