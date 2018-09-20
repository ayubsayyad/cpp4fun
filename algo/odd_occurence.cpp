#include <iostream>

int solution(int A[], int N){

    int num = A[0];
    for(int i = 1; i < N; ++i){
        num = num ^ A[i];
    }

    return num;
}

int main(){
    int A[7];
    A[0] = 9;
    A[1] = 3;
    A[2] = 9;
    A[3] = 3;
    A[4] = 9;
    A[5] = 7;
    A[6] = 9;
    std::cout << solution(A, 7) << std::endl;
}

