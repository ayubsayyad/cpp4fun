#include <iostream>
#include <vector>
#include <limits>

int max_subarray_sum(std::vector<int> arr){
    int max = arr[0]; 
    int curr_max = arr[0]; 

    for (int i = 1; i < arr.size(); i++) 
    { 
        curr_max = std::max(arr[i], curr_max+arr[i]); 
        max = std::max(max, curr_max); 
    } 
    return max; 
}

int main(){
    std::vector<int> vec1 = {-2,-3, 4,-1, -2, 1, 5, -3};
    std::vector<int> vec2 = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> vec3 = {-163};
    std::vector<int> vec4 = {-2,-3};

    std::cout << max_subarray_sum(vec1) << std::endl;
    std::cout << max_subarray_sum(vec2) << std::endl;
    std::cout << max_subarray_sum(vec3) << std::endl;
    std::cout << max_subarray_sum(vec4) << std::endl;

}
