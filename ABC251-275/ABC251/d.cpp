#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int W;
    cin >> W;
    
    vector<int> res;
    rep(i, 1, 101){
        res.push_back(i);
        res.push_back(i*100);
        res.push_back(i*10000);
    }

    cout << res.size() << endl;
    for (auto i: res) {cout << i << ' ';} cout << endl;
}