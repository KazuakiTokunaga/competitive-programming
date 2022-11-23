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
    
    int cnt = 0;
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            int k = K - i - j;
            if (k > 0 and k <= N) cnt++;
        }
    }
    cout << cnt << endl;
}