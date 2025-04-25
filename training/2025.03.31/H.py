import bisect, sys
sys.setrecursionlimit(100005)
 
n = int(input())
pointsX, pointsY = [[] for x in range(100010)], [[] for y in range(100010)]
floor = [-1 for i in range(100010)] # what the id of the node is if we were to drop at this x, y = inf
graph = {} # dictionary from id: node (left child id, right child id)
exists = set()
 
for i in range(n):
    x, y = map(int, input().split(" "))
    pointsX[x].append((y, i))
    pointsY[y].append((x, i))
    exists.add((x, y))
    graph[i] = [-1, -1, y] # left child, right child, node height
 
for x in range(100010): 
    pointsX[x].sort()
    pointsY[x].sort()
 
def processStrip(arr, y):
    li, ri, px = 0, 0, arr[0][0]
    arr.append((500000, -1)) # dummy value at the end
 
    while ri+1 < len(arr):
        ri += 1
        cx, ci = arr[ri]
 
        if cx == px + 1 and not {(cx, y+1), (px, y+1)} & exists: # continue for a continuous chunk (if there is nothing above)
            px += 1
            continue
 
        for j in range(li, ri):
            x, i = arr[j]
            getChild = lambda ind : -2 if (ind, y+1) in exists else floor[ind]
            graph[i] = [getChild(x-(j-li)-1), getChild(px+1), y] 
 
        li, px = ri, cx
 
    for cx, ci in arr[:-1]:
        floor[cx] = ci
 
[processStrip(pointsY[y], y) for y in range(1, 100010) if len(pointsY[y])] # build graph
 
ans = {}
def dfs(node):
    if node in ans: 
        return ans[node]
    
    l, r, y = graph[node]
    getMax = lambda side : 0 if side == -2 else (y if side == -1 else max(dfs(side)[0], y - graph[side][2]))
    getMin = lambda side : 2000001 if side == -2 else (y if side == -1 else max(dfs(side)[1], y - graph[side][2]))
    ans[node] = [(max(getMax(l), getMax(r))), min(getMin(l), getMin(r))]
    if ans[node][1] == 2000001: ans[node][1] = 0
 
    return ans[node]
 
[dfs(node) for node in range(n) if node not in ans] # call the dfs
 
for _ in range(int(input())):
    x, y = map(int, input().split(" "))
    column = pointsX[x]
    index = bisect.bisect_left(column, (y, 0))-1
    if index >= 0:
        minAns = max(ans[column[index][1]][0], y-column[index][0]-1)
        maxAns = max(ans[column[index][1]][1], y-column[index][0]-1)
        print(minAns, maxAns)
    else:
        print(y-1, y-1)