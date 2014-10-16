#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0;i<n;i++){
            if(A[i]!=i+1&&A[i]>0&&A[i]<=n){
                swap(A[i],A[A[i]-1]);
            }
        }
              for(int i=0;i<n;i++)
                cout<<A[i]<<endl;
        for(int i=0;i<n;i++)
           if(A[i]!=i+1)
              return i+1;
        return n+1;
    }
};

int main()
{
   int* A=new int[4];
   A[0]=3;A[1]=4;A[2]=-1;A[3]=1;
   Solution sln;
   cout<<sln.firstMissingPositive(A,4)<<endl;
   return 0;
}
