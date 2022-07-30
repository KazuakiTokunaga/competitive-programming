#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ll C(ll a, ll b) {
    ll res = 1;
    rep(i, 0, b){
        res *= (a-i);
    }
    rrep(i, b, 1){
        res /= i;  
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> cnt(200100, 0);
    rep(i, 0, N){
        int A; 
        cin >> A;
        cnt[A]++;
    }

    ll base = C(N, 3);
    rep(i, 0, 200100){
        if (cnt[i] >= 2) base -= C(cnt[i], 2) * (N - cnt[i]);
        if (cnt[i] >= 3) base -= C(cnt[i], 3);
    }
    cout << base << endl;
}