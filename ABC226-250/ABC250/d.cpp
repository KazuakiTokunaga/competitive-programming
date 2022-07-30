#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 1 は予めふるい落としておく
    isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
    ll N;
    cin >> N;

    vector<bool> isprime = Eratosthenes(1001000);
    
    vector<ll> primes;
    vector<ll> primespowers;
    rep(i, 2, isprime.size()){
        if (isprime[i]) primes.push_back(i);
        if (isprime[i]) primespowers.push_back((ll)i*i*i);
    }
    
    ll cnt = 0;
    rep(i, 0, primes.size()){
        ll p = primes[i];
        ll q = N / p;
        ll base = upper_bound(all(primespowers), q) - primespowers.begin();
        cnt += max(base - (i+1), (ll)0);
    }
    cout << cnt << endl;
}