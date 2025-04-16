#include <bits/stdc++.h>
using namespace std;
int n, m, u, adj[1000][1000] = {0}, bac[1000] = {0};
int main(){
    ifstream inp("CT.INP");
    ofstream out("CT.OUT");
    int t; inp >> t;
    if(t == 1){
        inp >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; inp >> x >> y;
            bac[x]++;
            bac[y]++;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(bac[i] % 2 == 1){
                cnt++;
            }
        }
        if(cnt == 0){
            out << 1 << endl;
        }
        else if(cnt == 2){
            out << 2 << endl;
        }
        else out << 0 << endl;
    }
    else{
        inp >> n >> m >> u;
        for(int i = 0; i < m; i++){
            int x, y; inp >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }
        vector<int> ve;
        stack<int> st;
        st.push(u);
        while(!st.empty()){
            int tmp = st.top();
            for(int i = 1; i <= n; i++){
                if(adj[tmp][i] == 1){
                    adj[tmp][i] = 0;
                    adj[i][tmp] = 0;
                    st.push(i);
                    break;
                }
            }
            if(tmp == st.top()){
                st.pop();
                ve.push_back(tmp);
            }
        }
        for(int i = ve.size() - 1; i >= 0; i--){
            out << ve[i] << " ";
        }
    }
    inp.close(); out.close();
    return 0;
}