#include <vector>
#include <iostream>
#include <algorithm>

int solution(std::vector<int> &A){
    long accum = std::accumulate(A.begin(), A.end(), 0);
    long n = A.size() + 1;

    return int(((n*(n+1))/2) - (accum));
}

int main(){
    std::vector<int> v = {2,3,1,5};
    std::cout << solution(v) << std::endl;
}
