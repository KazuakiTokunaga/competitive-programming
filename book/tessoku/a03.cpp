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

    vector<int> P(N), Q(N);
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, N) cin >> Q[i];

    for (int i: P) {
        for (int j: Q) {
            if (i+j == K) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
}