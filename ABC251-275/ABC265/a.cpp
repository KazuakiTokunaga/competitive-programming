#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    
    int a = Y * (N / 3) + X * (N % 3);
    int b = X * N;
    cout << min(a, b) << endl;
}