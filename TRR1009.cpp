#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n, k;
    int adj[105][105] = {0};
    inp >> t;
    if(t == 1){
        inp >> n >> k;
        for(int i = 0; i < k; i++){
            int x, y; inp >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if(adj[i][j] == 1){
                    cnt++;
                }
            }
            out << cnt << " ";
        }
    }
    else{
        inp >> n;
        for(int i = 1; i <= n; i++){
            int k; inp >> k;
            while(k--){
                int x; inp >> x;
                adj[i][x] = 1;
            }
        }
        int ans[109][109] = {0};
        int dem = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(adj[i][j] == 1){
                    dem++;
                    ans[i][dem] = 1;
                    ans[j][dem] = 1;
                }
            }
        }
        out << n << " " << dem << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= dem; j++){
                out << ans[i][j] << " ";
            }
            out << endl;
        }
    }
    inp.close();
    out.close();
}