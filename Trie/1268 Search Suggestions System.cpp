class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // Step 1: Sort the products lexicographically
        vector<vector<string>> result;
        string prefix = "";

        for (char c : searchWord) {
            prefix += c;

            // Step 2: Use lower_bound to find the first occurrence of the prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            
            // Step 3: Collect up to 3 valid suggestions
            vector<string> suggestions;
            for (int i = 0; i < 3 && (it + i) != products.end(); i++) {
                string word = *(it + i);
                if (word.find(prefix) != 0) break; // If word does not match prefix, stop
                suggestions.push_back(word);
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};