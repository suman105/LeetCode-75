class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    for (int spell : spells) {
      long long minPotion = (success + spell - 1) / spell;
      auto it = lower_bound(potions.begin(), potions.end(), minPotion);
      result.push_back(potions.end() - it);
    }
    return result;
  }
};