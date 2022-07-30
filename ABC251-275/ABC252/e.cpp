#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pip = pair<ll, pii>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pip>> graph(N);
    map<pii, int> getId;
    rep(i, 0, M){
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        graph[a].push_back({c, {b,a}});
        graph[b].push_back({c, {a,b}});
        getId[{a,b}] = i+1;
        getId[{b,a}] = i+1;
    }

    priority_queue<pip, vector<pip>, greater<pip>> q;
    vector<int> used(N, 0);
    vector<int> roads;
    
    for (pip p: graph[0]) q.push(p);
    used[0] = 1;

    int idx = 0;
    while (!q.empty()) {
        pip p = q.top(); q.pop();
        if (used[p.second.first]) continue;

        roads.push_back(getId[p.second]);
        used[p.second.first] = 1;

        // cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        // if (++idx >= 100) break;

        for (pip nxt: graph[p.second.first]) {
            if (used[nxt.second.first]) continue;

            q.push({p.first + nxt.first, {nxt.second.first, p.second.first}});
        }
    }

    for (auto i: roads) {cout << i << ' ';} cout << endl;
}