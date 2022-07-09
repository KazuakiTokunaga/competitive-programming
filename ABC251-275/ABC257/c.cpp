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
    
    string S;
    cin >> S;
    
    vector<int> W(N);
    rep(i, 0, N) cin >> W[i];
    
    vector<int> Adults;
    vector<int> Children;
    vector<int> Borders = {0};
    rep(i, 0, N){
        if (S[i] == '1') {
            Adults.push_back(W[i]);
            Borders.push_back(W[i]);
        }
        else {
            Borders.push_back(W[i]+1);
            Children.push_back(W[i]);
        }
    }

    sort(all(Children));
    sort(all(Adults));
    sort(all(Borders));
    
    int res = 0;

    for (int border: Borders) {

        int idx = lower_bound(all(Children), border) - Children.begin();
        int cnt = idx;

        int idx2 = lower_bound(all(Adults), border) - Adults.begin();
        cnt += Adults.size() - idx2;
        res = max(cnt, res);
    }

    cout << res << endl;
}