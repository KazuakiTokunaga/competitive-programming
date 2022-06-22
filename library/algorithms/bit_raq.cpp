#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

/* BIT: RAQ対応BIT
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

int main() {
    int n = 10;
    vector<int> input = {3,7,3,5,10,7,2,1,8,5};

    BIT<int> tree(n);
    rep(i, 0, n){
        tree.add(i+1, i+2, input[i]); // 最初の要素は1
    }
    cout << tree.sum(5) << endl; // 10までの和

    tree.add(4, 6, 3);
    cout << tree.sum(5) << endl;

}