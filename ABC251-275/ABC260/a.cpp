#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string S;
    cin >> S;

    map<char, int> m;
    rep(i, 0, S.size()){
        m[S[i]]++;
    }
    
    bool found = false;
    for (auto& [key, value]: m) {
        if (!found and value == 1) {
            cout << key << endl;
            found = true;
        }
    }
    if (!found) cout << -1 << endl;
}