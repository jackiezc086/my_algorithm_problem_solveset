#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 100000;
int h[2][N];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        scanf("%d %d", &h[0][i], &h[1][i]);
    }
    
    while (m -- ){
        int k;
        scanf("%d",&k);
        unordered_set<int> S;
        bool is_safe = true;
        for(int i = 0; i < k; i ++){
            int num;
            scanf("%d",&num);
            S.insert(num);
        }
        for(int i = 0; i < n; i ++){
            if(S.count(h[0][i]) && S.count(h[1][i]) && is_safe){
                is_safe = false;
                break;
            }
        }
        
        if(!is_safe)puts("No");
        else puts("Yes");
    }
    return 0;
}
