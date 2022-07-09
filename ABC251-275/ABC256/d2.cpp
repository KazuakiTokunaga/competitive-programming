#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()


constexpr int INF = 1e9 + 6;
 
set<pair<int,int>> st;
 
void insert(int l,int r) {
    auto itl = st.upper_bound({l,INF}), itr = st.upper_bound({r,INF});
    if (itl != st.begin() && (--itl)->second < l) itl++;
    if (itl != itr) {
        l = min(l , itl->first);
        r = max(r, prev(itr)->second);
        st.erase(itl,itr);
    }
    st.insert({l,r});
}
 
int main() {
    int n;cin >> n;
    for (int i = 0; i < n; i++) {
        int l,r;cin >> l >> r;
        insert(l,r);
    }
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}