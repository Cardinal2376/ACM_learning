#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

//用二维vector表示矩阵
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;

const int N = 2;
const int MOD = 10000;
int m;

mat mul (mat& A, mat& B) {
    mat C(A.size(), vec(B[0].size()));
    for(int k = 0; k < B.size(); ++k) {
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B[0].size(); ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

mat pow (mat& A, LL k) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); ++i)
        B[i][i] = 1;    //初始化为单位矩阵

    while(k > 0) {
        if (k & 1) B = mul(B, A);
        A = mul(A, A);
        k >>= 1;
    }

    return B;
}

int main()
{
    int k, a[10];
    while(cin >> k >> m) {
        for(int i = 0; i < 10; i++) {
            scanf("%d", &a[i]);
        }
        mat T(10, vec(10));
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if (i == 0) T[i][j] = a[j];
                else T[i][j] = i == j + 1;
            }
        }
        mat I(10, vec(1));
        for(int i = 0; i < 10; i++) {
            I[i][0] = 9 - i;
        }
        if (k >= 10) {
            T = pow(T, k - 9);
            I = mul(T, I);
            printf("%d\n", I[0][0]);
        } else {
            printf("%d\n", k % m);
        }
    }
    return 0;
}
