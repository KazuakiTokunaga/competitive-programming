#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
     cout << fixed << setprecision(10);
    const long double pi = M_PI;

    int a,b,x;
    cin >> a >> b >> x;
    
    if ((long double)a*a*b*0.5 < x){
        long double theta = atan(((long double)a * a * a / 2 / ((a*a*b) - x)));
        cout << 90 - (theta / pi * 180) << endl;
    } else {
        long double theta = atan((long double)x / b / b / a * 2);
        cout << 90 - (theta / pi * 180) << endl;
    }
}