#include <iostream>
using namespace std;
int const N = 1010;
int const M = 10010;
int Edge[2][M] = {0};
int main(){
    
    int n,m;
    scanf("%d %d",&n, &m);
    for (int i = 0; i < m; i ++){
        int a,b;
        scanf("%d %d",&a, &b);
        Edge[0][i] = a;
        Edge[1][i] = b;
    }
    
    int k;
    scanf("%d",&k);
    
    bool is_first = true;
    for (int i = 0; i < k; i ++){
        int h[n];
        int pos[n + 1];
        
        for (int i = 0; i < n; i ++){
            scanf("%d",&h[i]);
            pos[h[i]] = i;
        }
        bool success = true;
        for (int j = 0; j < m; j ++){
            if(pos[Edge[0][j]] > pos[Edge[1][j]]){
                success = false;
                break;
            }
        }
        if(!success){
            if(is_first) is_first = false;
            else cout << " ";
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
