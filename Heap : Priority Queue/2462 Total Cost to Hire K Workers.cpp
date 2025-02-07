
class Solution {
    public:
        long long totalCost(vector<int>& costs, int k, int candidates) {
            priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;
            int n = costs.size();
            int left = 0, right = n - 1;
            long long totalCost = 0;
    
            for (int i = 0; i < candidates && left <= right; i++) {
                leftHeap.push(costs[left++]);
                if (left <= right) rightHeap.push(costs[right--]);
            }
    
            while (k--) {
                if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                    totalCost += leftHeap.top();
                    leftHeap.pop();
                    if (left <= right) leftHeap.push(costs[left++]);
                } else {
                    totalCost += rightHeap.top();
                    rightHeap.pop();
                    if (left <= right) rightHeap.push(costs[right--]);
                }
            }
    
            return totalCost;
        }
    };