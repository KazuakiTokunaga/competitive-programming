#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

string s1, s2, s3;

vector<vector<ll>> combinations(vector<ll> lis,ll repeat){
    ll cnt=0;
    deque<set<ll>> d;
    set<ll> s,tmp;
    d.push_back(s);
    while (cnt<repeat){
        deque<set<ll>> d2;
        for(auto itr=d.begin(); itr!=d.end(); itr++){
            for(auto it=lis.begin()+cnt; it!=lis.begin()+lis.size()+cnt-repeat+1 ; it++){
                tmp=*itr;
                tmp.insert(*it);
                if (tmp.size()==cnt+1){
                    d2.push_back(tmp);
                }
            }
        }
        d=d2;
        cnt++;
    }
    sort(d.begin(), d.end());
    decltype(d)::iterator result = unique(d.begin(), d.end());
    d.erase(result, d.end());
    vector<vector<ll>> ans;
    for(auto item:d){
        vector<ll> ite(item.begin(),item.end());
        ans.push_back(ite);
    }
    return ans;
}

void create_dict(map<char, int> &dict, vector<ll> combi, set<char> chars) {
    int id = 0;
    for (char c: chars) {
        dict[c] = combi[id];
        id++;
    }
}

ll convert(string s, map<char, int> &dict){
    ll n = 0;
    rep(i, 0, s.size()){
        if (i == 0 and dict[s[i]] == 0) return 1LL << 60;
        n += dict[s[i]];
        if (i != s.size() - 1) n *= 10;
    }
    return n;
}

vector<ll> calculate(map<char, int> &dict){
    vector<ll> for_false = {0,0,0};

    ll n1 = convert(s1, dict);
    ll n2 = convert(s2, dict);
    ll n3 = convert(s3, dict);

    if (n1 == 1LL << 60) return for_false;
    if (n2 == 1LL << 60) return for_false;
    if (n3 == 1LL << 60) return for_false;

    if (n1 + n2 == n3) return vector<ll>{n1, n2, n3};
    else return for_false;
}

int main() {
    cin >> s1 >> s2 >> s3;
    
    set<char> chars;
    rep(i, 0, s1.size()){
        chars.insert(s1[i]);
    }
    rep(i, 0, s2.size()){
        chars.insert(s2[i]);
    }
    rep(i, 0, s3.size()){
        chars.insert(s3[i]);
    }

    if (chars.size() >= 11) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<ll> integers = {0,1,2,3,4,5,6,7,8,9};
    vector<vector<ll>> candidates = combinations(integers, chars.size());
    rep(i, 0, candidates.size()){
        vector<ll> combi = candidates[i];
        do {
            map<char, int> dict;    

            create_dict(dict, combi, chars);

            vector<ll> res = calculate(dict);
            if (res[0] != 0){

                rep(j, 0, res.size()){
                    cout << res[j] << endl;
                }
                return 0;
            }
        } while (next_permutation(combi.begin(), combi.end()));
    }

    cout << "UNSOLVABLE" << endl;

}