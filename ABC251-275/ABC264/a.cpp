#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int L, R;
    cin >> L >> R; L--; R--;

    string s = "atcoder";
    rep(i, L, R+1) cout << s[i];
    cout << endl;
}