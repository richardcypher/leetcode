#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    vector<int> profits(prices.size(), 0);
    int minprice = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] < minprice)
            minprice = prices[i];
        profits[i] = profits[i - 1] < (prices[i] - minprice) ? (prices[i] - minprice) : profits[i - 1];
    }
    return profits[profits.size() - 1];
}

int main() {
    return 0;
}