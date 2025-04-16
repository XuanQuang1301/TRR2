#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> components;

void BFS(int start) {
    queue<int> q;
    vector<int> component;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        component.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Sắp xếp thành phần liên thông theo thứ tự tăng
    sort(component.begin(), component.end());
    components.push_back(component);
}

int main() {
    ifstream inp("TK.INP");
    ofstream out("TK.OUT");

    inp >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    // Đọc ma trận kề
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            inp >> x;
            if (x == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }

    // Tìm các thành phần liên thông bằng BFS
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            BFS(i);
        }
    }

    // Ghi kết quả
    out << components.size() << endl;
    for (const auto& comp : components) {
        for (int node : comp) {
            out << node << " ";
        }
        out << endl;
    }

    inp.close();
    out.close();

    return 0;
}
