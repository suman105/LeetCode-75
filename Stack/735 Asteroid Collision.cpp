class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;  // Stack to track moving asteroids

        for (int asteroid : asteroids) {
            bool destroyed = false;

            // Handle collision when moving right (+) meets moving left (-)
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop(); // Previous asteroid is smaller, destroy it
                    continue;
                } else if (abs(st.top()) == abs(asteroid)) {
                    st.pop(); // Both asteroids destroy each other
                }
                destroyed = true; // Current asteroid is destroyed
                break;
            }

            if (!destroyed) {
                st.push(asteroid); // Push asteroid to stack if not destroyed
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};