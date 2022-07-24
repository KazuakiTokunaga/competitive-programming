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

    vector<int> res(N+1, -2);
    map<int, int> place;
    vector<int> next_num(N+1, -1);
    rep(i, 0, N){
        int p; 
        cin >> p;

        auto itr = place.lower_bound(p);
        if (itr == place.end()) place[p]++;
        else {
            int bf = itr->first;
            next_num[p] = bf;
            int cnt = itr->second; cnt++;
            // cout << "key,cnt: " << p << " " << cnt << endl;
            place.erase(bf);
            place[p] = cnt;
        }

        if (place[p] == K){
            int cur = p;
            while (cur != -1){
                res[cur] = i;
                cur = next_num[cur];
            }
            place.erase(p);
        }
        // cout << i << " " << p << ": ";
        // for (auto& [key, value]: place) {cout << key << ' ';} cout << endl;
    }

    rep(i, 1, N+1){
        cout << res[i]+1 << endl;
    }
}