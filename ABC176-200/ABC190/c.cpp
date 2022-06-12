#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pii> conditions;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;

        conditions.push_back({a, b});
    }

    int k, res = 0;
    cin >> k;
    vector<pii> people;

    rep(i, 0, k){
        int c, d;
        cin >> c >> d;

        people.push_back({c,d});
    }

    for (int bit=0; bit < (1 << k); bit++){
        vector<int> dishes(n+1, 0);
        int success = 0;

        for (int i = 0; i < k; i++) {
            int a, b;
            tie(a,b) = people[i];
            
            if (bit & 1 << i) dishes[a]++;
            else dishes[b]++;
        }

        rep(i, 0, m){
            int a, b;
            tie(a, b) = conditions[i];
            if (dishes[a] and dishes[b]) success++;
        }
        res = max(res, success);
    }

    cout << res << endl;

}