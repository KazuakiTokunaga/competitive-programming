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
    
    vector<int> P(N);
    rep(i, 0, N-1) cin >> P[i];
    
    int cur = P[N-2];
    int res = 1;
    while (cur != 1){
        cur = P[cur-2];
        res++;
    }
    cout << res << endl;
}