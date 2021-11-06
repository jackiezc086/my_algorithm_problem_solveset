#include <iostream>
#include <algorithm>
using namespace std;
int const N = 10 + 5;
int a[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int m = *max_element(a + 1, a + n + 1);
    int e = a[n];
    //cout << m << e << endl;
    int x = m xor e;
    cout << x << endl;
    
}
