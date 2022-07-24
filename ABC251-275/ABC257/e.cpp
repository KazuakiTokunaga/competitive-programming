#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;

    vector<int> C(9);
    rep(i, 0, 9) cin >> C[i];
    
    int min_c = pow(10, 9) + 7;
    int min_c_idx = 10;
    rrep(i, 8, 0){
        if (C[i] < min_c) {
            min_c_idx = i;
            min_c = C[i];
        }
    }
    int cnt = N / min_c;

    int R = N - min_c * cnt;
    rep(i, 0, 9){
        C[i] -= min_c;
    }

    // cout << "R: " << R << endl;
    // cout << "min_c_idx: " << min_c_idx << endl;
    // for (auto i: C) {cout << i << ' ';} cout << endl;

    string res = "";
    while (true){
        bool update = false;
        rrep(i, 8, min_c_idx+1){
            if (R >= C[i]){
                res += to_string(i+1);
                R -= C[i];
                update = true;
                break;
            }
        }
        if (!update) break;
    }

    int r_cnt = cnt - res.size();
    rep(i, 0, r_cnt){
        res += to_string(min_c_idx+1);
    }
    if (res == "") res = "0";
    cout << res << endl;
}