#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){
    std::sort(A.begin(), A.end(), std::greater<int>());
    return std::max(A[0]*A[1]*A[2], A[0]*A[A.size()-1]*A[A.size() - 2]);
}

int main(){
    std::vector<int> vec = {-3,1,2,-2, 5,6};

    std::cout << solution(vec) << std::endl;
}


