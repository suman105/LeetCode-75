class StockSpanner {
public:
  StockSpanner() {}

  int next(int price) {
    int span = 1;
    while (!stack.empty() && stack.top().first <= price) {
      span += stack.top().second;
      stack.pop();
    }
    stack.push({price, span});
    return span;
  }

private:
  stack<pair<int, int>> stack;
};