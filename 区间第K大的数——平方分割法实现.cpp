#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int B = 1000;
const int MAXN = 1e5 + 5;
const int MAXM = 5005;

int N, M;
int A[MAXN]; // 要处理的数组
int I[MAXM], J[MAXM], K[MAXM]; //存查询

int nums[MAXN]; //对A排序后的数组
vector<int> bucket[MAXN / B];

void solve() {
    //初始化
    for(int i = 0; i < N; i++) {
        bucket[i / B].push_back(A[i]);
        nums[i] = A[i];
    }
    for(int i = 0; i < N / B; i++) { // 桶内排序
        sort(bucket[i].begin(), bucket[i].end());
    }
    sort(nums, nums + N);

    for (int i = 0; i < M; i++) {
        //求区间[l, r)中的第k个数
        int l = I[i] - 1, r = J[i], k = K[i];

        int lb = -1, ub = N - 1; //二分下标(-1, N-1]
        while(ub - lb > 1) {
            int md = (lb + ub) >> 1;
            int x = nums[md];
            int c = 0, tl = l, tr = r;

            //  区间多余部分
            while(tl < tr && tl % B != 0) if (A[tl++] <= x) c++; //我也不知道为什么反正就是《=
            while(tl < tr && tr % B != 0) if (A[--tr] <= x) c++;

            // 桶内计算
            while(tl < tr) {
                c += upper_bound(bucket[tl / B].begin(), bucket[tl / B].end(), x) - bucket[tl / B].begin();//我也不知道为什么反正就是upper_bound
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
