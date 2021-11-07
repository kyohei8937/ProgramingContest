#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1LL << 60;

// 便利関数
// ...繰り返し
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,n,m) for(int i=n;i<m;++i)
#define ALL(x) (x).begin(),(x).end()

// ...比較入れ替え
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//============================================================================
//ここまでテンプレ
//============================================================================

// union by size + path having
class UnionFind {
public:
    vector <int> par; // 各元の親を表す配列
    vector <int> siz; // 素集合のサイズを表す配列(1 で初期化)

    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身ssss
    }

    // Member Function
    // Find
    int root(int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(int x, int y) { // 連結判定
        return root(x) == root(y);
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


#define H_MAX (2000)
#define W_MAX (2000)

int H, W, Q;

UnionFind UF;
int table[H_MAX + 2][W_MAX + 2];

const int dir_r[4] = { 0,1,0,-1 };
const int dir_c[4] = { 1,0,-1,0 };

void query1(int pr,int pc){
	rep(i,4){
		int sr = pr + dir_r[i];
		int sc = pc + dir_c[i];
		if(table[sr][sc] == 0){
			continue;
		}
		int hash1 = (pr-1) * W + (pc - 1);
		int hash2 = (sr-1) * W + (sc - 1);
		UF.merge(hash1,hash2);
	}
	table[pr][pc] = 1; 
}

bool query2(int pr,int pc,int qr,int qc){
	if(table[pr][pc] == 0 || table[qr][qc] == 0){
		return false;
	}
	int hash1 = (pr-1) * W + (pc - 1);
	int hash2 = (qr-1) * W + (qc - 1);	
	return UF.issame(hash1,hash2);
}

signed main() {
	cin >> H >> W;
	cin >> Q;
	UF.init(H*W);
	vector<bool> ansArray;
	rep(i, Q) {
		int type;
		cin >> type;
		if (type == 1) {
			int r, c;
			cin >> r >> c;
			query1(r,c);
		}
		else {
			int ra, ca, rb, cb;
			cin >> ra >> ca >> rb >> cb;
			bool ans = query2(ra,ca,rb,cb);
			ansArray.push_back(ans);
		}
	}
	rep(i, ansArray.size()) {
		if (ansArray[i]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}