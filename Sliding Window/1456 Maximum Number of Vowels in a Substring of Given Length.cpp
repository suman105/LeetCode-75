class Solution {
public:
  int maxVowels(string s, int k) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int curCount = 0, maxCount = 0;

    for (int i = 0; i < s.size(); i++) {
      if (vowels.count(s[i]))
        curCount++;
      if (i >= k && vowels.count(s[i - k]))
        curCount--;
      maxCount = max(curCount, maxCount);
    }

    return maxCount;
  }
};