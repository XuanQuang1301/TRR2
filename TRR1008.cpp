#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("DT.INP");
    ofstream out("DT.OUT");
    int t, n;
    inp >> t >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int k;
        inp >> k;
        for (int j = 0; j < k; j++) {
            int v;
            inp >> v;
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
            out << degree << " ";
        }
    } else if (t == 2) {
        set<pair<int, int>> s;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if(adj[i][j] == 1){
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    s.insert(p);
                }
            }
        }
        out << n << " " << s.size() << endl;
        for(auto i : s){
            out << i.first << " " << i.second << endl;
        }
    }

    inp.close();
    out.close();
    return 0;
}