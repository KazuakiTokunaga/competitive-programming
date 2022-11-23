// BITの応用。転倒数を求める典型

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

template <typename T>
struct BIT {
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) { // i&-1はiの最後の1のビットを表す(p.144)
            bit[idx] += x;
        }
    }

    T sum(int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    BIT<int> bit(10000);
    ll ans = 0;
    rep(j, 0, n){
        ans += j - bit.sum(a[j]);
        bit.add(a[j], 1);
    }
    cout << ans << endl;
}

/*
4
3 1 4 2
*/