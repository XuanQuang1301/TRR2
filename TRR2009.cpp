#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> check;
vector<int> tmp;
vector<vector<int>> ans;
void DFS(int u){
    tmp.push_back(u);
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
    int n; inp >> n;
    adj.clear(); adj.resize(n + 10);
    check.clear(); check.resize(n + 10, false);
    ans.clear();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; inp >> x;
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            tmp.clear();
            DFS(i);
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
    }
    out << ans.size() << endl;
    for(const auto &i : ans){
        for(auto j : i){
            out << j << " ";
        }
        out << endl;
    }
    inp.close();
    out.close();
}