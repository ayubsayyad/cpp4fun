#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <tuple>

struct Point{
    int     y_;
    char    x_;
    Point(int y, char x) : y_(y), x_(x){}
};

struct Compare {
    bool operator() (const Point  &lhs, const Point& rhs) const{
        return std::tie(lhs.y_, lhs.x_) < std::tie(rhs.y_, rhs.x_);
    }
};

struct Ship{
    Point p1_;
    Point p2_;
    int total_cells;
    int hit_cells;

    Ship(Point p1, Point p2): p1_(p1), p2_(p2){
        total_cells = (std::abs(p1_.y_ - p2_.y_) + 1) * (std::abs(p1_.x_ - p2_.x_) + 1);
        hit_cells = 0;
        //std::cout << total_cells << std::endl;
    }

    bool hit_ship(const Point& bullet){
        if((bullet.y_ >= p1_.y_) && (bullet.y_ <= p2_.y_) &&
           (bullet.x_ >= p1_.x_) && (bullet.x_ <= p2_.x_)){
            hit_cells++;

            return true;
        }
        return false;
    }
};

int getCoordinates(const std::string& str, int startidx, Point& pt){

    int chars = 3;

    char n[3] = {0};
    n[0] = str[startidx];
    char ch = str[startidx + 1];
    if(str[startidx + 1] < 65){
        n[1] = str[startidx + 1];
        ch = str[startidx + 2];
        chars = 4;
    }

    pt = Point(atoi(n), ch);

    return chars;

}

std::string solution(int N, const std::string ships, const std::string T){
    std::vector<Ship> vec;
    int start_idx = 0;
    int i = 0;
    for(; i <= ships.size(); ++i){
        if((ships[i] == ',') || (ships[i] == '\0')){
            Point pt1(0,0);
            int chars = getCoordinates(ships, start_idx, pt1);

            Point pt2(0,0);
            chars = getCoordinates(ships, start_idx + chars, pt2);

            vec.push_back(Ship(pt1, pt2));
            ++i;
            start_idx = i;
        }
    }

    std::set<Point, Compare> bullet_set;
    i = 0;
    start_idx = 0;
    for(; i <= T.size(); ++i){
        if(T[i] == ' ' || T[i] == '\0'){
            Point bullet(0,0);
            getCoordinates(T, start_idx, bullet);
            i++;
            start_idx = i;

            auto iter = bullet_set.find(bullet);
            if(iter != bullet_set.end()){
                //std::cout << "found" << std::endl;
                continue;
            }
            bullet_set.insert(bullet);

            for(Ship& s : vec){
                if(s.hit_ship(bullet)) break; // ships are not overlapping so if bullet hits, it wont hit again
            }
        }
    }

    int distroyed = 0;
    int hit = 0;
    for(Ship& s : vec){
        if(s.hit_cells != 0){
            if(s.hit_cells >= s.total_cells){
                distroyed++;
            }
            else{
                hit++;
            }
        }
    }

    char solution[100 + 1] = {0};
    snprintf(solution, 100, "%d,%d", distroyed, hit);

    return std::string(solution);
}

int main(){
    std::cout << solution(10, "1B 2C,2D 4D", "2B 2D 3D 4D 4A") << std::endl;;
    std::cout << solution(10, "1A 1B,2C 2C", "1B") << std::endl;
    std::cout << solution(10, "1A 2A,12A 12A", "12A 12A") << std::endl;
}

