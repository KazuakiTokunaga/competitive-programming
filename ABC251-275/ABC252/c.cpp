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
    
    vector<string> slots;
    rep(i, 0, N){
        string s;
        cin >> s;
        slots.push_back(s);
    }

    int res = pow(10, 9) + 7;
    rep(i, 0, 10){
        vector<int> cnt(10, 0);
        rep(j, 0, N){
            rep(k, 0, 10){
                if (int(slots[j][k]-'0') == i) cnt[k]++;
            }
        }

        int m = *max_element(all(cnt));
        int t = 0;
        rep(j, 0, 10){
            if (cnt[j] == m) t = (m-1)*10 + j;
        }
        res = min(res, t);
    }
    cout << res << endl;
}