class Solution {
public:
  const int MOD = 1e9 + 7;

  int numTilings(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    vector<long long> dp(n + 1, 0);
    vector<long long> p(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;
    p[2] = 1;

    for (int i = 3; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2] + 2 * p[i - 1]) % MOD;
      p[i] = (dp[i - 2] + p[i - 1]) % MOD;
    }

    return dp[n];
  }
};