class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    unordered_set<int> s;

    for (int num : arr)
      m[num]++;
    for (auto i : m)
      s.insert(m[i.first]);

    return s.size() == m.size();
  }
};