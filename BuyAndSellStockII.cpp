#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int maxProfit(vector<int> &Prices){
            int size  = Prices.size(); 
            if(size<2) return 0;
            int lowVal = Prices[0], highVal = Prices[0], Profits = 0;
            for(int i=1;i<size;i++){
                if(Prices[i]>Prices[i-1]){
                    highVal = Prices[i];
                }
                else
                if(Prices[i]<Prices[i-1]){
                    Profits += highVal - lowVal;
                    highVal = lowVal = Prices[i];
                }
            }
            return Profits + highVal - lowVal;
        }
};
int main(int argc,char* argv[]){
    return 0;
}
