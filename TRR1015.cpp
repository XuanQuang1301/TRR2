#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, k, adj[100][100] = {0}, dem = 0;
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    inp >> t >> n >> k;
    while(k--){
        int x, y; 
        inp >> x >> y;
        adj[x][y] = 1;
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            int vao = 0, ra = 0;
            for(int j = 1; j <= n; j++){
                if(adj[i][j] == 1){
                    ra++;
                }
                if(adj[j][i] == 1){
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