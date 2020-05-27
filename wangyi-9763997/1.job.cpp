#include <bits/stdc++.h>
using namespace std;
//代码写的有点绕，基本思想就是将工作和能力都排序，然后都从小开始遍历
//复杂度max(NlogN,MlogM,N+M)
int main()
{
    int N, M; 
    cin >> N >> M;
    vector<pair<int, int>> job(N);
    for (int i = 0; i < N; i++)
    {
        cin >> job[i].first >> job[i].second;
    }
    vector<pair<int,int>> friends(M);
    vector<int> earn(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> friends[i].first; // ability
        friends[i].second = i; // second i is position index memo. and first i will be used point as indexfriend
    }
    //sort list python can auto
    sort(friends.begin(), friends.end(), [&](pair<int, int> &e1, pair<int, int>& e2) {return e1.first < e2.first; });
    sort(job.begin(), job.end(), [&](pair<int, int> &e1, pair<int, int>& e2) {return e1.first < e2.first; });
    int indexFriend = 0;
    int indexJob = 0;
    int preEarn = 0;
    while (indexFriend < M && indexJob < N)
    {
        if (friends[indexFriend].first < job[indexJob].first)
            indexFriend++; // curr person incapable ability, next person
        else if (indexJob == N-1 || friends[indexFriend].first < job[indexJob + 1].first) {
            // cpp = = support
            preEarn = earn[friends[indexFriend].second] = max(preEarn, job[indexJob].second);
            indexFriend++;  // no remain job, or curr person incapable nextjob, so curr person is over pass.
            // earn is wanted, 
            // 9 ability< 10 difficulty.
            // earn(0)=1000=preearn
            // indexf=1, next person, still curr job
        }
        else {
            preEarn = max(preEarn, job[indexJob].second);
            indexJob++; // job iter
        }
    }
    for (int i = 0; i < M; i++)
    {
        cout << earn[i] << endl; // last line is blank , still ok
    }
    return 0;
}

//////////////
// python
def main():
    # import io
    # instr="""3 3 
    # 1 100 
    # 10 1000 
    # 1000000000 1001 
    # 9 10 1000000000"""
    # f=io.StringIO(instr)
    import sys
    f=sys.stdin
    
    job=[] # list([list],) like vector<pair<>>
    if f is '': return
     #maybe just oj's error, not exact standard input, may have a blank line,
#or write it again with cpp.
    ff=[line for line in list(f) if line.strip()]
    for num, line in enumerate(ff,1):
#    for num, line in enumerate(f,1):        
        if num==1:
            N, M=map(int, line.split())
        elif num==N+2: # not else if
            # friend=list(map(int,line.split()))
            friends=map(int,line.split())
            friend=list(zip(friends, range(M)))
        else:
            job.append(list(map(int, line.split())))
    friend.sort(); job.sort() 
    pfriend=0; pjob=0; preearn=0; earn=[0]*M
    while pfriend<M and pjob<N:
        if friend[pfriend][0]< job[pjob][0]:
            pfriend+=1
        # elif friend[pfriend][0]< job[pjob+1][0] || pjob==N-1:     
        elif pjob==N-1 or friend[pfriend][0]< job[pjob+1][0]:  
            # short circuit, pjob first.
            preearn=earn[friend[pfriend][1]]=max(preearn, job[pjob][1])
            pfriend+=1
        else:
            preearn=max(preearn, job[pjob][1])
            pjob+=1 
    for _ in earn:
        print(_)
main()        
