#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];
    
    a.push_back(0);
    a.push_back(n+1);
    sort(a.begin(), a.end());

    int min_range = pow(10, 9) + 7;
    rep(i, 0, a.size() - 1){
        int range = a[i+1] - a[i];
        if (range > 1) min_range = min(min_range, range);
    }

    int res = 0;
    int stamp = min_range - 1;
    rep(i, 0, a.size() - 1){
        int range = a[i+1] - a[i];
        if (range == 1) continue;
        else res += ceil((double)(range - 1) / stamp);
    }

    cout << res << endl;

}