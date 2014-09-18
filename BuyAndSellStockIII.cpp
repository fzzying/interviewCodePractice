#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int> &prices){
            if(prices.size()<2) return 0;
            vector<int> profitsAtoB;
            vector<int> profitsBtoA;
            int size = prices.size();
            int min_price = prices[0], max_price = prices[size-1], maxProfit = INT_MIN, lastVal = 0;
            profitsAtoB.push_back(0);
            profitsBtoA.push_back(0);
            for(int i=1;i<size;i++){
                min_price = min(prices[i], min_price);
                profitsAtoB.push_back(max(prices[i]-min_price, lastVal));
                lastVal=profitsAtoB.back();
            }
             lastVal = 0;
            for(int i=size-2;i>=0;--i){
                max_price = max(prices[i], max_price);
                profitsBtoA.push_back(max(max_price-prices[i], lastVal));
                lastVal=profitsBtoA.back();
            }
            for(int i=1;i<size-1;i++){
                maxProfit=max(profitsAtoB[i]+profitsBtoA[size-2-i],maxProfit);
            }

            return max(profitsAtoB[size-1],maxProfit);
        }
};

int main(int argc,char* argv[]){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(7);
    prices.push_back(11);
    prices.push_back(4);
    prices.push_back(2);
    Solution sln;
    cout<<sln.maxProfit(prices)<<endl;
    return 0;
}
