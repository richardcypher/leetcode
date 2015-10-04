#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    if(prices.empty())
        return 0;
    int min = prices[0];
    bool buy = true;
    for (int i = 0; i < prices.size(); ++i)
    {
        if(buy) {
            if(i < prices.size() - 1) {
                if(prices[i] >= prices[i + 1])
                    continue;
                else {
                    min = prices[i];
                    buy = false;
                }
            }
        }
        else {
            if(i < prices.size() - 1) {
                if(prices[i] <= prices[i + 1])
                    continue;
                else {
                    profit += prices[i] - min;
                    buy = true;
                }
            }
            else {
                profit += prices[i] - min;
            }
        }
    }
    return profit;
}

int main() {
    return 0;
}