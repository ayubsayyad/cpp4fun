#include <iostream>
#include <vector>

int solution(std::vector<int> &A){
    if(A.size() < 2) return 0;

    int minidx = 0;
    double minavg = (A[0] + A[1]) / 2.0;

    for(int i = 2; i < A.size(); ++i){
        double min3 = (A[i] + A[i-1] + A[i-2])/3.0;
        double min2 = (A[i] + A[i-1])/2.0;

        if(minavg > min2){
            minavg = min2;
            minidx = i-1;
        }
        if(minavg > min3){
            minavg = min3;
            minidx = i-2;
        }
    }

    return minidx;
}


int main(){
    std::vector<int> vec = {4,2,2,5,1,5,8};

    std::cout << solution(vec) << std::endl;

    return 0;
}


