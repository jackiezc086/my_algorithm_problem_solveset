//xPATx 或者 xPAATxx
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n --){
        string str;
        cin >> str;
        int ill = 0;//发现非法字符时记ill = 1
        int index_p = -1;
        int index_t = -1;
        int cntA = 0;
        int cntA1 = 0;
        int cntA2 = 0;
        int cntA3 = 0;
        for(int i = 0; str[i]; i ++){
            if(str[i] == 'P' && index_p == -1){
                index_p = i;
            } 
            else if(str[i] == 'T' && index_t == -1){
                index_t = i;
            }
            else if(str[i] == 'A'){
                cntA ++;
            }
            else {
                ill = 1;
                puts("NO");
                break;
            }
        }
        cntA1 = index_p;
        cntA2 = index_t - index_p -1;
        cntA3 = str.length() - index_t - 1;
        if(cntA3 == cntA2 * cntA1 && ill == 0 && cntA2 > 0){
            puts("YES");
        }
        else if(ill == 0){
            puts("NO");
        }
    }
    return 0;
}
