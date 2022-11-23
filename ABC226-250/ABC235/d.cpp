#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int a, N;
int res = INF;

int main() {    
    cin >> a >> N;
    
    vector<int> used(1000010, 0);
    queue<pii> q;
    q.push({1, 0});
    
    
    while (!q.empty()){
        auto[x, cnt] = q.front(); q.pop();

        if (used[x]) continue;
        used[x] = 1;

        if (x == N) {res = cnt; break;}

        if ((ll)a*x < 1000000){
            q.push({a*x, cnt+1});
        }

        if (x < 10)  continue;
        string cstr = to_string(x);
        int s = cstr.size();
        if (cstr[s-1] == '0') continue;

        cstr = cstr[s-1] + cstr.substr(0, s-1);
        q.push({stoi(cstr), cnt+1});
    }

    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
}