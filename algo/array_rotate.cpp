#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K){
    if(K == 0 || K == A.size()){
        return A;
    }
    if(A.size() == 0 || A.size() == 1) return A;


    for(int j = 0; j < K; ++j){
        int temp = A[0];
        int temp1 = A[0];
        for(int i = 0; i < A.size(); ++i){
            temp1 = A[(i+1)%A.size()];
            A[(i+1)%A.size()] = temp;
            temp = temp1;
        }
    }

    return A;

}

void print(vector<int> &A){
    for(int i : A){
        std::cout << i << ", ";
    }

    std::cout << endl;
}

int main(){
    vector<int> vec = {1,2,3,4};
    print(vec);
    auto ve = solution(vec, 2);
    print(ve);


    return 0;
}
