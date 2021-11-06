//一个不够间接的写法
#include <iostream>
using namespace std;
const int N = 8 + 5;
int g[N][N];
bool check_che(int a1,int b1, int a2, int b2){//检查a1,b1的车会不会攻击到a2,b2的子，会攻击到返回true
    if(a1 == a2 || b1 == b2){
        return true;
    }
    else return false;
}
bool check_ma(int a1,int b1, int a2, int b2){//检查a1,b1的马会不会攻击到a2,b2的子
    if(a1 + 2 == a2 && b1 + 1 == b2) return true;
    else if(a1== a2 && b1 == b2) return true;
    else if(a1 + 2 == a2 && b1 - 1 == b2) return true;
    else if(a1 + 1 == a2 && b1 + 2 == b2) return true;
    else if(a1 + 1 == a2 && b1 - 2 == b2) return true;
    else if(a1 - 1 == a2 && b1 + 2 == b2) return true;
    else if(a1 - 1 == a2 && b1 - 2 == b2) return true;
    else if(a1 - 2 == a2 && b1 + 1 == b2) return true;
    else if(a1 - 2 == a2 && b1 - 1 == b2) return true;
    
    return false;
}

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    int x1 = str1[0] - 'a' + 1;
    int y1 = str1[1] - '1' + 1;
    g[x1+2][y1+2] = 1;
    
    int x2 = str2[0] - 'a' + 1;
    int y2 = str2[1] - '1' + 1;
    g[x2+2][y2+2] = 1;
    int cnt = 0;
    for(int i = 3; i <= 10; i ++){
        for(int j = 3; j <= 10; j ++){
        if(!check_che(x1+2, y1+2,i ,j) && !check_ma(x2+2, y2+2,i ,j) && !check_ma(i, j,x1 + 2 ,y1 +2)){
            cnt ++;
        }
    }
    }
    cout << cnt << endl;
    return 0;
}
