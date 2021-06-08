#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
 
void print(vector < int > &sub){
    int len = sub.size();
    for(int i = 0; i < len; i++){
        if(i == len-1) cout << sub[i] << endl;
        else cout << sub[i] << ' ';
    }
    return;
}

void allsubsets(vector < int > &set, vector < int > &sub, int n, int index){
    if(index == n){
        print(sub);
        return;
    }
    sub.pb(set[index]);
    allsubsets(set, sub, n, index+1);
    sub.pop_back();
    allsubsets(set, sub, n, index+1);
}
 
int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
 
    int n;
    cin >> n;
    vector < int > set;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        set.pb(value);
    }
    vector < int > sub;
    allsubsets(set, sub, n, 0);
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}