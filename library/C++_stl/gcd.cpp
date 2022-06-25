#include <bits/stdc++.h>
using namespace std;

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

int main() {
    // 例 1: 2 つの整数 a, b を入力し、a と b の最大公約数と最小公倍数を出力する
    int a = 24, b = 60;
    cout << __gcd(a, b) << endl;
    cout << a / __gcd(a, b) * b << endl; // 最小公倍数
    
    // 5x + 13y = gcd(5, 13)の解を求める
    int x, y;
    extgcd(5, 13, x, y);
    cout << x << " " << y << endl;
}