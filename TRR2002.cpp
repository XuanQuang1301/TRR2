#include <bits/stdc++.h>
using namespace std;
int t, n, u, v, train[1000], ok;
vector<bool> check;
vector<vector<int>> adj;
void BFS(int e){
    queue<int> q;
    q.push(e);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == v){
            ok = 1;
            return;
        }
        check[x] = true;
        for(int i : adj[x]){
            if(!check[i]){
                check[i] = true;
                train[i] = x;
                q.push(i);
            }
        }
    }
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");

    inp >> t >> n >> u >> v;
    adj.clear(); adj.resize(n + 10);
    check.clear(); check.resize(n + 10, false);
    memset(train, 0, sizeof(train));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; inp >> x;
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }

    if(t == 1){
        int cnt = 0;
        check[u] = true;
        for(auto i : adj[u]){
            if(!check[i] && i != v){
                check[i] = true;
                for(auto j : adj[i]){
                    if(j == v){
                        cnt++;
                        break;
                    }
                }
            }
        }
        out << cnt << endl;
    }

    else{
        ok = 0;
        train[u] = 0;
        check.assign(n + 10, false);
        BFS(u);
        if(ok == 0 || u == v){
            out << 0 << endl;
        }
        else{
            vector<int> ve;
            ve.push_back(v);
            int tmp = v;
            while(train[tmp] != 0){
                ve.push_back(train[tmp]);
                tmp = train[tmp];
            }
            for(int i = ve.size() - 1; i >= 0; i--){
                out << ve[i] << " ";
            }
        }
    }
    inp.close();
    out.close();
}