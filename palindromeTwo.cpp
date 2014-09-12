#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    private:
        vector<vector<string> > ans;
        vector<string> tmp;
        void findAllCombination(vector<int> &p,string &s,int id){
            int size = s.length();
            if(size<=id){
                ans.push_back(tmp);
            }else{
                for(int j=id;j<size;j++) 
                {
                    int len = j-id+1;
                    int px =  2*((j+id)/2+!(len&1))+(len&1); 
                    if(p[px]>=(len)){
                        tmp.push_back(s.substr(id,len));
                        findAllCombination(p,s,j+1);
                        tmp.pop_back();
                    }
                }
            }
        }
    public:
        vector<vector<string> > partition(string s){
           vector<int> p;
           string str;
           str.push_back('^');
           int size = s.length(); 
           for(int i=0;i<size-1;i++)
           {
               str.push_back(s[i]);
               str.push_back('*');
           }
           str.push_back(s[size-1]);
           str.push_back('$');
           p.push_back(0);
           int mx = 0,id=0; 
           size = 2*size + 1;
           cout<<str<<endl;
           for(int i=1;i<size-1;i++){
               int rd = 1;
               if(mx>i){
                    rd = min(p[2*id-i],mx-i);
               }
               while(str[i+rd]==str[i-rd]){
                   rd++;
               }
               if(i+rd>mx){
                    mx = i + rd; 
                    id = i;
               }
               p.push_back(rd);
               cout<<i<<":" <<rd<<endl;
           }
           findAllCombination(p,s,0); 
           return ans;
        }
        void printAns(){
            int size = ans.size();  
            for(int i=0;i<size;i++){
                int size2 = ans[i].size();
                for(int j=0;j<size2;j++){
                    cout<<ans[i][j]<<",";
                }
                cout<<endl;
            }
        }
};

int main(int argc,char* argv[]){
    Solution sln;
    sln.partition("");
    sln.printAns();
    return 0;
}
