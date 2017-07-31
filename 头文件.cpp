#include <iostream>
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <cctype>
#include <climits>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <functional>
/*int类型最大值INT_MAX，short最大值为SHORT_MAX
long long最大值为LONG_LONG_MAX*/
//cout << "OK" << endl;
#define _clr(x,y) memset(x,y,sizeof(x))
#define _inf(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define mp make_pair
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double EULER = 0.577215664901532860;
const double PI = 3.1415926535897932384626;
const double E = 2.71828182845904523536028;

typedef long long LL;