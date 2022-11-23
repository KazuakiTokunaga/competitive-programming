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

    string res = "";
    rep(i, 0, 10){
        if (N % 2 == 1) res += "1";
        else res += "0";

        N /= 2;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}