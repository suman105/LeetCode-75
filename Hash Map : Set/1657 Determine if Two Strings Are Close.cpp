class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
      return false;

    vector<int> freq1(26, 0), freq2(26, 0);
    vector<int> charExists1(26, 0), charExists2(26, 0);

    for (char &c : word1) {
      freq1[c - 'a']++;
      charExists1[c - 'a'] = 1;
    }

    for (char &c : word2) {
      freq2[c - 'a']++;
      charExists2[c - 'a'] = 1;
    }

    if (charExists1 != charExists2)
      return false;

    sort(begin(freq1), end(freq1));
    sort(begin(freq2), end(freq2));

    return freq1 == freq2;
  }
};