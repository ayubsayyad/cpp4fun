#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> solution(int N, std::vector<int> &A){
    std::vector<int> counters(N, 0);

    int max_counter = 0;
    int last_max = 0;
    for(int i : A){
        if(i <= N){
            counters[i-1] = std::max(last_max, counters[i-1]) + 1;
            if(counters[i-1] > max_counter)
                max_counter = counters[i-1];
        }else if(i == N + 1){

            //std::for_each(counters.begin(), counters.end(), [max_counter](int& j){ j = max_counter;});
            last_max = max_counter;
        }
    }

    for(int& ctr : counters){
        ctr = std::max(ctr, last_max);
    }

    return counters;
}


int main(){
    std::vector<int> vec = {3,4,4,6,1,4,4};
    auto ret = solution(5, vec);
    std::for_each(ret.begin(), ret.end(), [](int i){std::cout << i << std::endl;});
}

