#include <bits/stdc++.h>
using namespace std;
int t, n;
int adj[100][100];
void test2(){
    
}
int main(){
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    inp >> t >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; inp >> x;
            if(x == 1){
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    if(t == 1){
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1){
                    cnt++;
                }
            }
            out << cnt << " ";
        }
    }
    else{
        set<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(adj[i][j] == 1){
                    pair<int, int> tmp;
                    tmp.first = i + 1;
                    tmp.second = j + 1;
                    p.insert(tmp);
                }
            }
        }
        out << n << " " << p.size() << endl;
        for(auto i : p){
            out << i.first << " " << i.second << endl;
        }
    }
    inp.close();
    out.close();
}