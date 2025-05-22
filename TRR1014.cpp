#include <bits/stdc++.h>
using namespace std;
int adj[1000][1000], ans[1000][1000];
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n; 
    inp >> t >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            inp >> adj[i][j];
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            int ra = 0, vao = 0;
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
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] == 1){
                    cnt++;
                    ans[i][cnt] = 1;
                    ans[j][cnt] = -1;
                }
            }
        }
        out << n << " " << cnt << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= cnt; j++){
                out << ans[i][j] << " ";
            }
            out << endl;
        }
    }
}