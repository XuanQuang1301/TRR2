#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int t, n;
    cin >> t >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[i][v] = 1;
            adj[v][i] = 1;
        }
    }
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            int degree = 0;
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] == 1) {
                    degree++;
                }
            }
            cout << degree << " ";
        }
    } else if (t == 2) {
        set<pair<int, int>> s;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if(adj[i][j] == 1){
                    s.insert({i, j});
                }
            }
        }
        cout << n << " " << s.size() << endl;
        vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
        int cnt = 1;
        for(auto i : s){
            ans[i.first][cnt] = 1;
            ans[i.second][cnt] = 1;
            cnt++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= s.size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}