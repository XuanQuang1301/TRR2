#include <bits/stdc++.h>
using namespace std;
int n; 
vector<vector<int>> adj;
vector<bool> check;
void BFS(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front(); q.pop();
        check[x] = true;
        for(auto i : adj[x]){
            if(!check[i]){
                check[i] = true;
                q.push(i);
            }
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
            BFS(i);
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        fill(check.begin(), check.end(), false);
        check[i] = true;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!check[j]){
                BFS(j);
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