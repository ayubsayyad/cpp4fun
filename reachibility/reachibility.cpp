#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, int x, int y, vector<int>& visited) {
    if(x == y){
        return true;
    }
    visited[x] = true;
    for(int elem : adj[x]){
        if(!visited[elem]){
            if(explore(adj, elem, y, visited)){
                return true;
            }
        }
    }

    return false;
}

int reach(vector<vector<int> > &adj, int x, int y) {
    //write your code here
    vector<int> visited(adj.size());
    std::for_each(visited.begin(), visited.end(), [](int& v){ v = 0;});
    
    return explore(adj, x, y, visited);
}

void explore1(vector<vector<int> > &adj, int x, vector<int>& visited) {
    visited[x] = true;
    for(int elem : adj[x]){
        if(!visited[elem]){
            explore1(adj, elem, visited);
        }
    }
}

int findconnected(vector<vector<int> > &adj){
    int count = 0;
    vector<int> visited(adj.size());
    std::for_each(visited.begin(), visited.end(), [](int& v){ v = 0;});

    for(int i =0; i < adj.size(); ++i){
        if(!visited[i]){
            count++;
            explore1(adj, i, visited);
        }
    }

    return count;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1) << std::endl;

    std::cout << findconnected(adj) << std::endl;
}

