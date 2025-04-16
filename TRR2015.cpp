#include <bits/stdc++.h>
using namespace std;
int n; 
vector<vector<int>> adj;
vector<vector<int>> ans;
vector<bool> check;
void DFS(int u, vector<vector<int>> a){
    check[u] = true;
    for(auto i : a[u]){
        if(!check[i]){
            DFS(i, a);
        }
    }
}
int Test1(){
    for(int i = 1; i <= n; i++){
        fill(check.begin(), check.end(), false);
        DFS(i, adj);
        for(int j = 1; j <= n; j++){
            if(!check[j]){
                return 0;
            }
        }
    }
    return 1;
}
int Test2(){
    for(int i = 1; i <= n; i++){
        fill(check.begin(), check.end(), false);
        DFS(i, ans);
        for(int j = 1; j <= n; j++){
            if(!check[j]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");
    cin >> n;
    adj.clear(); adj.resize(n + 1);
    ans.clear(); ans.resize(n + 1);
    check.clear(); check.resize(n + 1, false);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x == 1){
                adj[i].push_back(j);
                ans[i].push_back(j);
                ans[j].push_back(i);
            }
        }
    }
    if(Test1() == 1){
        out << 1 << endl;
    }
    else if(Test2() == 1){
        out << 2 << endl;
    }
    else out << 0 << endl;
    inp.close(); out.close();
}