#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;

    vector<vector<ll>> cities;
    rep(i, 0, N){
        ll x, y, p;
        cin >> x >> y >> p;
        vector<ll> city = {x, y, p};
        cities.push_back(city);
    }

    vector<vector<pii>> graph(N);
    rep(i, 0, N){
        rep(j, 0, N){
            if (i == j) continue;
            auto city1 = cities[i];
            auto city2 = cities[j];
            ld dist = abs(city1[0] - city2[0]) + abs(city1[1] - city2[1]);
            ll s = ceil(dist / city1[2]);
            graph[i].push_back(make_pair(s, j));
        }
    }


    ll res = 2LL << 60;
    auto c = [](pii l, pii r) { return l.first >= r.first; };
    rep(i, 0, N){
        ll dist = 0;
        priority_queue<pii, vector<pii>, decltype(c)> q(c);

        vector<int> seen(N, 0);
        seen[i] = 1;
        for (pii edge: graph[i]) {
            q.push(edge);
        }
        while (!q.empty()){
            pii edge = q.top(); q.pop();
            ll s; ll j;
            tie(s, j) = edge;

            if (seen[j]) continue;

            seen[j] = 1;
            dist = max(s, dist);
            for (pii next_Edge: graph[j]) {
                q.push(next_Edge);
            }
        }

        res = min(res, dist);
    }
    cout << res << endl;
}