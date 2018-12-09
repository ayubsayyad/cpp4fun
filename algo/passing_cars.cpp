#include <iostream>
#include <vector>

int solution(std::vector<int> &A){
    bool start = A[0];
    bool other = start ? 0 : 1;

    long multiplier = 1;
    long other_count = 0;
    long total_cars = 0;
    for(auto iter = A.begin()+1; iter != A.end(); ++iter){
        if(*iter == other){
            other_count++;
        }else{
            total_cars += other_count*multiplier;
            if(1000000000 < total_cars) return -1;
            other_count = 0;
            multiplier++;
        }
    }
    total_cars += other_count*multiplier;
    if(1000000000 < total_cars) return -1;

    return total_cars;
}


int main(){
    std::vector<int> vec {1,0};
    std::cout << solution(vec) << std::endl;
}

