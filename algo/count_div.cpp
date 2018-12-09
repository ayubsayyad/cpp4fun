#include <iostream>


int solution(int A, int B, int K){

    int divcount = 0;
    if((A%K) == 0) divcount++; 
    
    return ((B/K - A/K) + divcount);
}

int main(){

    std::cout << solution(1, 1, 11) << std::endl;
    std::cout << solution(10, 10, 5) << std::endl;
    std::cout << solution(10, 10, 7) << std::endl;
    std::cout << solution(10, 10, 20) << std::endl;
    std::cout << solution(6, 11, 2) << std::endl;

    return 0;
}
