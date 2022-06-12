#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10,9) + 7;


// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#8-modint
int main() {
    ll a = pow(7, 11);

    rep(i,0,100){
        a *= 2;
        a %= MOD;
        if (i % 10 == 0){
            cout << a << " ";
        }
    }
    cout << endl;
}