#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 105;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
bool path[MAXN][MAXN];
int f[MAXN];
int cost[MAXN];
int score[MAXN];
int main()
{

    int T;
    cin >> T;
    int cas = 1;
    while(T--) {
        int B, n;
        cin >> B >> n;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", score + i, cost + i);
        }
        fill(f, f + MAXN, 0);
        memset(path, false, sizeof(path));
        for(int i = 1; i <= n; i++) {
            for(int j = B; j >= cost[i]; j--) {
                if(f[j - cost[i]] + score[i] > f[j]) {
                    path[i][j] = true;
                    f[j] = f[j - cost[i]] + score[i];
                }
            }
        }
		/*************
			”√path±Íº«
		*************/
        vector<int> seq;
        int ans = 0;
        for(int i = n, j = B; i >= 0 && j >= 0; i--) {
            if(path[i][j]) {
                seq.push_back(i);
                j -= cost[i];
                ans += cost[i];
            }
        }
		
        printf("Case #%d:\n%d %d\n", cas++, f[B], ans);
        reverse(seq.begin(), seq.end());
        for(int i = 0; i < seq.size(); i++) {
            printf("%d%c", seq[i], i == seq.size() - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
