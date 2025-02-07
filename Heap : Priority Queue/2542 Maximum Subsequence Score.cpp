class Solution {
    public:
        long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            int n = nums1.size();
            vector<pair<int, int>> pairs;
            
            for (int i = 0; i < n; i++) {
                pairs.push_back({nums2[i], nums1[i]});
            }
            sort(pairs.rbegin(), pairs.rend());
    
            priority_queue<int, vector<int>, greater<int>> minHeap; 
            long long maxScore = 0, sum = 0;
    
            for (int i = 0; i < k; i++) {
                sum += pairs[i].second;
                minHeap.push(pairs[i].second);
            }
            maxScore = sum * pairs[k - 1].first;
    
            for (int i = k; i < n; i++) {
                sum += pairs[i].second - minHeap.top();
                minHeap.pop();
                minHeap.push(pairs[i].second);
                maxScore = max(maxScore, sum * pairs[i].first);
            }
    
            return maxScore;
        }
    };