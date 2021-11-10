#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int const N = 1005;
int h[N];
int n;
bool max_heap = true;
bool min_heap = true;
vector<int> path;

void dfs(int x){
    path.push_back(h[x]);
    
    if(2 * x > n){//叶节点
        cout << path[0];
        for(int i = 1; i < path.size(); i ++){
            if(path[i] > path[i - 1]) max_heap = false;
            if(path[i] < path[i - 1]) min_heap = false;
            cout << ' ' << path[i];
        }
        cout << endl;
    }
    
    if(2 * x + 1 <= n) dfs(2 * x + 1);
    if(2 * x <= n) dfs(2 * x);
    
    path.pop_back();
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    
    dfs(1);
    
    if (max_heap && !min_heap)puts("Max Heap");
    if (min_heap && !max_heap)puts("Min Heap");
    if (!max_heap && !min_heap)puts("Not Heap");
    if (max_heap && min_heap)puts("Error");
    return 0;
}
