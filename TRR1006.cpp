#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, v, e;
    inp >> t >> v >> e;
    int adj[v + 10][v + 10], ans[100][100] = {0};
    for(int i = 1; i <= e; i++){
        int x, y; 
        inp >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
        
        //ans[i][j] == 1 khi dinh i ke canh j
        ans[x][i] = 1;
        ans[y][i] = 1;
    }
    if(t == 1){
        for(int i = 1; i <= v; i++){
            int cnt = 0;
            for(int j = 1; j <= v; j++){
                if(adj[i][j] == 1){
                    cnt++;
                }
            }
            out << cnt << " ";
        }
    }
    else{
        out << v << " " << e << endl;
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= e; j++){
                out << ans[i][j] << " ";
            }
            out << endl;
        }
    }
}