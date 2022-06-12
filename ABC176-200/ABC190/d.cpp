#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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
    ll n;
    cin >> n;

    ll res = 0;
    vector<ll> divisors = enum_divisors(2*n);
    for (ll i: divisors) {
         ll d = 2 * n / i;
         if (i % 2 == 1 and d % 2 == 0) res++;
         if (i % 2 == 0 and d % 2 == 1) res++; 
    }
    
    cout << res << endl;
}