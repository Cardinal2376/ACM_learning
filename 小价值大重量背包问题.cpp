#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
const int MAXN = 1005, MAXV = 1000005;
int f[MAXV];
int v[MAXN];
int w[MAXN];
const int INF = 0x3f3f3f3f;
int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, V;
        cin >> n >> V;
        fill(f, f + MAXV, INF);
        f[0] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", v + i);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", w + i);
        }
        for(int i = 0; i < n; i++) {
            for(int j = MAXV - 1; j >= v[i] ; j--) {
                f[j] = min(f[j], f[j - v[i]] + w[i]);
            }
        }
        int ans = -1;
        for(int i = MAXV - 1; i >= 0; i--) {
            if (f[i] <= V) {
                ans = i;
                break;
            }
        }
        if (ans != -1)
            printf("%d\n", ans);
        else
            printf("No solution\n");
    }
	return 0;
}
