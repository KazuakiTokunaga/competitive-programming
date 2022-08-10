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

    vector<vector<int>> cnt(N+1);
    rep(i, 0, N){
        int a;
        cin >> a;

        int k = i+1;
        cnt[a].emplace_back(k);
    }

    int Q;
    cin >> Q;
    vector<int> vec;
    rep(i, 0, Q){
        int l, r, x;
        cin >> l >> r >> x;
        
        vec = cnt[x];
        cout << upper_bound(all(vec), r) - lower_bound(all(vec), l) << endl;
    }
    

}