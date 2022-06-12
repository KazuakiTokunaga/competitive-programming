#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll n;
    cin >> n;
    
    if (n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }

    ll res = 0;
    while (n >= 5){
        n /= 5;
        res += n / 2;
    }
    cout << res << endl;
}
