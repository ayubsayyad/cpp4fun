#include <iostream>
#include <vector>


void print_top(std::vector<std::vector<int>>& array, int layer){
    for(int i = layer; i < array[0].size() - layer ; ++i){
        std::cout << array[layer][i] << ",";
    }
}

void print_right(std::vector<std::vector<int>>& array, int layer){
    for(int i = layer + 1; i < array.size() - layer ; ++i){
        std::cout << array[i][array[0].size()-layer - 1] << ",";
    }
}

void print_bottom(std::vector<std::vector<int>>& array, int layer){
    if(array.size()/2 == layer) return;

    for(int i = layer + 1; i < array[0].size() - layer; ++i){
        //std::cout << i << std::endl;
        std::cout << array[array.size() - layer - 1][array[0].size() - i - 1] << ",";
    }
}

void print_left(std::vector<std::vector<int>>& array, int layer){
    for(int i = layer + 1; i < array.size() - layer -1; ++i){
        std::cout << array[array.size() - i - 1][layer] << ",";
    }
}

void print_spiral(std::vector<std::vector<int>>& array){
    
    int layers = std::max(array.size() -1, array[0].size()) - 1;
    std::cout << layers << std::endl;

    for(int i = 0; i < layers; ++i){
        print_top(array, i);
        print_right(array, i);
        print_bottom(array, i);
        print_left(array, i);
    }

    std::cout << std::endl;
}

int main(){
    
    std::vector<std::vector<int>> vec = {
                                         {1,2,3},
                                         {8,9,4},
                                         {7,6,5}
                                         };
    
    std::vector<std::vector<int>> vec1 = {
                                         {1, 2, 3, 4},
                                         {12,13,14,5},
                                         {11,16,15,6},
                                         {10,9, 8, 7}
                                         };

    std::vector<std::vector<int>> vec2 = {
                                         {1, 2, 3, 4},
                                         {10,11,12,5},
                                         {9, 8, 7, 6}
                                         };

    std::vector<std::vector<int>> vec3 = {
                                         {1},
                                         {2},
                                         {3}
                                         };



    //print_spiral(vec);
    //print_spiral(vec1);
    //print_spiral(vec2);
    print_spiral(vec3);

    return 0;
}
