class Solution {
public:
  int tribonacci(int n) {

    if (n == 0 || n == 1)
      return n;

    vector<int> tn(n + 1);

    tn[0] = 0, tn[1] = 1, tn[2] = 1;

    for (int i = 3; i <= n; i++)
      tn[i] = tn[i - 1] + tn[i - 2] + tn[i - 3];

    return tn[n];
  }
};