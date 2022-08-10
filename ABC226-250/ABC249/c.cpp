#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<string> S;
    rep(i, 0, N){
        string s;
        cin >> s;
        S.push_back(s);
    }

    int res = 0;
    rep(bit, 0, 1<<N){

        vector<int> cnt(30, 0);
        rep(i, 0, N){
            if (bit & (1 << i)){
                for (char s: S[i]) {
                    cnt[s-'a']++;
                }
            }
        }

        int kinds = 0;
        rep(i, 0, cnt.size()){
            if (cnt[i] == K) kinds++;
        }

        res = max(res, kinds);
    }

    cout << res << endl;
}