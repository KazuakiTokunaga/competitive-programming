// エラトステネスの篩っぽく

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

    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(all(A));
    
    int res = 0;
    vector<int> is_valid(1000010, 1);
    rep(i, 0, N){
        int a = A[i];
        if (!is_valid[a]) continue;
        if (i == N-1 or a != A[i+1]) res++;

        while (a < 1000010){
            is_valid[a] = 0;
            a += A[i];
        }
    }

    cout << res << endl;
}