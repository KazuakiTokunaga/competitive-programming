// 前処理O(N)
// 文字列 S の区間 [i, j) の部分文字列に関するハッシュ値を O(1) で返す
// https://drken1215.hatenablog.com/entry/2019/09/16/014600


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// ローリングハッシュ
struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<ll> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }
    
    // get hash of S[left:right]（0始まりで右端含まない）
    inline pair<ll, ll> get(int l, int r) const {
        ll res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        ll res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }

    // get lcp of S[a:] and T[b:]（一致する最大の長さ）
    inline int getLCP(int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};



int main() {
    string s = "hogefaelghaelhogeahselhgaoehogehgaoegcvahoge";
    int n = s.size();

    RollingHash rh(s);

    map<pair<ll, ll>, int> cnt;
    int num = 0;

    // 最初の4文字(hoge)が出現している回数をカウントする
    auto p = rh.get(0, 3);
    rep(i, 0, n-2){
        if (p == rh.get(i, i+3)) num++;
    }
    cout << num << endl;
}


