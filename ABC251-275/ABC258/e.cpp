#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, Q, X;
    cin >> N >> Q >> X;
    vector<int> W(2 * N);
    rep(i, 0, N){
        cin >> W[i];
        W[i + N] = W[i];
    }
    const ll all = accumulate(begin(W), begin(W) + N, 0ll);
    vector<int> count(N, (X / all) * N);
    X %= all;
    int r = 0, s = 0;
    rep(l, 0, N){
        if (r < l) {
            r = l;
            s = 0;
        }
        while (s < X) {
            s += W[r];
            r += 1;
        }
        count[l] += r - l;
        s -= W[l];
    }
    vector<int> order(N, -1), path;
    int loop = -1;
    int u = 0;
    rep(k, 0, N){
         if (order[u] != -1) {
            loop = k - order[u];
            break;
        }
        order[u] = k;
        path.push_back(u);
        u = (u + count[u]) % N;   
    }
    const int non_loop = (int)path.size() - loop;
    while (Q--) {
        ll k;
        cin >> k;
        k -= 1;
        if (k < non_loop) {
            cout << count[path[k]] << '\n';
        } else {
            k = (k - non_loop) % loop;
            cout << count[path[non_loop + k]] << '\n';
        }
    }
    return 0;
}