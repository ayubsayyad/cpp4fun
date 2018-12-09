#include <vector>
#include <iostream>

int solution(std::vector<int> &A){

    std::vector<long> additions;
    long last_add = 0;

    for(int i : A){
        last_add += i;
        additions.push_back(last_add);
    }

    long mindiff = 2147483647;
    auto iter = additions.begin() + 1;
    for(; iter != additions.end(); ++iter){
        long first = *(iter -1);
        long rest = last_add - first;

        auto diff = std::abs(rest - first);
        if(diff < mindiff){
            mindiff = diff;
        }    
    }

    return mindiff;
}

int main(){

    std::vector<int> vec = {3,1,2,4,3};
    std::cout << solution(vec) << std::endl;

    return 0;
}


