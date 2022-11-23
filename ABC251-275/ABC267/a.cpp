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

    map<string, int> mp;
    mp["Friday"] = 1;
    mp["Thursday"] = 2;
    mp["Wednesday"] = 3;
    mp["Tuesday"] = 4;
    mp["Monday"] = 5;

    cout << mp[s] << endl;
}