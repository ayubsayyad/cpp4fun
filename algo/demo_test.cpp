#include <iostream>
#include <algorithm>
#include <vector>

int solution(std::vector<int> &A) {
    if(A.empty()) return 1;

    std::sort(A.begin(), A.end());

    auto iter = A.begin();
    for(; iter != A.end(); ++iter){
        if(*iter >= 1) break;
    }
    if(iter == A.end()) return 1;

    if(*iter > 1) return 1;

    int priv = *iter;
    ++iter;
    for(; iter != A.end(); ++iter){
        if((*iter - priv) > 1) return priv+1;

        priv = *iter;
    }

    return priv+1;
}

int main(){
    std::vector<int> vec = {1, -2,5,2};
    solution(vec);

    return 0;
}
