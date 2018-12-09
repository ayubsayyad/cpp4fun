#include <vector>
#include <iostream>

int solution(int X, std::vector<int> &A){
    bool positions[X+1] = {false};
    int slots_filled = 0;

    int i =0;
    for(; i < A.size(); ++i){
        if (A[i] > X) continue;

        if(positions[A[i]] == true) continue;

        positions[A[i]] = true;
        slots_filled++;

        if(slots_filled == X){
            return i;
        }
    }

    return -1;
}

int main(){
    std::vector<int> vec = {1,3,1,4,2,3,5,4};

    std::cout << solution(5, vec) << std::endl;
}

