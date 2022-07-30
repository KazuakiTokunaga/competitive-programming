#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// 前処理
template <typename T>
vector<T> smallest_prime_factor(T n) {
    vector<T> spf(n + 1);
    for (T i = 0; i <= n; i++) spf[i] = i;
    for (T i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (T j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    return spf;
}

// クエリ
template <typename T>
map<T, T> prime_factolization(T x, vector<T> &spf) {
    map<T, T> mp;
    while (x != 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
  
    return mp;
}

int main() {
    int N;
    cin >> N;

    int max = N;
    auto spf = smallest_prime_factor(N);

    vector<ll> v;
    rep(i, 1, N+1){
        v.push_back((ll)i*i);
    }

    ll res = 0;
    rep(i, 1, N+1){
        ll base = 1;
        auto p_fact = prime_factolization(i, spf);  
        for (auto p: p_fact) {
            if (p.second % 2 == 1) base *= p.first;
        }

        ll m = N / base;
        int idx = upper_bound(all(v), m) - v.begin();
        res += idx;
    }

    cout << res << endl;
}