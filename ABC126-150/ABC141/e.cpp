#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

vector<int> Z_algorithm(string S) {
	int c = 0, n = S.size();
	vector<int> Z(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		if (i + Z[l] < c + Z[c]) {
			Z[i] = Z[l];
		} else {
			int j = max(0, c + Z[c] - i);
			while (i + j < n && S[j] == S[i + j])j++;
			Z[i] = j;
			c = i;
		}
	}

	Z[0] = n;
	return Z;
}

int main() {
    int n; string s;
    cin >> n >> s;

    int res = 0;
    rep(i, 0, n){
        string t = s.substr(i);
        vector<int> lcp = Z_algorithm(t);
        rep(j, 0, lcp.size()){
            int len = min(j, lcp[j]);
            res = max(len, res);
        }
    }

    cout << res << endl;
}


// いろいろな解き方
// https://drken1215.hatenablog.com/entry/2019/09/16/014600