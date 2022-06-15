#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int a,b,w;
    cin >> a >> b >> w;
    
    int w1 = w * 1000;
    double lower = (double)w1 / b;
    double upper = (double)w1 / a;

    int mini = ceil(lower);
    int maxi = floor(upper);

    if (mini <= upper and maxi >= lower) cout << mini << " " << maxi << endl;
    else if (mini <= upper) cout << mini << " " << mini << endl;
    else if (maxi >= lower) cout << maxi << " " << maxi << endl;
    else cout << "UNSATISFIABLE" << endl;
}