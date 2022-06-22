#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

/* BIT: 区間和の更新や計算を行う構造体
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(i,x): a_i += x とする
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
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
    
    // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
    int lower_bound(T w) {
    if (w <= 0) {
        return 0;
    } else {
        int x = 0, r = 1;
        while (r < n) r = r << 1;
        for (int len = r; len > 0; len = len >> 1) { // 長さlenは1段下るごとに半分に
            if (x + len < n && bit[x + len] < w) { // 採用するとき
                w -= bit[x + len];
                x += len;
            }
        }
        return x + 1;
    }
}
};

int main() {
    int n = 10;
    vector<int> input = {3,7,3,5,10,7,2,1,8,5};

    BIT<int> tree(n);
    rep(i, 0, n){
        tree.add(i+1, input[i]); // 最初の要素は1
    }
    
    cout << tree.sum(5) << endl; // 10までの和
    cout << tree.lower_bound(30) << endl; // 累積和が30を超える位置
}