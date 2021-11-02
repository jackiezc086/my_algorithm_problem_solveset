#include <iostream>
using namespace std;

const int N = 10;
int path[N];//记录排列顺序
int st[N];//记录排列顺序里用过的数
int n;

void dfs(int u){//寻找排列中的第u个数
    if(u > n){//递归跳出条件
        for(int i = 1; i <= n - 1; i ++){
            cout << path[i] << " ";
        }
        cout << path[n] << endl;
    }
    else{
        for(int i = 1; i <= n; i ++){//循环1到n，来判断能否作为排列中的第u个数
            if(!st[i]){//如果i之前没用过，就将i作为排列中的第u个数
                path[u] = i;//将i作为排列中的第u个数
                st[i] = 1;//标记i为用过的数
                dfs(u + 1);//继续去寻找排列中的第u + 1个数
                path[u] = 0;//回溯，取消i作为排列中的第u个数，来寻找别的可能性
                st[i] = 0;//回溯，标记i为未使用过的数
            }
        }
    }
}

int main(){
    cin >> n;
    dfs(1);//寻找列表中的第1个数（后续数也会一起寻找）
    return 0;
}
