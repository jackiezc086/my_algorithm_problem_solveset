#include <iostream>
using namespace std;
const int N = 20;
char g[N][N];
int st[N];//第i列放过皇后，记为st[i]=1
int dg[N];//第i条正对角线对角线放过皇后，记为dg[i]=1。第x行第y列经过的次对角线，记为udg[x-y]
int udg[N];//第i条次对角线放过皇后，记为udg[i+1] = 1。第x行第y列经过的对角线，记为udg[x+y]
int n;
int cnt = 1;

void dfs(int u){//寻找第u行的皇后应该放在那个位置
    if(u > n){//递归跳出条件，输出
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cout << g[i][j];
            }
                cout << endl;
        }
            cout << endl;
    }
    else{//寻找第u行的皇后应该放在第几列
        for(int i = 1; i <= n; i ++ ){//测试u行i列这个位置    
            if(!st[i] && !dg[u - i] && !udg[u + i]){//如果i列没放过皇后
                g[u][i] = 'Q';
                st[i] = 1; 
                dg[u - i] = 1;
                udg[u + i] = 1;
                
                dfs(u + 1);
                g[u][i] = '.';
                st[i] = 0;
                dg[u - i] = 0;
                udg[u + i] = 0;
            }
        }
    }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            g[i][j] = '.';
        }
    }
    dfs(1);
    return 0;
}

