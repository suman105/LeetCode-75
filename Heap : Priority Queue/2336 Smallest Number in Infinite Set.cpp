class SmallestInfiniteSet {
    private:
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        unordered_set<int> inHeap;
        int nextNumber;
    
    public:
        SmallestInfiniteSet() {
            nextNumber = 1;
        }
    
        int popSmallest() {
            if (!minHeap.empty()) {
                int smallest = minHeap.top();
                minHeap.pop();
                inHeap.erase(smallest);
                return smallest;
            }
            return nextNumber++;
        }
    
        void addBack(int num) {
            if (num < nextNumber && inHeap.find(num) == inHeap.end()) {
                minHeap.push(num);
                inHeap.insert(num);
            }
        }
    };