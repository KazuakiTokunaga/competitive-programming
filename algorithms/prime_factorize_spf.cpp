#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// 前処理O(NlogN), クエリO(logN)で求められる素因数分解
// https://qiita.com/ganyariya/items/fba261ee53a5b6decc47
// https://ateruimashin.com/diary/2020/09/spf_factorization/

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
    int max = pow(10, 7);
    auto spf = smallest_prime_factor(max);

    vector<int> n = {300,1000,6000,10000};
    for (int i: n) {
        auto p_fact = prime_factolization(i, spf);   
        for (auto p: p_fact) {
            cout << p.first << "^" << p.second << " ";
        }
        cout << endl;
    }
 }