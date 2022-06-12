#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 素因数分解
vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

// 約数列挙
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}


int main() {
    auto res = prime_factorize(600);
    for (auto p: res) {
        cout << p.first << " " << p.second << endl;
    }

    vector<ll> divisors = enum_divisors(600);
    for (auto i: divisors) {cout << i << ' ';} cout << endl;
    
}