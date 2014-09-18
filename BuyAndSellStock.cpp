#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int> &Prices){
            if(Prices.size()<2) return 0;
            int maxProfits=0,lowest=Prices[0]; 
            for(auto &price:Prices){
                lowest = min(price,lowest);
                maxProfits = max(maxProfits,price-lowest);
            }
            return maxProfits;
        }
};

int main(int argc,char* argv[]){
    return 0;
}
