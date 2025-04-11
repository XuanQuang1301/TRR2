#include <bits/stdc++.h>
using namespace std;
int t, v, e;
int adj[100][100];
void test2(){
    
}
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    inp >> t >> v, e;
    for(int i = 0; i < e; i++){
        int x, y;
        inp >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
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
        out << v << endl;
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++){
                out << adj[i][j] << " ";
            }
            out << endl;
        }
    }
    inp.close();
    out.close();
}