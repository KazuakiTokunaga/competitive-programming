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

    vector<vector<int>> M(200100, vector<int>(2, 0));
    map<int, int> p_map; int idx = 1;
    map<vector<int>, int> Map;
    vector<vector<pii>> ms(N);
    rep(i, 0, N){
        int m;
        cin >> m;
        rep(j, 0, m){
            int p, e;
            cin >> p >> e;

            // pをidxに変換する
            if (!p_map[p]) {
                p_map[p] = idx;
                p = idx;
                idx++;
            } else {
                p = p_map[p];
            }

            // 復元するため
            ms[i].push_back({p,e});

            // 最大の値と2番目の値をセット
            if (e > M[p][0]) {
                swap(M[p][0], M[p][1]);
                M[p][0] = e;
            } else if (e > M[p][1]){
                M[p][1] = e;
            }
        }
    }

    ll res = 0;
    rep(i, 0, N){
        vector<int> diff;
        for (pii pe: ms[i]) {
            int p, e;
            tie(p, e) = pe;
            if (e == M[p][0]){
                if (e != M[p][1]) diff.push_back(p);
            }
        }
        
        if (Map[diff]) continue;
        else {res++; Map[diff]++;}
    }

    cout << res << endl;
}