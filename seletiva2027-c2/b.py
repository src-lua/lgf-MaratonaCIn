n = int(input())

print((n * ' ') + ((n+1) * '_'))

k = 0
for i in range(n-1, 0, -1):
    print((i*' ') + '/' + ((n+1 + 2*k) * ' ') + '\\')
    k+= 1

tot = 2*k + 1

print('/' + (n*'_') + (tot * ' ') + '\\' + ((n+1)*'_'))

k = 2*(n-1)
j = 0
for i in range(n-1, 0, -1):
    print(((n+1+j)*' ') + '\\' + (((n+1)+k) * ' ') + '/')
    k-=2
    j+=1

print(((n+1+j)*' ') + '\\' + (((n+1)+k) * '_') + '/')