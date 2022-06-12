#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<vector<int>> count(10, vector<int>(10, 0));
    rep(i, 1, n+1){
        int bottom = i % 10;
        int top = -1, x = i;
        while (0 < x){
            top = x % 10;
            x /= 10;
        }

        count[top][bottom]++;
    }

    ll ans = 0;
    rep(i, 0, 10){
        rep(j, 0, 10){
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << endl;
}