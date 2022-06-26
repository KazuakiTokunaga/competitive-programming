// https://sen-comp.hatenablog.com/entry/2020/01/16/174230
// 全てのiについて、文字列全体とi文字目以降の部分文字列が、何文字まで一致するかをO(S)で出力する

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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
    string S = "abcabcabbcabbabbccabcabcccbba";
    vector<int> lcp = Z_algorithm(S);
    
    for (auto i: lcp) {cout << i << ' ';} cout << endl;
}

