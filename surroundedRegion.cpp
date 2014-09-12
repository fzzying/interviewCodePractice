#include<iostream> 
#include<vector>
using namespace std;

class Solution{
    private:
        int n,m;
        void search(int x,int y,vector<vector<char> > &board){
            if(x<=0||x>=n-1) return;
            if(y<=0||y>=m-1) return;
            if(board[x][y]!='M') return;
            board[x][y]='O';
            search(x-1,y,board);
            search(x+1,y,board);
            search(x,y-1,board);
            search(x,y+1,board);
        }
    public:
        void solve(vector<vector<char> > &board){
            n = board.size(); 
            if(n<=2) return;
            m = board[0].size();
            for(int i=1;i<n-1;i++)
            {
                for(int j=1;j<m-1;j++)
                {
                    board[i][j]=board[i][j]=='O'?'M':board[i][j];
                }
            }
            for(int i=1;i<n-1;i++)
                if(board[i][0]=='O')
                {
                    search(i,1,board);
                }
            for(int i=1;i<n-1;i++)
                if(board[i][m-1]=='O')
                {
                    search(i,m-2,board);
                }
            for(int j=1;j<m-1;j++)
                if(board[0][j]=='O')
                {
                    search(1,j,board);
                }
            for(int j=1;j<m-1;j++)
                if(board[n-1][j]=='O')
                {
                    search(n-2,j,board);
                }
            for(int i=1;i<n-1;i++)
            {
                for(int j=1;j<m-1;j++)
                {
                    board[i][j]=board[i][j]=='M'?'X':board[i][j];
                }
            }
 
        }
};

int main(int argc,char* argv[]){
    
}



