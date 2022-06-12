#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<pii> laggage;
    rep(i, 0, n){
        int w, v;
        cin >> w >> v;
        laggage.push_back(make_pair(w,v));
    }
    sort(laggage.begin(), laggage.end());
    reverse(laggage.begin(), laggage.end());

    vector<int> boxes(m);
    rep(i, 0, m) cin >> boxes[i];

    rep(i, 0, q){
        int l, r;
        cin >> l >> r;

        vector<int> usable;
        rep(i, 0, m){
            if (i < (l-1) or i > (r-1)) usable.push_back(boxes[i]);
        }
        sort(usable.begin(), usable.end());

        int res = 0;
        priority_queue<int, vector<int>> q;
        vector<pii> cur_laggage = laggage;
        rep(j, 0, usable.size()){
            int s = usable[j];
            while (!cur_laggage.empty()){
                int w, v;
                tie(w, v) = cur_laggage.back();
                if (w > s) break;
                else {
                    q.push(v);
                    cur_laggage.pop_back();
                }
            }
            if (!q.empty()){
                res += q.top(); 
                q.pop();
            }
        }

        cout << res << endl;
    }
}