#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, adj[100][100], dem = 0;
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    inp >> t >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            inp >> adj[i][j];
            if(adj[i][j] == 1){
                dem++;
            }
        }
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
            set<int> s;
            for(int j = 1; j <= n; j++){
                if(adj[i][j] == 1){
                    s.insert(j);
                }
            }
            out << s.size() << " ";
            for(auto i : s){
                out << i << " ";
            }
            out << endl;
        }
    }
}
