#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

string s, t;
vector<int> s_cnt(10, 0);
vector<int> t_cnt(10, 0);
vector<int> remain_cnt(10, 0);
int total;


bool battle(int i, int j){
    vector<int> s_cnt1 = s_cnt;
    vector<int> t_cnt1 = t_cnt;

    s_cnt1[i]++; t_cnt1[j]++;

    int s_score = 0, t_score = 0;
    rep(t, 1, 10){
        s_score += t * pow(10, s_cnt1[t]);
        t_score += t * pow(10, t_cnt1[t]);
    }
    if (s_score > t_score) return true;
    else return false;
}


ld calc_prob(int i, int j){
    vector<int> remain_cnt1 = remain_cnt;
    ld res1 =  ((ld)remain_cnt1[i] / total);
    remain_cnt1[i]--;

    ld res2 = ((ld)remain_cnt1[j] / (total - 1));

    return max(res1*res2, (ld)0);
}


int main() {
    int k;
    cin >> k >> s >> t;

    rep(i, 0, 4){
        s_cnt[int(s[i]-'0')]++;
        t_cnt[int(t[i]-'0')]++;
    }
    
    total = 9 * k - 8;
    rep(i, 1, 10){
        int used = s_cnt[i] + t_cnt[i];
        remain_cnt[i] = k - used;
    }

    ld res = 0;
    rep(i, 1, 10){
        rep(j, 1, 10){
            if (battle(i, j)) {
                res += calc_prob(i, j);
            }
        }
    }

	cout << fixed << setprecision(15);
    cout << res << endl;
}