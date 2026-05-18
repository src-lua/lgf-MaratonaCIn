def isPalindrome(a):
    return (a == a[::-1])

n = int(input());

best = 0;
ans = [0, 0]

for i in range(n):
    for j in range(n):
        if i*j > best and isPalindrome(str(i*j)): 
            best = i*j
            ans = [i, j]

print(f"{ans[0]} {ans[1]}")