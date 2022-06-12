#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    int c,d,e;
    c = a+b;
    d = a-b;
    e = a*b;

    cout << max({c,d,e}) << endl;
}