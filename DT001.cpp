#include <bits/stdc++.h>
using namespace std;
int n;
int adj[100][100];
void inp(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            if(x == 1){
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
}
void test1(){
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(adj[i][j] == 1){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}
void test2(){
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(adj[i][j] == 1){
                pair<int, int> tmp;
                tmp.first = i + 1;
                tmp.second = j + 1;
                p.push_back(tmp);
            }
        }
    }
    cout << n << " " << p.size() << endl;
    for(auto i : p){
        cout << i.first << " " << i.second << endl;
    }
}
int main(){
    int t; cin >> t;
    inp();
    if(t == 1){
        test1();
    }
    else test2();
    cout << endl;
}