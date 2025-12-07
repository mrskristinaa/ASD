#include "algorithms.h"
#include "stack.h"
bool check_algorithms(const std::string& symbol) {
    Stack<char> stack;
    for (char ch : symbol) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.is_empty()) {
                return false;
            }
            char top_char = stack.top();
            stack.pop();
            if ((ch == ')' && top_char != '(') || (ch == '}' && top_char != '{') || (ch == ']' && top_char != '[')) {
                return false;
            }
        }
    }
    return stack.is_empty();
}