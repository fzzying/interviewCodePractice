#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rows = matrix.size();
        int largestArea = INT_MIN;
        if(rows<=0) return 0;
        int columns = matrix[0].size();
        int h[columns];
        memset(h,0,sizeof(int)*columns);
        for(int i=0;i<rows;i++)
        {
           int r[columns];
           int l[columns];
           for(int j=0;j<columns;j++)
           {
                if(matrix[i][j]=='1')
                {
                    h[j]+=1;
                }
                else
                {
                    h[j]=0;
                }
           }
           l[0]=0;
           r[columns-1]=columns-1;
           for(int j=1;j<columns;j++)
           {
               l[j]=j;
               int k=l[j];
               while(l[j]>0&&h[l[j]]<=h[l[k-1]]){
                   l[j]=l[k-1];
                   k=l[j];
               }
           }
           for(int j=columns-2;j>=0;j--)
           {
               r[j]=j;
               int k=r[j];
               while(r[j]<columns-1&&h[r[j]]<=h[r[k+1]]){
                   r[j]=r[k+1];
                   k=r[j];
               }
           }
           for(int j=0;j<columns;j++){
               if(largestArea<h[j]*(r[j]-l[j]+1)){
                  largestArea=h[j]*(r[j]-l[j]+1); 
               }
           }
        }
        return largestArea;
    }
};

int main(int argc,char* argv[]){
    Solution sln;
    vector<vector<char> >  matrix;
    matrix.push_back(vector<char>(5,'0','1','1','0','1'));
    matrix.push_back(vector<char>(5,'1','1','0','1','0'));
    matrix.push_back(vector<char>(5,'0','1','1','1','0'));
    matrix.push_back(vector<char>(5,'1','1','1','1','0'));
    matrix.push_back(vector<char>(5,'0','0','0','0','0'));
    sln.maximalRectangle();
    return 0;
}
