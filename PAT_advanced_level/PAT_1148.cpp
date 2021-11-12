#include <iostream>
#include <vector>
using namespace std;
int const N = 105;
int saying[N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> saying[i];
    }
    
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++){
            bool is_wolf[N] = {false};
            is_wolf[i] = true;
            is_wolf[j] = true;
            
            vector<int> liar;
            
            for (int k = 1; k <= n; k ++){
                if((is_wolf[abs(saying[k])] && saying[k] > 0) || (!is_wolf[abs(saying[k])] && saying[k] < 0))
                    liar.push_back(k);
            }
            
            if(liar.size() == 2 && ( (is_wolf[liar[0]] && !is_wolf[liar[1]]) || (!is_wolf[liar[0]] && is_wolf[liar[1]]) )){
               cout << i << " "<< j << endl;
               return 0;
            }
        }
    cout << "No Solution" << endl;
    return 0;
}
