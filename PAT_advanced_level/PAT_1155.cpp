//dfs之前写成死循环了，改了好久才改好
//todo 以后应把层数加入dfs的形参
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int const N = 1005;
int h[N];
int num;
bool max_heap = true;
bool min_heap = true;
int seq[500][10];//seq[i][j] represents the j^th element in i^th sequence

void dfs(int x){
    if(2 * x > num){
        vector<int> res;
        int y = x;
        while (y != 1){
            res.push_back(y);
            if(y % 2 == 0) y /= 2;
            else if(y % 2 == 1) y = (y - 1) / 2;
        }
        res.push_back(1);
        bool is_first = true;
        vector<int> seq;//判断是否递增或递减
        while(!res.empty()){
            if(is_first){
                is_first = false;
            }
            else cout << ' ';
            seq.push_back(h[res.back()]);
            cout << h[res.back()];
            res.pop_back();
        }
        for(int i = 1; i < seq.size(); i ++){
            if(seq[i] > seq[i - 1]) max_heap = false;
            if(seq[i] < seq[i - 1]) min_heap = false;
        }
        cout << endl;
        return;
    }
    if(2 * x + 1 <= num) dfs(2 * x + 1);
    if(2 * x <= num) dfs(2 * x);
}

int main(){
    cin >> num;
    for(int i = 1; i <= num; i ++){
        cin >> h[i];
    }
    
    dfs(1);
    
    if (max_heap && !min_heap)puts("Max Heap");
    if (min_heap && !max_heap)puts("Min Heap");
    if (!max_heap && !min_heap)puts("Not Heap");
    if (max_heap && min_heap)puts("Error");
    return 0;
}

