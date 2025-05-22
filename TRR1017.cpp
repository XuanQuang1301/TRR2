#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000], vao[1000], ra[1000];
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n, m; 
    inp >> t >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; inp >> x >> y;
        vao[y]++;
        ra[x]++;
        ans[x][i] = 1;
        ans[y][i] = -1;
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            out << vao[i] << " " << ra[i] << endl;
        }
    }
    else{
        out << n << " " << m << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                out << ans[i][j] << " ";
            }
            out << endl;
        }
    }
}