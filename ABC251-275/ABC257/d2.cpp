// ワーシャルフロイド法
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll INF = 2LL << 60;

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

    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    rep(i, 0, N){
        rep(j, 0, N){
            if (i == j) continue;
            auto city1 = cities[i];
            auto city2 = cities[j];
            ld dist = abs(city1[0] - city2[0]) + abs(city1[1] - city2[1]);
            ll s = ceil(dist / city1[2]);
            dp[i][j] = s;
        }
    }

    rep(i, 0, N){
        dp[i][i] = 0;
    }

    rep(k, 0, N){
        rep(i, 0, N){
            rep(j, 0, N){
                dp[i][j] =  min(dp[i][j], max(dp[i][k], dp[k][j]));
            }
        }
    }

    ll res = INF;
    rep(i, 0, N){
        ll max_dist = 0;
        rep(j, 0, N){
            max_dist = max(dp[i][j], max_dist);
        }
        res = min(max_dist, res);
    }

    cout << res << endl;
}