#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using ld = long double;

vector<int> A;
int N, K;
bool check(int l) {
    if (l == 0) return false;

    ll cnt = 0;
    rep(i, 0, N){
        int a = A[i];
        cnt += ceil((ld)a / l) - 1;
        if (cnt > K) return false;
    }
    return true;

}

int main() {
    cin >> N >> K;
    
    rep(i, 0, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int left = 0, right = pow(10, 9) + 7;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(mid)) {
            right = mid;
        }
        else {
            left = mid;
        }
    } 

    cout << right << endl;
}