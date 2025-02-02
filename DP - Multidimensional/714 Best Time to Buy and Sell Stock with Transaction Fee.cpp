class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    if (n == 0)
      return 0;

    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < n; i++) {
      cash = max(cash, hold + prices[i] - fee);
      hold = max(hold, cash - prices[i]);
    }

    return cash;
  }
};