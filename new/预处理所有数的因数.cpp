//预处理所有数的因数表
//SPEED: ECNUOJ 1E6 5000MS O(nlogn)
const int N = 100000 + 5;
vector<int > factor[N];
void init(){
    for(int i = 2; i < N; i ++){ 
        for(int j = i; j < N; j += i){
            factor[j].push_back(i); 
        }
    }
}

//预处理质因数表
vector<int> x[N];  
bool is[N];  
void prime() {  
    memset(is, false, sizeof(is));  
    for (int i=0; i<N; i++) x[i].clear();  
  
    for (int j=2; j<N; j+=2) x[j].push_back(2);  
    for (int i=3; i<N; i+=2)  
        if (!is[i]) {  
            for (int j=i; j<N; j+=i) {  
                is[j] = true;  
                x[j].push_back(i);  
            }  
        }  
}  