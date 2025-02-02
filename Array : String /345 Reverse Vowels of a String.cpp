class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = s.length() - 1;

    while (i < j) {
      while (i < j) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          break;
        i++;
      }

      while (i < j) {
        char c = tolower(s[j]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          break;
        j--;
      }

      swap(s[i++], s[j--]);
    }

    return s;
  }
};