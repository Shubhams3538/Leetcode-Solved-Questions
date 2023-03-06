class StockSpanner {
public:
// we have a pair of stack where the first represent price and second 
// represents that it is smaller than how many before it.
     
    stack<pair<int,int>> stack;
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
   // we keep adding until we find an element bigger than it's value or until stack become empty and then we push it into stack and move forward .
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */