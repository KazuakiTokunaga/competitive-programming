#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    
    ll a_cnt = N / A;
    ll b_cnt = N / B;

    ll lcm = A / __gcd(A,B) * B;
    ll lcm_cnt = N / lcm;

    ll a_sum = (1+a_cnt) * a_cnt / 2 * A;
    ll b_sum= (1+b_cnt) * b_cnt / 2 * B;
    ll lcm_sum = (1+lcm_cnt) * lcm_cnt / 2 * lcm;
    ll N_sum = (1+N) * N  / 2;

    cout << N_sum - (a_sum + b_sum - lcm_sum) << endl;
}