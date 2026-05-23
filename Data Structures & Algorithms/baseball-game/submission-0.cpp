class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> operation_stack;
        for (const string& operation : operations) {
            if (operation == "C")
                HandleRemove(operation_stack);
            else if (operation == "D")
                HandleDouble(operation_stack);
            else if (operation == "+")
                HandleAddition(operation_stack);
            else
                operation_stack.push(operation);
        }
        int sum = 0;
        while(!operation_stack.empty()){
            sum = sum + stoi(operation_stack.top());
            operation_stack.pop();
        }
        return sum;
    }

private:
    void HandleRemove(stack<string>& operation_stack) {
        if (!operation_stack.empty()) {
            operation_stack.pop();
        }
    }
    void HandleAddition(stack<string>& operation_stack) {
        if (operation_stack.size() >= 2) {
            int first_number = stoi(operation_stack.top());
            operation_stack.pop();
            int second_number = stoi(operation_stack.top());
            operation_stack.pop();
            

            operation_stack.push(to_string(second_number));
            operation_stack.push(to_string(first_number));
            

            operation_stack.push(to_string(first_number + second_number));
        }
    }
    void HandleDouble(stack<string>& operation_stack) {
        if (!operation_stack.empty()) {
            int number = stoi(operation_stack.top());
            operation_stack.push(to_string(number * 2));
        }
    }
};

