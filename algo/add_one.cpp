#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> nums, int numToadd){
  std::vector<int> out;
  int carry = numToadd;
  for(auto iter = nums.rbegin(); iter != nums.rend(); ++iter){
      auto i = *iter;
      const auto addition = carry + i;
      if(addition > 9){
      int add = addition % 10;
      carry = addition / 10;
      out.push_back(add);
    }
    else{
      carry = 0;
      out.push_back(addition);
    }
  }

  if(carry != 0){
    out.push_back(carry);
  }

  

  std::for_each(out.rbegin(), out.rend(), [](int i){std::cout << i;});




  std::cout << std::endl;

  return 0;
}


int main(){
    std::vector<int> vec =  {1,2,3};
    std::vector<int> vec1 =  {1,9,9};
    std::vector<int> vec2 =  {9,9};
    solution(vec, 1);
    solution(vec1, 1);
    solution(vec2, 1);
    return 0;
}

