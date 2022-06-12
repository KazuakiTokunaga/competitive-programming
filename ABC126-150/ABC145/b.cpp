#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    if (n % 2 != 0){
        cout << "No" << endl;
    } else {
        if (s.substr(0, n/2) == s.substr(n/2)){
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    };
}