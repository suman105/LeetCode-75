class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    int a = word1.length(), b = word2.length();
    string result;

    while (i < a && j < b) {
      result += word1[i++];
      result += word2[j++];
    }

    while (i < a)
      result += word1[i++];
    while (j < b)
      result += word2[j++];

    return result;
  }
};