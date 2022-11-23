#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    cin >> s;

    string t = "atcoder";
    int cnt = 0;
    rep(i, 0, t.size()){
        char c = t[i];
        int cur = i;
        while (true){
            if (s[cur] == c) break;
            cur++;
        }
        while (cur != i){
            swap(s[cur], s[cur-1]);
            cur--;
            cnt++;
        }
    }
    cout << cnt << endl;
}