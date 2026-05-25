class MinStack {
public:
    stack<pair<int, int>> min_stack;

    MinStack() {}

    void push(int val) {
        if (min_stack.empty()) {
            min_stack.push({val, val});
        } else {
            int MinElement = min_stack.top().second;
            if (val < MinElement)
                min_stack.push({val, val});
            else
                min_stack.push({val, MinElement});
        }
    }

    void pop() {
        if(min_stack.empty())
            return ;
        min_stack.pop();
    }

    int top() { return min_stack.top().first; }

    int getMin() { return min_stack.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */