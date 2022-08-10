#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N), B(N), C(M), D(M);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, M) cin >> C[i];
    rep(i, 0, M) cin >> D[i];
    
    vector<pii> Chocolates;
    rep(i, 0, N) Chocolates.push_back({A[i], B[i]});
    sort(all(Chocolates), greater<pii>());

    vector<pii> Boxes;
    rep(i, 0, M) Boxes.push_back({C[i], D[i]});
    sort(all(Boxes));

    multiset<int> Available;
    rep(i, 0, N){
        int a, b;
        tie(a, b) = Chocolates[i];

        while (!Boxes.empty()){
            int c, d;
            tie(c, d) = Boxes.back();
            if (c >= a) {
                Available.insert(d); // 縦はOKなものを追加していく
                Boxes.pop_back();
            }
            else break;
        }

        // bを超える最小の要素であるような箱を使う
        auto iter = Available.lower_bound(b);

        if (iter == Available.end()){
            cout << "No" << endl;
            return 0;
        } else {
            Available.erase(iter);
        }
    }

    cout << "Yes" << endl;
}