#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int res = 0;
int dfs(int cur, int must, int possible) {
    if (cur == 5 and must != 0) return 0; 
    if (cur == 5) return 1;
    return must * dfs(cur+1, must-1, possible+1) + possible * dfs(cur+1, must, possible);
}

int main() {
    string s;
    cin >> s;

    vector<int> cnt(3, 0);
    rep(i, 0, 10){
        if (s[i] == 'o') cnt[0]++;
        if (s[i] == 'x') cnt[1]++;
        if (s[i] == '?') cnt[2]++;
    }

    cout << dfs(1, cnt[0], cnt[2]) << endl;
}