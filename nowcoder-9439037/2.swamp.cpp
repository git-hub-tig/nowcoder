#include<bits/stdc++.h>

using namespace std;

struct Arc
{
	int b, e;
	int cost;
};

int main()
{
	//求最小生成树即可
	int N, M;
	cin >> N >> M;
	vector<Arc> data(M);
	//树的集合
	vector<vector<int>> tree(N);
	for (int i = 0; i < M; i++)
	{
		cin >> data[i].b >> data[i].e >> data[i].cost;
	}
	for (int i = 0; i < N; i++)
	{
		tree[i].push_back(i + 1); 
	}
	// kruskal sort edge, start shortest.
	sort(data.begin(), data.end(), [](Arc& c1, Arc& c2) {return c1.cost < c2.cost; });
	int longestWood = 0;
	for (int i = 0; i < M; i++) // edges
	{
		int b = data[i].b;
		int e = data[i].e;
		int bIndex = -1;
		int eIndex = -1;
		for (int i = 0; i < N; i++) // vertex traverl
		{
			if (find(tree[i].begin(),tree[i].end(),b) != tree[i].end())
			{
				bIndex = i;
			}
			if (find(tree[i].begin(), tree[i].end(), e) != tree[i].end())
			{
				eIndex = i;
			}
		}
		if (bIndex == eIndex) // same vertex, in sameset.
		{
			//已经在同一个集合中
			continue; 
		}
		tree[bIndex].insert(tree[bIndex].end(), tree[eIndex].begin(), tree[eIndex].end());
		tree[eIndex].clear();
		longestWood = max(longestWood, data[i].cost);
	}
	cout << longestWood << endl;
	return 0;
}
///////
// above is kruskal with no unionfind,  no isSameset no unionset.
// below is prim with priority_queue.

import io
from heapq import heappush, heappop
import sys
def process(u, taken, AL, pq):                      # set u as taken and enqueue neighbors of u
    taken[u] = 1 # set visited
    for v, w in AL[u]:
        if (not taken[v]):
            heappush(pq, (w, v))                    # sort by (inc) weight
                                                    # then by (inc) id, if same weight or cost.    
def main():
    instr="""4 3
1 2 1
2 3 1
3 4 2""" 
    # mark from 1 not 0. so AL need N+1, also pq process start call
    # from 1
    # f=sys.stdin
    f=io.StringIO(instr)
    # f = open("kruskal_prim_in.txt", "r")
    V, E = map(int, f.readline().split())
    V+=1
    # Kruskal's algorithm merged with Prim's algorithm
    # only can not []*3, but can [some]*n 
    AL = [[] for _ in range(V)]                     # the graph stored in AL
    EL = []
    for _ in range(E):
        # u, v, w = map(int, f.readline().split(" ")) # read as (u, v, w)
        u, v, w = map(int, f.readline().split()) # read as (u, v, w)
        EL.append((w, u, v))                        # reorder as (w, u, v)
        # for sort 
        AL[u].append((v, w))
        AL[v].append((u, w))
    EL.sort()                                       # sort by w, O(E log E)
    
    # taken = [0 for i in range(V)]                   # to avoid cycle, no vertex is taken, just visited
    taken = [0]*V                # to avoid cycle, no vertex is taken
    pq = []                                         # to select shorter edges
    process(1, taken, AL, pq)                       # take+process vertex 0
    mst_cost = 0                                    # no edge has been taken
    #  also can get as max_edge of mst.
    num_taken = 0
    # while len(pq) > 0 and num_taken < V-1:          # until we take V-1 edges
    while pq and num_taken < V-1:          # until we take V-1 edges, enougth
        w, u = heappop(pq)
        if not taken[u]:                            # we have not taken u yet
            num_taken += 1                          # 1 more edge is taken
            # mst_cost += w                           # add w of this edge
            mst_cost=max(mst_cost, w)                           # add w of this edge
            process(u, taken, AL, pq)               # take+process vertex u
                                                    # each edge is in pq once
    print(mst_cost)
    # print("MST cost = {} (Prim's)".format(mst_cost))
main()
