#include <bits/stdc++.h>
using namespace std;
int t, n, u, v, train[1000], ok;
vector<bool> check;
vector<vector<int>> adj;
void BFS(int e){
    queue<int> q;
    q.push(e);
    check[e] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == v){
            ok = 1;
            return;
        }
        for(auto i : adj[x]){
            if(!check[i]){
                check[i] = true;
                q.push(i);
                train[i] = x;
            }
        }
    }
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");

    inp >> t >> n >> u >> v;
    adj.clear(); adj.resize(n + 5);
    check.clear(); check.resize(n + 5, false);
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
        BFS(u);
        if(ok == 0){
            out << 0;
        }
        else if(u == v){
            out << u;
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
        out << endl;
    }
    inp.close();
    out.close();
}