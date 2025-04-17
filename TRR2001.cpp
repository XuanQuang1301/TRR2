#include <bits/stdc++.h>
using namespace std;
int t, n, u, v, train[1000], ok;
vector<bool> check;
vector<vector<int>> adj;

void DFS(int e){
    if(e == v){
      ok = 1;
      return;
    }
    check[e] = true;
    for(auto i : adj[e]){
        if(!check[i]){
            train[i] = e;
            DFS(i);
            if(ok){ return;}
        }
    }
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");

    cin >> t >> n >> u >> v;
    adj.clear(); adj.resize(n + 10);
    check.clear(); check.resize(n + 10, false);
    memset(train, 0, sizeof(train));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
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
        cout << cnt << endl;
    }
    else{
        ok = 0;
        train[u] = 0;
        DFS(u);
        if(ok == 0){
            cout << 0 << endl;
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
                cout << ve[i] << " ";
            }
        }
    }
    inp.close();
    out.close();
}