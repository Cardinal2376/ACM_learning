#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int B = 1000;
const int MAXN = 1e5 + 5;
const int MAXM = 5005;

int N, M;
int A[MAXN]; // Ҫ���������
int I[MAXM], J[MAXM], K[MAXM]; //���ѯ

int nums[MAXN]; //��A����������
vector<int> bucket[MAXN / B];

void solve() {
    //��ʼ��
    for(int i = 0; i < N; i++) {
        bucket[i / B].push_back(A[i]);
        nums[i] = A[i];
    }
    for(int i = 0; i < N / B; i++) { // Ͱ������
        sort(bucket[i].begin(), bucket[i].end());
    }
    sort(nums, nums + N);

    for (int i = 0; i < M; i++) {
        //������[l, r)�еĵ�k����
        int l = I[i] - 1, r = J[i], k = K[i];

        int lb = -1, ub = N - 1; //�����±�(-1, N-1]
        while(ub - lb > 1) {
            int md = (lb + ub) >> 1;
            int x = nums[md];
            int c = 0, tl = l, tr = r;

            //  ������ಿ��
            while(tl < tr && tl % B != 0) if (A[tl++] <= x) c++; //��Ҳ��֪��Ϊʲô�������ǡ�=
            while(tl < tr && tr % B != 0) if (A[--tr] <= x) c++;

            // Ͱ�ڼ���
            while(tl < tr) {
                c += upper_bound(bucket[tl / B].begin(), bucket[tl / B].end(), x) - bucket[tl / B].begin();//��Ҳ��֪��Ϊʲô��������upper_bound
                tl += B;
            }

            if (c >= k) ub = md;
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
