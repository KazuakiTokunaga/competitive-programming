#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int a,b;
    cin >> a >> b;

    if (a >= 13){
        cout << b << endl;
    } else if (a >= 6){
        cout << b /2 << endl;
    } else {
        cout << 0 << endl;
    }
}