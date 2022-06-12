#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10, 9) + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    
    ll least = (k-1) * k / 2;
    ll greatest = (n + (n - (k-1))) * k / 2;
    
    ll res = 0;
    rep(i, k, n+2){
        res += greatest - least + 1;
        res %= MOD;
        least += i;
        greatest += (n - i);
    }
    cout << res << endl;
}