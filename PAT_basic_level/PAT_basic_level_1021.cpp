//字符串的长度
#include <iostream>
using namespace std;
const int N = 1000 + 10;
int num[N];

int main(){
    string str;
    cin >> str;
    for(int i = 0; str[i]; i++){
        num[str[i]-48] ++;
    }
    for(int i = 0; i <= 9; i++){
        if(num[i] != 0){
            cout << i << ":" << num[i] << endl;
        }
    }
    
    return 0;
}
