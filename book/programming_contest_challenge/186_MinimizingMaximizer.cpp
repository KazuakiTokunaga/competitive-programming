#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

template <typename T>
struct RMQ {
    const T INF = pow(10, 9) + 7;
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n+1, pow(10, 9)+7);
    RMQ<int> rmq(n);
    rmq.update(1, 0);
    dp[1] = 0; // 1がいちばん難しいので、1を最後尾に持ってくることができればどの番号でもOK.
    rep(i, 0, m){
        int s, t;
        cin >> s >> t;

        int v = min(dp[t], rmq.query(s, t+1)+1);
        cout << s << " " << t << " " << v << endl;
        dp[t] = v;
        rmq.update(t, v);
    }

    cout << dp[n] << endl;
}

/*
40 6
20 30
1 10
10 20
20 30
15 25
30 40
*/