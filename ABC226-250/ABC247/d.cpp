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

    deque<pii> balls;
    rep(i, 0, N){
        int q;
        cin >> q;

        if (q == 1){
            int x, c;
            cin >> x >> c;
            
            balls.push_back({x, c});
        } else if (q == 2){
            int c;
            cin >> c;

            int cnt = 0;
            ll res = 0;
            while (cnt < c){
                pii p = balls.front(); balls.pop_front();
                if (p.second + cnt <= c){
                    res += (ll)p.first * p.second;
                    cnt += p.second;
                } else {
                    res += (ll)p.first * (c-cnt);
                    p.second -= (c - cnt);
                    
                    cnt = c;
                    balls.push_front({p.first, p.second});
                }
            }
            cout << res << endl;
        }
    }
}