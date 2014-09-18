#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<vector<int> > generate(int numRows){
            if(numRows == 0) return vector<vector<int> >{};
            if(numRows == 1) return vector<vector<int> >{vector<int>{1}};
            if(numRows == 2) return vector<vector<int> >{vector<int>{1},vector<int>{1,1}};
            vector<vector<int> > triangle{vector<int>{1}, vector<int>{1,1}};
            for(int i=2;i<numRows;i++){
                vector<int> row;
                row.push_back(1);
                for(int j=1;j<i;j++)
                    row.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
                row.push_back(1);
                triangle.push_back(row);
            }
            return triangle;
        }
};

int main(int argc,char* argv[]){

    return 0;
}
