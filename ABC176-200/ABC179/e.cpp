#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    
    ll res = X; N--;
    ll cur = (X * X) % M;
    vector<ll> As = {X};
    
    while (N > 0 and find(all(As), cur) == As.end()){
        As.push_back(cur);
        res += cur; N--;
        cur = (cur * cur) % M;
    }
    // for (auto i: As) {cout << i << ' ';} cout << endl;
    // cout << cur << endl;
    

    int idx = find(all(As), cur) - As.begin();
    int loop_size = As.size() - idx;
    ll loop_sum = accumulate(As.begin() + idx, As.end(), (ll)0);
    ll loop_cnt = (loop_size ? (N / loop_size): 0);
    res += loop_cnt * loop_sum;
    N -= loop_size * loop_cnt;

    // cout << loop_size << " " << loop_cnt << " " << N << endl;
    while (N > 0){
        res += cur;
        cur = (cur * cur) % M;
        N--;
    }
    cout << res << endl;

}