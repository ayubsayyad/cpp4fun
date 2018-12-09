#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>


struct counts{
    int As;
    int Cs;
    int Gs;
    int Ts;
    counts(){
        As = Cs = Gs = Ts = 0;
    }
};

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q){

    std::vector<counts> arr(S.size()+1);

    for(int i =0; i < S.size(); ++i){
        int a,c,g,t;
        a = c = g = t = 0;
        if('A' ==  S[i])
            a = 1;
        if('C' ==  S[i]) 
            c = 1;
        if('G' ==  S[i]) 
            g = 1;
        if('T' ==  S[i]) 
            t = 1;
            
        arr[i+1].As = arr[i].As + a;
        arr[i+1].Cs = arr[i].Cs + c;
        arr[i+1].Gs = arr[i].Gs + g;
        arr[i+1].Ts = arr[i].Ts + t;
    }

    std::vector<int> out_vec;
    for(int i = 0; i < P.size(); ++i){
        if(arr[Q[i]+1].As - arr[P[i]].As > 0){
            out_vec.push_back(1);
        }
        else if(arr[Q[i]+1].Cs - arr[P[i]].Cs > 0){
            out_vec.push_back(2);
        }
        else if(arr[Q[i]+1].Gs - arr[P[i]].Gs > 0){
            out_vec.push_back(3);
        }
        else { //if(std::get<3>(arr[Q[i] + 1]) - std::get<3>(arr[P[i]]) > 0){
            out_vec.push_back(4);
        }
    }

    return out_vec;
}


int main(){
    std::vector<int> P = {0,0,4,7};
    std::vector<int> Q = {8,2,5,7};
    std::string str = "GACACCATA";

    auto vec = solution(str, P, Q);

    std::for_each(vec.begin(), vec.end(), [](int i) {std::cout << i << std::endl;});
}

