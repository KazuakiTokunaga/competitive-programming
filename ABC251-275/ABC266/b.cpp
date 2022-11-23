#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N;
    cin >> N;

    ll res = N % 998244353;
    if (res < 0) res = 998244353 + res;
    cout << res << endl;
}