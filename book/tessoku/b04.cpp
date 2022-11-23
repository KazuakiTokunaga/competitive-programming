#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string N;
    cin >> N;
    reverse(all(N));

    int res = 0;
    rep(i, 0, N.size()){
        int s = int(N[i]-'0');
        res += s * (1<<i);
    }
    cout << res << endl;
}