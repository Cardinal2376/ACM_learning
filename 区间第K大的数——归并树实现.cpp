#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int ST_SIZE = (1 << 18) - 1;
const int MAXN = 1E5 + 5;
const int MAXM = 5005;
int N, M;
int A[MAXN]; // 要处理的数组
int I[MAXM], J[MAXM], K[MAXM]; //存查询

int nums[MAXN]; //对A排序后的数组
vector<int> dat[ST_SIZE]; //线段树节点数组

//构建线段树
// k是节点编号， 和区间[l, r)对应
void init(int k, int l, int r) {
    if (r - l == 1) {
        dat[k].push_back(A[l]);
    } else {
        int lch = k * 2 + 1, rch = 2 * k + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - l); //也不知道有什么用，估计是缩小空间吧
        //利用STL的merge函数把两个儿子的数列合并
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }

}

//计算[i, j)中不超过x的数的个数
//k是节点编号， 和区间[l, r)对应 (一开始 k l r 0 0 N）
int query(int i, int j, int x, int k, int l, int r) {
    if (j <= l || r <= i) {
        //完全不相交
        return 0;
    } else if (i <= l && r <= j) {
        //完全包含
        return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    } else {
        //对儿子们递归计算
        int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
        int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
        return lc + rc;
    }
}

void solve() {
    for(int i = 0; i < N; i++) nums[i] = A[i];
    sort(nums, nums + N);

    init(0, 0, N);

    for (int i = 0; i < M; i++) {
        //[l, r)
        int l = I[i] - 1, r = J[i], k = K[i];

        int lb = -1, ub = N - 1; //(-1, N-1]
        while(ub - lb > 1) {
            int md = (ub + lb) / 2;
            int ans = query(l, r, nums[md], 0, 0, N);
            if (ans >= k) ub = md;
            else lb = md;
        }
        printf("%d\n", nums[ub]);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", I + i, J + i, K + i);
    }
    solve();
    return 0;
}
