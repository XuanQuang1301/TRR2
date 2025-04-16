#include <bits/stdc++.h>
using namespace std;
int n; 
vector<vector<int>> adj;
vector<bool> check;
void DFS(int u){
    check[u] = true;
    for(int i : adj[u]){
        if(!check[i]){
            DFS(i);
        }
    }
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");
    inp >> n;
    adj.clear(); adj.resize(n + 5);
    check.clear(); check.resize(n + 5, false);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; inp >> x;
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }
    
    int lt = 0;
    for(int i = 1; i <= n; i++){
        if(!check[i]){
            lt++;
            DFS(i);
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        fill(check.begin(), check.end(), false);
        check[i] = true;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!check[j]){
                DFS(j);
                cnt++;
            }
        }
        if(cnt > lt){
            ans.push_back(i);
        }
    }
    out << ans.size() << endl;
    for(auto i : ans){
        out << i << " ";
    }
    out << endl;
    inp.close(); out.close();
}