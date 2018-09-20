#include <iostream>

int solution(int input){
    bool found_1 = false;
    int maxbinary_gap = 0;

    int count = 0;
    while(input){
        if(input & 1){
            if(found_1 == false){
                found_1 = true;
            }else{
                if(count > maxbinary_gap){
                    maxbinary_gap = count;
                    count = 0;
                }

                found_1 = false;
                count = 0;
            }
        }else{
            if(found_1)
                count++;
        }
        input = input >> 1;
    }

    return maxbinary_gap;

}

int main(){
    std::cout << solution(9) << std::endl;
    std::cout << solution(15) << std::endl;
    std::cout << solution(8) << std::endl;
    std::cout << solution(20) << std::endl;
    std::cout << solution(529) << std::endl;
    std::cout << solution(32) << std::endl;
    std::cout << solution(561892) << std::endl;

    return 0;
}
