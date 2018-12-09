#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int solution(std::vector<int> &A){
    std::unordered_set<int> set;
    std::for_each(A.begin(), A.end(), [&](int i){set.insert(i);});
    return set.size();
}

int main(){
    std::vector<int> vec = {1,3,5,6,6,8,1};
    std::cout << solution(vec) << std::endl;
    
    return 0;
}


