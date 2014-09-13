#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution{
    private:
        int length;
        vector<vector<string> > ans;
        vector<string> currentAns;
        string newString(string str,int i,char s){
            char currStr[length+1];
            for(int j=0;j<length;j++)
                currStr[j]=str[j];
            currStr[i]=s;
            currStr[length]='\0';
            return string(currStr);
        }
        void findAnsVector(int index, vector<vector<int> > &trace, vector<string> &BFS){
            if(index == -1){
                ans.push_back(currentAns);
                return;
            }
            currentAns.insert(currentAns.begin(),BFS[index]);
            for(auto &newIndex:trace[index]){
                findAnsVector(newIndex,trace,BFS); 
            }
            currentAns.erase(currentAns.begin());
        }
    public:
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
            length = start.length();
            dict.insert(end);
            vector<string> BFS;
            vector<vector<int> > ansTrace;
            if(start == end){
                  return vector<vector<string> >(1,vector<string>(1,start));
            }
            BFS.push_back(start);
            ansTrace.push_back(vector<int>(1,-1));
            int mostLeft = 0, mostRight = 0, ansIndex;
            bool findAns = false;
            dict.erase(start);
            while(!findAns&&mostLeft<=mostRight){
                unordered_map<string,int> currentLevelMap;
                while(mostLeft<=mostRight){
                    string currentString = BFS[mostLeft++];
                    for(int i=0;i<length;i++)
                        for(char s='a';s<'z';s++)
                        {
                              string word = newString(currentString,i,s);
                                if(dict.find(word)!=dict.end()){
                                    if(currentLevelMap.find(word)==currentLevelMap.end()){
                                        ansTrace.push_back(vector<int>(1,mostLeft-1));
                                        BFS.push_back(word); 
                                        currentLevelMap[word]=BFS.size()-1;
                                    }else{
                                        ansTrace[currentLevelMap[word]].push_back(mostLeft-1);
                                    }
                                    if(!findAns&&word==end){
                                        findAns = true;
                                        ansIndex = BFS.size()-1;
                                    }
                                }
                        }
                }
                for(auto& word:currentLevelMap){
                    dict.erase(word.first);
                }
                mostRight = BFS.size()-1;
            }
            if(findAns){
                currentAns.clear();
                findAnsVector(ansIndex, ansTrace, BFS);
            }
            return ans;
        }
        void printAns(){
            cout<<"Print Answer:"<<endl;
            int n = ans.size(); 
            cout<<n<<endl;
            int m = ans[0].size();
            cout<<m<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++) {
                    cout<<ans[i][j]<<",";
                }
                cout<<endl;
            }
        }
};

int main(int argc,char* argv[]){
    Solution sln; 
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    sln.findLadders("hit","cog",dict);
    sln.printAns();
    return 0;
}
