#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int main() {
    int N;
    cin >> N;
    
    vector<pii> ppl;
    rep(i, 0, N){
        int x, y;
        cin >> x >> y;
        ppl.push_back({x, y});
    }

    string s;
    cin >> s;

    map<int, pii> memo;
    rep(i, 0, N){
        int x, y;
        tie(x, y) = ppl[i];

        char dir = s[i];
        if (memo.count(y)){
            if (dir == 'R') if (x < memo[y].first) {cout << "Yes" << endl; return 0;}
            if (dir == 'L') if (x > memo[y].second) {cout << "Yes" << endl; return 0;}
        } else {
            memo[y] = {-1 * INF, INF};
        }

        if (dir == 'R') {
            memo[y].second = min(memo[y].second, x);
        } else {
            memo[y].first = max(memo[y].first, x);
         }
    }

    cout << "No" << endl;
}