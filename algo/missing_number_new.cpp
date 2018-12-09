#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){

    if(A.size() == 0) return 0;

    std::sort(A.begin(), A.end());

    A.erase(std::remove_if(A.begin(), 
                 A.end(),
                 [](int x){return x < 1;}), A.end());

    if(A.size() == 0) return 1;
    if (*A.begin() != 1) return 1;
    if((A.size() == 1) && *A.begin() == 1){
        return 2;
    }else if((A.size() == 1) && *A.begin() != 1){
        return 1;
    }

    int priv = *A.begin();
    for(auto iter = A.begin() + 1; iter != A.end(); ++iter){
        if(*iter == priv) continue;
        
        if(*iter - priv != 1) return ++priv;

        priv = *iter;
    }

    return ++priv;
}

int main(){
    std::vector<int> vec = {1, 3, 6, 4, 1, 2, -1, -2, 0};
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {-1, -3};
    std::vector<int> vec3 = {1};
    std::cout << solution(vec) << std::endl;
    std::cout << solution(vec1) << std::endl;
    std::cout << solution(vec2) << std::endl;
    std::cout << solution(vec3) << std::endl;

    return 0;
}
