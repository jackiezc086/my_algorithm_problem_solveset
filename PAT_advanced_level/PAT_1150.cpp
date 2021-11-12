#include <iostream>
using namespace std;
int const N = 210;
int const M = 20010;
int const D = 2000000;
int dist[N][N];
int visited[N];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            dist[i][j] = D;
        }
    }
    for (int i = 1; i <= m; i ++){
        int a,b,d;
        cin >> a >> b >> d;
        dist[a][b] = dist[b][a] = d;
    }
    
    int k;
    cin >> k;
    int shortest_dist = D;
    int shortest_dist_index = 1;
    for(int i = 1; i <= k; i ++){//对每一条路径判断
        
        for(int i = 1; i <= n; i ++ ) visited[i] = 0;
        
        int num;
        cin >> num;
        
        int totaldist = 0;
        int start;
        cin >> start;
        int stop1 = start;
        visited[stop1] = 1;
        int stop2;
        for(int j = 1; j < num; j ++){
            cin >> stop2;
            totaldist += dist[stop1][stop2];
            visited[stop2] = 1;
            stop1 = stop2;
        }
        
        bool all_visited = true;
        for(int i = 1; i <= n; i ++){
            if(visited[i] == 0) {
                all_visited = false;
                break;
            }
        }
        
        bool is_TS_simple = false;
        bool is_TS_cycle = false;
        if(all_visited && num == n + 1 && start == stop1 && totaldist < D) 
            is_TS_simple = true;
        else if (all_visited && num != n + 1 && start == stop1 && totaldist < D) 
            is_TS_cycle = true;
        
        if(totaldist >=D)
            printf("Path %d: %s", i, "NA");
        else 
            printf("Path %d: %d", i, totaldist);
        
        if(is_TS_simple) 
            cout << " (TS simple cycle)" << endl;
        else if(is_TS_cycle) 
            cout << " (TS cycle)" << endl;
        else 
            cout << " (Not a TS cycle)" << endl;
        
        if(totaldist < shortest_dist && (is_TS_simple || is_TS_cycle)) {
            shortest_dist = totaldist;
            shortest_dist_index = i;
        }
        
    } 
    printf("Shortest Dist(%d) = %d\n", shortest_dist_index,shortest_dist);
    return 0;
}
