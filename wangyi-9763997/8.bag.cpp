#include <bits/stdc++.h>
using namespace std;
 
long long n, w;
vector<long long> good;
long long result = 0;
 
void dfs(int cur, long long sum)
{
    if (sum <= w && cur == n)
        result++;
    if (cur == n || sum > w)
        return;
    dfs(cur + 1, sum + good[cur]);
    dfs(cur + 1, sum);// 2^30=1024^3=10^6
}
int main() {
    cin >> n >> w;
    good.resize(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> good[i];
        sum += good[i];
    }
    if (sum <= w) {
        //全部都可以放入
        result = pow(2, n);
    }
    else {
        dfs(0, 0);
    }
    cout << result << endl;
    return 0;
}
//////

n, bag=map(int, input().split())
snack=list(map(int, input().split()))
# snack.sort()
def dfs(cur, summ):
    global res # should first line?
    if cur==n and summ<=bag: # short circuit, cnt just choice judge num, not choose obj index.
        res+=1 # write need global
    if cur==n or summ>bag:
        return
    cur+=1
    dfs(cur, summ)
    dfs(cur, summ+snack[cur-1])
res=0
if sum(snack)<=bag:
    res=pow(2,n)
'''
need if
运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
case通过率为80.00%
'''    
else: dfs(0,0)
print(res)

    
