//from 2:47 pm to 3:05 pm
#include <iostream>
#include <set>
using namespace std;
const int N = 10010;
const int M = 10010;
int color[N];
int edge[2][M];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        scanf("%d %d", &edge[0][i], &edge[1][i]);
    }
    
    int k;
    cin >> k;
    while (k -- ){
        set<int> s;
        for(int i = 0; i < n; i ++){
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        bool is_proper = true;
        for(int i = 0; i < m; i ++){
            int a = color[edge[0][i]];
            int b = color[edge[1][i]];
            if(a == b) is_proper = false;
        }
        if(is_proper == false)puts("No");
        else printf("%d-coloring\n",s.size());
    }
    
    return 0;
}
