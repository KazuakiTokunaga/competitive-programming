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
    
    vector<pii> intervals;
    rep(i, 0, N){
        int l, r;
        cin >> l >> r;
        intervals.push_back(make_pair(l, r));
    }

    sort(all(intervals));
    
    int idx = 0;
    while (idx < N){
        pii p = intervals[idx];
        int s, e;
        tie(s, e) = p;

        while (true){
            idx++;

            // この場合は区間を確定させて次に進む
            if (idx >= N or intervals[idx].first > e) {
                cout << s << " " << e << endl;
                break;
            }

            // この場合はeを入れ替える
            if (intervals[idx].second > e) {
                e = intervals[idx].second;
            };
        }
    }

}