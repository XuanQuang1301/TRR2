#include <bits/stdc++.h>
using namespace std;
int  adj[101][101];

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
        int ans[100][100];
        int dem = 0;
        for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
              ans[i][j] = 0;
          }
        }
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
