#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    string res = "";
    rep(i, 0, 6){
        res += s[i % n];
    }
    cout << res << endl;
}