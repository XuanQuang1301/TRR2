#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n, k, dem = 0, adj[1000][1000] = {0};
    inp >> t >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){
                adj[i][j] = 10000;
            }
            else{
                adj[i][j] = 0;
            }
        }
    }
    while(k--){
        int x, y, z;
        inp >> x >> y >> z;
        adj[x][y] = z;
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            int vao = 0, ra = 0;
            for(int j = 1; j <= n; j++){
                if(adj[i][j] != 0 && adj[i][j] != 10000){
                    ra++;
                }
                if(adj[j][i] != 0 && adj[j][i] != 10000){
                    vao++;
                }
            }
            out << vao << " " << ra << endl;
        }
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
    inp.close();
    out.close();
}