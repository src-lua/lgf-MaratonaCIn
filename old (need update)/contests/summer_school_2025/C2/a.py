a = input().split(' ')

x = int(a[0])
op = str(a[1])
y = int(a[2])

MOD = int(1e9+7)

if (op == '+'):
    print((x + y) % MOD)
elif (op == '-'):
    print((x - y + MOD) % MOD)
elif (op == '*'):
    print((x * y) % MOD)
elif (op == '^'):
    print(pow(x,y, MOD) % MOD)