//注意答案精确到小数点后一位，注意double和int类型的数
#include <iostream>
using namespace std;
int const N = 1001;
double h[2][N];

int main(){
    int k[2];
    for(int i = 0; i < 2; i ++){
        cin >> k[i];
        while(k[i] -- ){
            int a;
            cin >> a;
            cin >> h[i][a];
        }
    }
    double res[N] = {0};
    int cnt = 0;
    for(int i = 0; i < 1001; i ++){
        res[i] = h[0][i] + h[1][i];
        if(res[i] != 0) cnt ++;
    }
    cout << cnt;
    for(int i = 1000; i >= 0; i -- ){
        if(res[i] != 0) {
            cout << ' ' << i << ' ';
            printf("%.1f",res[i]);
        }
    }
    return 0;
}
