#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;
const int MAXN = 25;
const int N = 25;
LL D[MAXN];
LL C[MAXN][MAXN];
void dp() {
    D[1] = 0;
    D[2] = 1;
    for(int i = 3; i < 25; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
    }
}

LL combination() {
    C[1][0] = C[1][1] = 1;
	for (int i = 2; i < N; i++){
		C[i][0] = 1;
		for (int j = 1; j < N; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
	}
}

void solve(int N, int M) {
    printf("%I64d\n", C[N][M] * D[M]);
}

int main()
{
    dp();
    combination();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        solve(x, y);
    }
    return 0;
}
