// ソート順を保存するバケット分割

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    const int B = 3; // バケットのサイズ
    vector<int> a_sort(n);

    int bucket_count = ceil((double)n/B);
    vector<vector<int>> bucket(bucket_count);
    rep(i, 0, n){
        bucket[i/B].push_back(a[i]);
        a_sort[i] = a[i];
    }

    sort(all(a_sort));
    rep(i, 0, n/B){
        sort(all(bucket[i]));
    }

    rep(i, 0, m){
        // 蟻本の入力のindexがおかしい？
        // l,rは1始まり（両端含む）で与えられているので[l, r)とするためにはlを1引く
        int l, r, k;
        cin >> l >> r >> k; 
        l--;

        int lb = -1, ub = n-1;

        // 「x以下の数がk個以上あるか」を条件に二分探索
        while (ub - lb > 1){
            int md = (lb + ub) / 2;
            int x = a_sort[md];
            int tl = l, tr = r, c = 0;

            while (tl < tr && tl % B != 0) if (a[tl++] <= x) c++;
            while (tl < tr && tr % B != 0) if (a[--tr] <= x) c++;

            while (tl < tr){
                int b = tl / B;
                c += upper_bound(all(bucket[b]), x) - bucket[b].begin();
                tl += B;
            }

            if (c >= k) {
                cout << "ok: " << x << endl;
                ub = md;
            }
            else {
                cout << "ng: " << x << endl;
                lb = md;
            }
        }

        cout << a_sort[ub] << endl;
    }
}

/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
*/