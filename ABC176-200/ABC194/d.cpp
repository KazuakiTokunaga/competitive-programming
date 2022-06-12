#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int n;
vector<ld> e(n+1);

int main() {
    cin >> n;

    ld res = 0;
    rep(i, 1, n){
        res += (ld) n / (n-i);
    }
	cout << fixed << setprecision(15);
    cout << res << endl;

}