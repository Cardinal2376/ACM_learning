#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int ST_SIZE = (1 << 18) - 1;
const int MAXN = 1E5 + 5;
const int MAXM = 5005;
int N, M;
int A[MAXN]; // Ҫ���������
int I[MAXM], J[MAXM], K[MAXM]; //���ѯ

int nums[MAXN]; //��A����������
vector<int> dat[ST_SIZE]; //�߶����ڵ�����

//�����߶���
// k�ǽڵ��ţ� ������[l, r)��Ӧ
void init(int k, int l, int r) {
    if (r - l == 1) {
        dat[k].push_back(A[l]);
    } else {
        int lch = k * 2 + 1, rch = 2 * k + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - l); //Ҳ��֪����ʲô�ã���������С�ռ��
        //����STL��merge�������������ӵ����кϲ�
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }

}

//����[i, j)�в�����x�����ĸ���
//k�ǽڵ��ţ� ������[l, r)��Ӧ (һ��ʼ k l r 0 0 N��
int query(int i, int j, int x, int k, int l, int r) {
    if (j <= l || r <= i) {
        //��ȫ���ཻ
        return 0;
    } else if (i <= l && r <= j) {
        //��ȫ����
        return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    } else {
        //�Զ����ǵݹ����
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
