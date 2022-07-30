#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    int Q;
    cin >> Q;
    
    map<int, int> cnt;
    int maxi = pow(10, 9)+7, mini = -1;
    rep(i, 0, Q){
        int q;
        cin >> q;

        if (q == 1){
            int x;
            cin >> x;
            cnt[x]++;
        } else if (q == 2){
            int x, c;
            cin >> x >> c;
            if (cnt[x] <= c) cnt.erase(x);
            else cnt[x] -= c;
        } else {
            cout << (--cnt.end())->first - cnt.begin()->first << endl;
        }
    }
}