#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 100000 + 5;
typedef long long LL;
int bit[MAXN + 1], a[MAXN + 1], b[MAXN + 1], n; //[1, n]

int sum(int i) {
    int s = 0;
    while(i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while(i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}



int main()
{

    //freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++) {
        cin >> n;
        fill(bit, bit + n + 1, 0);
        printf("Case #%d: ", k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            add(a[i], 1);
            b[a[i]] = i + a[i] - 1 - sum(a[i] - 1) - min(i, a[i]);
        }
        for(int i = 1; i <= n; i++) {
            printf("%d%c", b[i], (i == n ? '\n' : ' '));
        }
    }

    return 0;
}
