#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
    public:
        int minimumTotal(vector<vector<int> > &triangle){
            int nSize = triangle.size();
            if(nSize<1) return 0;
            if(nSize<2) return triangle[0][0];
            for(int i=1;i<nSize-1;i++){
                int mSize = triangle[i].size();
                triangle[i][0]=triangle[i-1][0]+triangle[i][0];
                triangle[i][mSize-1]=triangle[i-1][mSize-2]+triangle[i][mSize-1];
                for(int j=1;j<mSize-1;j++){
                    if(triangle[i-1][j-1]<triangle[i-1][j]){
                        triangle[i][j]=triangle[i-1][j-1]+triangle[i][j];
                    }
                    else{
                        triangle[i][j]=triangle[i-1][j]+triangle[i][j];
                    }
                }
            }
            int mSize = triangle[nSize-1].size(), minVal, i = nSize-1;
            triangle[i][0]=triangle[i-1][0]+triangle[i][0];
            triangle[i][mSize-1]=triangle[i-1][mSize-2]+triangle[i][mSize-1];
            minVal=min(triangle[i][0],triangle[i][mSize-1]);
            for(int j=1;j<mSize-1;j++){
                minVal=min(minVal,min(triangle[i][j]+triangle[i-1][j-1],triangle[i][j]+triangle[i-1][j]));
            }
            return minVal;
        }
};

int main(int argc,char* argv[]){
    Solution sln;
    vector<vector<int> > inputs;
//    inputs.push_back(vector<int>{2});
//    inputs.push_back(vector<int>{3,4});
//    inputs.push_back(vector<int>{6,5,7});
//    inputs.push_back(vector<int>{4,1,8,3});
    inputs.push_back(vector<int>{-1});
    inputs.push_back(vector<int>{2,3});
    inputs.push_back(vector<int>{1,-1,-3});

    cout<<sln.minimumTotal(inputs)<<endl;
    return 0;
}
