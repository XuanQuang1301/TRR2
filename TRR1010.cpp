#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, adj[100][100];
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
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
                if(adj[i][j] != 0 && adj[i][j] != 10000){
                    cnt++;
                }
            }
            out << cnt << " ";
        }
    }
    else{
        vector<pair<int, int>> ve;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(adj[i][j] != 0 && adj[i][j] != 10000){
                    pair<int, int> tmp;
                    tmp.first = i;
                    tmp.second = j;
                    ve.push_back(tmp);
                }
            }
        }
        out << n << " " << ve.size() << endl;
        for(auto i : ve){
            out << i.first << " " << i.second << " " << adj[i.first][i.second] << endl;
        }
    }
    inp.close();
    out.close();
}