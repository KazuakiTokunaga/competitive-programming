#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

ll attack(ll i){
    if (i == 1) return 1;
    else return 1 + 2 * attack(i / 2);
}

int main() {
    ll n;
    cin >> n;

    cout << attack(n) << endl;
}