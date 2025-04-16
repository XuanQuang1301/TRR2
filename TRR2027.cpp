#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> check;
vector<pair<int, int>>  ans;
set<pair<int, int>> canh;
int n;
void DFS(int u){
    check[u] = true;
    for(auto i : adj[u]){
        if(!check[i]){
            DFS(i);
        }
    }
}
void DFS2(int u, int t, int s){
    check[u] = true;
    for(auto i : adj[u]){
        if((u == s && i == t ) ||(u == t && i == s)) {
            continue;
        }
        if(!check[i]){
            DFS2(i, t, s);
        }
    }
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");
    inp >> n;
    adj.clear(); adj.resize(n + 10);
    check.clear(); check.resize(n + 10, false);
    ans.clear(); canh.clear();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tmp; inp >> tmp;
            if(tmp == 1){
                adj[i].push_back(j);
                int x = min(i, j), y = max(i, j);
                canh.insert({x, y});
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
    for(auto it : canh){
        int x = it.first, y = it.second;
        fill(check.begin(), check.end(), false);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!check[i]){
                DFS2(i, x, y);
                cnt++;
            }
        }
        if(cnt > lt){
            ans.push_back(it);
        }
    }
    out << ans.size() << endl;
    for(auto i : ans){
       out << i.first << " " << i.second << endl;
    }
}