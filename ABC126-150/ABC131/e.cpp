#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// 単純なcombinationの計算
#define CMAX 110
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
    int n, k;
    cin >> n >> k;

    int max = C(n-1, 2);
    int cnt = max - k;

    if (cnt < 0) {cout << -1 << endl; return 0;}
    if (n == 2 and k == 0){
        cout << 1 << endl; cout << 1 << " " << 2 << endl;
        return 0;
    } else if (n == 2 and k == 1){
        cout << -1 << endl;
        return 0;
    }

    cout << n-1 + cnt << endl;
    rep(i, 2, n+1){
        cout << 1 << " " << i << endl;
    }

    int draw = 0;
    rep(i, 2, n){
        rep(j, i+1, n+1){
            if (draw == cnt) return 0;
            cout << i << " " << j << endl;
            draw++;
        }
    }
}