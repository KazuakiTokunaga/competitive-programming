#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define CMAX 1010
ll memo[CMAX][CMAX];
int noinit = 1;
ll C(ll a, ll b) {
	if (noinit) {
		rep(i, 0, CMAX) rep(j, 0, CMAX) memo[i][j] = -1;
		noinit = 0;
	}
	if (b == 0 || a == b) return 1;
	if (0 <= memo[a][b]) return memo[a][b];
	return memo[a][b] = C(a - 1, b - 1) + C(a - 1, b);
}


int main() {
    int a, b; ll k;
    cin >> a >> b >> k;

    int t = a + b;

    ll cnt = 0;
    int cur_b = b;
    int cur_t = t;
    vector<int> bs;
    while (k > cnt){
        rep(i, cur_b, cur_t+1){
            ll per = C(i-1, cur_b-1);
            if (cnt + per >= k) {
                bs.push_back(i);
                cur_t = i-1;
                cur_b -= 1;
                if (cnt + per == k) cnt = k;
                break;
            } else {
                cnt += per;
            }
        }
    }

    while (bs.size() < b){
        int last = bs.back();
        bs.push_back(last-1);
    }

    // for (auto i: bs) {cout << i << ' ';} cout << endl;

    string res = "";
    int id = 1;
    while (true){
        int bc;
        if (!bs.empty()) {bc = bs.back(); bs.pop_back();}
        else bc = t+1;
        while (id < bc){
            res += "a";
            id++;
        }
        if (id >= t+1) break;
        else {
            res += "b";
            id++;
        }
    }
    reverse(res.begin(), res.end());

    cout << res << endl;

}