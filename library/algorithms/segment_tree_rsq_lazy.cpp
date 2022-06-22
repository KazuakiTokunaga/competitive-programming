#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

/* RSQ：[0,n-1] について、区間ごとの和を管理する構造体
    add(a,b,x): 区間[a,b) の要素に x を加算。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RSQ {
    int n;
    vector<T> dat, lazy;
    RSQ(int n_) : n(), dat(n_ * 4, 0), lazy(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
    }

    /* lazy eval */
    void eval(int k) {
        if (!lazy[k]) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] += lazy[k] / 2;
            lazy[k * 2 + 2] += lazy[k] / 2;
        }
        // 自身を更新
        dat[k] += lazy[k];
        lazy[k] = 0;
    }

    void add(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] += x * (r-l);
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
        }
    }
    void add(int a, int b, T x) { add(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return 0;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main() {
    int n = 10;
    vector<int> input = {1,5,3,6,8,10,7,2,5,3};
    RSQ<int> rsq(n);

    rep(i, 0, n){
        rsq.set(i, input[i]);
    }
    rsq.build();

    cout << rsq.query(0, 4) << endl;
    rsq.add(2, 5, 7); // [2,5)に7を加える

    rep(i, 0, n){
        cout << rsq.query(i,i+1) << " ";
    }
    cout << endl;
    cout << rsq.query(1, 4) << endl;
}