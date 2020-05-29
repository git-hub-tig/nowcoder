#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> alarm;
    while (N--)
    {
        int Hi, Mi;
        cin >> Hi >> Mi;
        alarm.push_back(Hi * 60 + Mi);
    }
    int X;
    cin >> X;
    int hi,mi, ClassTime;
    cin >> hi>>mi;
    ClassTime = hi * 60 + mi - X;
    sort(alarm.begin(), alarm.end(), greater<int>());
    auto it = lower_bound(alarm.begin(), alarm.end(), ClassTime, greater<int>());
    cout << *it / 60 << " " << *it % 60 << endl;
    return 0;
}
//

from bisect import bisect, bisect_left
n=int(input())
times=[]
for _ in range(n):
    tim=list(map(int, input().split()))
    time=tim[0]*60+tim[1]
    times.append(time)
times.sort()
cost=int(input())

end=list(map(int, input().split()))
ending=end[0]*60+end[1]

#  5 6 7
i=bisect(times,ending-cost) # i is 2, cuz [lo,i] is val<=x
# i=bisect_left(times,ending-cost) # i is 1, cuz [i, hi] is val>=x
#  left something wrong like 6.02< 6.30< 6.37. need 6.02
target=times[i-1]
# target=times[i]
print(target//60,target%60) # python3 / is real float
