#include <bits/stdc++.h>
using namespace std;

int v, e, n;
int main(){
    ifstream in("CT.INP");
    ofstream out("CT.OUT");
    int t; in >> t;
    if(t == 1){
        in >> v >> e;
        vector<vector<int>> adj;
        for(int i = 0; i < e; i++){
            int x, y; in >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1; i <= v; i++){
            if(adj[i].size() % 2 == 1){
                cnt++;
            }
        }
        if(cnt == 0){
            out << 1 << endl;
        }
        if(cnt == 2){
            out << 2 << endl;
        }
        else out << 0 << endl;
    }
    else{
        in >> v >> e >> n;
        set<int> adj[1000];
        for(int i = 0; i < e; i++){
            int x, y; in >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        stack<int> st;
        vector<int> ans;
        st.push(n);
        while(!st.empty()){
            int x = st.top();
            if(adj[x].size() != 0){
                int y = *adj[x].begin();
                adj[x].erase(y);
                adj[y].erase(x);
                st.push(y);
            }
            else{
                st.pop();
                ans.push_back(x);
            }
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            out << ans[i] << " ";
        }
        out << endl;
    }
}