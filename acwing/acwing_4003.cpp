#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//用sqrt函数判断是否是完全平方数，注意要用int保存开方后的结果
bool check(int a){
    if(a < 0) return false;
    else if(a == 0) return true;
    else if(a > 0){
        int t = sqrt(a);
        if(t * t == a) return true;
        else return false;
    }
}

int main(){
    int n;
    cin >> n;
    int ans = -1e8;
    int a;
    while(n -- ){
        cin >> a;
        if (!check(a)){
            ans = max(a,ans);
        }
    }
    cout << ans;
    return 0;
}
