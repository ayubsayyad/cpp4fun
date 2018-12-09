#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){
    if(A.size() == 0) return 0;
    bool check[A.size()] = {false};
    int check_count = 0;
    long int sum  = 0;
    for(auto i : A){
        if(i > A.size()) return 0;
        if(check[i-1] == true) return 0; 

        check[i-1] = true;
        check_count++;
    }

//    long int sum2 = (A.size()*(A.size()+1))/2;

    return check_count == A.size();
}


int main(){
    std::vector<int> vec = {4,1,3,2};
    std::vector<int> vec1 = {4,1,3};
    std::cout << solution(vec) << std::endl;
    std::cout << solution(vec1) << std::endl;
}
