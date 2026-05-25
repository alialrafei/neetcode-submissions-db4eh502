class MyQueue {
public:
    stack<int> helper_stack;
    stack<int> main_stack;
    int front;
    int second_front;
    MyQueue() {}

    void push(int x) {
        if (main_stack.empty() && helper_stack.empty())
            front = x;
        else if(main_stack.empty() &&!helper_stack.empty() )
            second_front = x;
        main_stack.push(x);
    }

    int pop() {
        if (helper_stack.empty()) {
            while (!main_stack.empty()) {
                helper_stack.push(main_stack.top());
                main_stack.pop();
            }
        }

        int old_front = helper_stack.top();
        helper_stack.pop();
        if(!helper_stack.empty())
            front = helper_stack.top();
        else 
            front = second_front;
        return old_front;
    }

    int peek() {
        return front;
    }

    bool empty() { return main_stack.empty() && helper_stack.empty(); }
};
