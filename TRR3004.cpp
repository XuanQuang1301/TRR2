#include <bits/stdc++.h>
using namespace std;
vector<bool> check;
int n, u;
int main(){
    ifstream inp("CT.INP");
    ofstream out("CT.OUT");
    int t; cin >> t;
    if(t == 1){
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x; cin >> x;
                if(x == 1){
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += (adj[i].size() % 2);
        }
        if(cnt == 0) cout << 1;
        else if(cnt == 2) cout << 2;
        else cout << 0;
    }
    else{
        cin >> n >> u;
        set<int> adj[100];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                if(x == 1){
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }
        vector<int> ans;
        stack<int> st;
        st.push(u);
        while(!st.empty()){
            int x = st.top();
            if(adj[x].size() != 0){
                int y = *adj[x].begin();
                st.push(y);
                adj[x].erase(y);
                adj[y].erase(x);
            }
            else{
                st.pop();
                ans.push_back(x);
            }
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
    }
}