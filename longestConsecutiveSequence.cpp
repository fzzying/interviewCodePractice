#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        int longestConsecutive(vector<int> &num){
            int size = num.size();
            int longest=1;
            unordered_map<int,int> hash;
            for(int i=0;i<size;i++){
                if(hash.find(num[i])!=hash.end()) continue;
                int upper=num[i],lower=num[i];
                if(hash.find(num[i]-1)!=hash.end())
                    lower = hash[num[i]-1];
                if(hash.find(num[i]+1)!=hash.end())
                    upper = hash[num[i]+1];
                hash[num[i]] = num[i];
                hash[lower]=upper;
                hash[upper]=lower;
                longest=max(longest,upper-lower+1);
            }
            return longest;
        }
};

int main(int argc,char* argv[]){
    vector<int> num;
    num.push_back(100);
    num.push_back(4);
    num.push_back(200);
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    Solution sln;
    cout<<sln.longestConsecutive(num)<<endl;
    return 0;
}
