#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

template <typename T>
struct SegTree {
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    SegTree(int n_) : n(), dat(n_ * 4, 0) { // 葉の数は 2^x の形
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
            dat[i] = dat[i * 2 + 1] | dat[i * 2 + 2];
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return 0;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl | vr;
        }
    }
};

int main() {
    int n, Q; string s;
    cin >> n >> s >> Q;
    SegTree<int> st(n);

    rep(i, 0, n){
        int c = s[i] - 'a';
        st.update(i, 1 << c);
    }

    rep(i, 0, Q){
        int q; cin >> q;
        if (q == 1){
            int iq; char cq;
            cin >> iq >> cq;
            int c = cq - 'a';
            st.update(iq-1, 1 << c);
        } else {
            int l, r;
            cin >> l >> r;
            int cnt = st.query(l-1, r);
            
            int res = 0;
            rep(j, 0, 26){
                if (cnt & (1 << j)) res++;
            }
            cout << res << endl;
        }
    }
}