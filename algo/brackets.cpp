#include <stack>
#include <iostream>

bool is_match(char open, char close){
    if(open == '(') return close == ')';
    if(open == '{') return close == '}';
    if(open == '[') return close == ']';

    return false;
}

bool is_open(char ch){
    if(ch == '(' || ch == '{' || ch == '[') return true;

    return false;
}


int solution(std::string &S){

    std::stack<char> stack;    
    for(char ch : S){
        if(is_open(ch)) {
            stack.push(ch);
        }
        else{
            char from_stack = stack.top();
            stack.pop();
            if(!is_match(from_stack, ch)){
                return 0;
            }
        }
    }

    if(!stack.empty()) return 0;

    return 1;
}

int main(){
    std::string str("{[()()]}");
    std::string str1("([)()]");

    std::cout << solution(str) << std::endl;
    std::cout << solution(str1) << std::endl;

    return 0;
}


