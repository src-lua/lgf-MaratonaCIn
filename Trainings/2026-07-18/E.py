n = int(input())
target = n * n -1;
l = 1; r = int(2e9); ans = -1;
while (l <= r):
    m = l + (r-l)//2;
    test = m*(m+1)*(m+2)*(m+3);

    if (test > target): r = m-1;
    elif (test == target):
        ans = m; 
        break;
    else: l = m + 1;
print(ans)
