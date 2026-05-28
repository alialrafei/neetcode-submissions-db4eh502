class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (const string& token : tokens) {
            if (token.size() > 1 || token[0] >= '0' && token[0] <= '9') {
                numbers.push(stoi(token));
            } else {
                int rightOperand = numbers.top();
                numbers.pop();
                int leftOperand = numbers.top();
                numbers.pop();
                int total = 0;
                if (token == "+")
                    total = leftOperand + rightOperand;

                else if (token == "-")
                    total = leftOperand - rightOperand;

                else if (token == "*")
                    total = leftOperand * rightOperand;

                else if (token == "/")
                    total = leftOperand / rightOperand;
                numbers.push(total);
            }
        }
        return numbers.top();
    }
};