#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //东南西北
    static char str[] = "ESWN";
    static int map[][2] = {
        {3,1},
        {0,2},
        { 1,3 },
        { 2,0 }
    };
    int cur = 3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int lr = 0;
        if (c == 'R')
            lr = 1;
        cur = map[cur][lr];
    }
    cout << str[cur] << endl;
    return 0;
}
////////////
num=int(input())
direction=input()
dictt={0:'N', 1:'E', 2:'S', 3:'W'}
turnn={'L':-1, 'R':1}
init=0
for turn in direction:
    init+=turnn[turn]
init%=4    
print(dictt[init])    
