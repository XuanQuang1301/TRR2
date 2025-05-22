#include <bits/stdc++.h>
using namespace std;
int adj[1000][1000];
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n, m; 
    inp >> t >> n >> m; 
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                adj[i][j] = 0;
            }
            else adj[i][j] = 10000;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, z; 
        inp >> x >> y >> z;
        adj[x][y] = z;
        adj[y][x] = z;
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if(adj[i][j] > 0 && adj[i][j] <= 50){
                    cnt++;
                }
            }
            out << cnt << " ";
        }
        out << endl;
    }
    else{
        out << n << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                out << adj[i][j] << " ";
            }
            out << endl;
        }
    }
    inp.close(); out.close();
}