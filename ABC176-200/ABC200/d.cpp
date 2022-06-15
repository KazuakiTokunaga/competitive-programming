#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    int s = min(n, 9);
    vector<vector<int>> rs(200, vector<int>());

    rep(bit, 1, 1<<s){
        ll sum = 0;
        rep(i, 0, s){
            if (bit & 1 << i){
                sum += a[i];
            }
        }
        int r = sum % 200;

        if (rs[r].size() != 0) {

            int first = rs[r][0];
            vector<int> b, c;
            rep(i, 0, s){
                if (first & 1 << i){
                    b.push_back(i);
                }
                if (bit & 1 << i){
                    c.push_back(i);
                }
            }

            cout << "Yes" << endl;
            cout << b.size() << " ";
            for (auto i: b) {cout << i+1 << ' ';} cout << endl;
            cout << c.size() << " ";
            for (auto i: c) {cout << i+1 << ' ';} cout << endl;

            return 0;
        }

        rs[r].push_back(bit);
    }

    cout << "No" << endl;
}