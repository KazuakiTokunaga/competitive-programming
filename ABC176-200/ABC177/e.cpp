#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<int> A(1000100, 0);

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
    int maxi = pow(10, 6)+10;
    auto spf = smallest_prime_factor(maxi);

    int n;
    cin >> n;
    
    rep(i, 1, n+1){
        int a;
        cin >> a;
        auto p_fact = prime_factolization(a, spf);
        for (auto p: p_fact) {
            A[p.first]++;
        }
    }

    int cnt = 0;
    rep(i, 2, A.size()){
        cnt = max(cnt, A[i]);
    }
 
    if (cnt == n) cout << "not coprime" << endl;
    else if (cnt >= 2) cout << "setwise coprime" << endl;
    else cout << "pairwise coprime" << endl;
 }