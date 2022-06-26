#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

template <typename T>
struct RMQ {
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
    int n, q;
    cin >> n >> q;

    vector<pii> Infants(n+1); // 幼稚園児データ
    RMQ<int> rmq(200100); // レート最大値のリスト
    vector<multiset<int>> Gardens(200100, multiset<int>());
    
    rep(i, 0, n){
        int a, b; 
        cin >> a >> b; b--;

        Infants[i] = make_pair(a,b);
        Gardens[b].insert(a);
    }
    rep(i, 0, 200100){
        if (!Gardens[i].size()) continue;
        int maxi = *--Gardens[i].end();
        rmq.update(i, maxi);
    }

    rep(i, 0, q){
        int c, d; 
        cin >> c >> d; c--; d--;

        int a,b;
        tie(a,b) = Infants[c];

        // 以前の園のデータを更新
        Gardens[b].erase(a); 
        if (!Gardens[b].size()) rmq.update(b, INF);
        else {
            int m0 = *--Gardens[b].end();
            rmq.update(b, m0);
        }

        // 新しい園のデータを更新
        Gardens[d].insert(a);
        int m1 = *--Gardens[d].end();
        rmq.update(d, m1);

        // 園児の所属を更新
        Infants[c] = make_pair(a, d);

        // 最小値を取得
        int res = rmq.query(0, 200100);
        cout << res << endl;
    }

}