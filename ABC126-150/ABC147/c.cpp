#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> t(n);
    rep(i, 0, n){
        int a;
        cin >> a;
        rep(j, 0, a){
            int x, y;
            cin >> x >> y;
            t[i].push_back({x, y});
        }
    }

    int res = 0;
    for (int bit=0; bit < (1 << n); bit++){
        int count = 0;
        vector<int> seen(n, -1);
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (bit & 1 << i){
                if (seen[i] == 0){
                    flag = false;
                } else {
                    seen[i] = 1;
                    count++;
                    for (auto p: t[i]) {
                        if (seen[p.first-1] == -1){
                            seen[p.first-1] = p.second;
                        } else {
                            if (seen[p.first-1] != p.second){
                                flag = false;
                            }
                        }
                    }
                }
            } else {
                if (seen[i] == 1){
                    flag = false;
                } else {
                    seen[i] = 0;
                }
            }
        }

        if (flag){
            // cout << "true bit: " << bit << " " << count << endl;
            res = max(res, count);
        }
    }

    cout << res << endl;
}