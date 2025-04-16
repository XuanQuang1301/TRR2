#include <bits/stdc++.h>
using namespace std;
int n, u, a[1005][1005];
int main(){
    ifstream inp("CT.INP");
    ofstream out("CT.OUT");
    int t; inp >> t;
    if(t == 1){
        inp >> n;
        vector<vector<int>> adj(n + 1, vector<int> (n + 1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x; inp >> x;
                if(x == 1){
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += (adj[i].size() % 2);
        }
        if(cnt == 0) out << 1;
        else if(cnt == 2) out << 2;
        else out << 0;
    }
    else{
        inp >> n >> u;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                inp >> a[i][j];
            }
        }
        stack<int> st; vector<int> ans;
        st.push(u);
        while(!st.empty()){
            int x = st.top();
            for(int i = 1; i <= n; i++){
                if(a[x][i] == 1){
                    a[x][i] = 0;
                    a[i][x] = 0;
                    st.push(i);
                    break;
                }
                
            }
            if(x == st.top()){
                st.pop();
                ans.push_back(x);
            }
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            out << ans[i] << " ";
        }
    }
    inp.close(); out.close();
    return 0;
}