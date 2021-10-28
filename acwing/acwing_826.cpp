#include <iostream>
using namespace std;

int const N = 100010;
int h = -1, e[N], ne[N], idx = 1;
void H(int x)
{
    e[idx] = x;
    ne[idx] = h;
    h = idx ++;
}
void I(int x,int y)
{
    e[idx] = y;
    ne[idx] = ne[x];
    ne[x] = idx ++;
}
void D(int x)
{
    if (x == 0) h = ne[h];
    else ne[x] = ne[ne[x]];
}
int main(){

    int n;
    cin >> n;
    while (n -- ){
        char s;
        cin >> s;
        if(s == 'H')
        {
            int x;
            scanf("%d",&x);
            H(x);
        }
        else if(s == 'I')
        {
            int x,y;
            scanf("%d %d",&x,&y);
            I(x,y);
        }
        else if(s == 'D')
        {
            int x;
            scanf("%d",&x);
            D(x);
        }
    }

    bool is_first = true;
    for (int i = h;i != -1 ;i = ne[i])
    {
        if (is_first) is_first = false;
        else printf(" ");
        printf("%d",e[i]);
    }

    return 0;
}


