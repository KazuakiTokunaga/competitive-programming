#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()


// 最小公倍数
int __lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

// ax + by = gcd(a, b)の解(x,y)を求める
int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if (b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

// 法mでのaの逆元を求める（mが素数でなくても良い）
ll inv(ll a, ll m) {
    int x, y;
    extgcd(a, m, x, y);
    return x;
}

// Ax == B (mod M)となる最小のxを求める
int mod_equation(int a, int b, int MOD){
    int d = gcd(__gcd(a, b), MOD);
    a /= d;
    b /= d;
    MOD /= d;
    
    if (__gcd(a, MOD) != 1) return -1;
    else return inv(a, MOD) * b;
}


int main() {
    // 例 1: 2 つの整数 a, b を入力し、a と b の最大公約数と最小公倍数を出力する
    int a = 24, b = 60;
    cout << __gcd(a, b) << endl;
    cout << __lcm(a, b) << endl; // 最小公倍数
    
    // 5x + 13y = gcd(5, 13)の解を求める
    int x, y;
    extgcd(5, 13, x, y);
    cout << x << " " << y << endl;

    // 24x == 60 (MOD 162) となる最小のxを求める
    int m = 162;
    cout << mod_equation(a, b, m) << endl;
}