#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){
    if(A.size() < 3) return 0;

    std::sort(A.begin(), A.end());

    for(int i = 2; i < A.size(); ++i){
        if((long)A[i-2] + (long)A[i-1] > (long)A[i])
            return 1;
    }

    return 0;
}

int main(){
    std::vector<int> vec = {10,2,5,1,8,20};
    std::vector<int> vec1 = {10,50,5,1};

    std::cout << solution(vec) << std::endl;
    std::cout << solution(vec1) << std::endl;

    return 0;
}


