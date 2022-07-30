#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    // 平方数を判定
    vector<bool> sq(N+1, false);
    rep(i, 1, N+1){
        if (i*i > N) break;
        sq[i*i] = true;
    }

    // d[j]: jの約数の配列
    vector<vector<int>> d(N+1);
    rep(i, 1, N+1){
        for (int j = i; j <= N; j += i) {
            d[j].push_back(i);
        }
    }

    map<ll, ll> cnt;
    rep(i, 1, N+1){
        ll f = 0;
        for (int j: d[i]) {
            if (sq[j]) f = j; // f = iの約数のうちの最大の平方数
        }
        cnt[i / f]++;
    }

    ll res = 0;
    for (auto& [key, value]: cnt) {
        res += value * value;
    }
    cout << res << endl;
    
}