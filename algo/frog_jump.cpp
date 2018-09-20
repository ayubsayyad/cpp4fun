#include <iostream>

int solution(int X, int Y, int D){
    int count =0;
    int distance = Y - X;
    int jumps = distance / D;
    if(distance % D != 0) jumps++;

    return jumps;
}

int main(){
    std::cout << solution(10, 85, 30) << std::endl;
}

