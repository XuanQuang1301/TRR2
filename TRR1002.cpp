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
        out << n << endl;
        for(int i = 0; i < n; i++){
            set<int> s;
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1){
                    s.insert(j + 1);
                }
            }
            out << s.size() << " ";
            for(auto i : s){
                out << i << " ";
            }
            out << endl;
        }
    }
    inp.close();
    out.close();
}