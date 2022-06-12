#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int maxi = a.back();

    vector<int> invalid(maxi+10, 0);
    vector<int> cnt(maxi+10, 0);
    int res = 0; 
    rep(i, 0, n){
        int cur = a[i];
        
        if (invalid[cur] == 0 and cnt[cur] == 1){
            res--;
            cnt[cur]++;
            continue;
        } else if (cnt[cur] > 1){
            continue;
        }
        cnt[cur]++;

        if (invalid[cur] == 0) res++;

        int t = cur;
        while (true){
            t += cur;
            if (t > maxi) break;
            invalid[t] = 1;
        }
    }

    cout << res << endl;
}