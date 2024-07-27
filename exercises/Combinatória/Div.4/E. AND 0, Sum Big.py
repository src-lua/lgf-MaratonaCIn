# CADA K BIT 0 PODE ESTAR EM N POSIÇÕES
# 
# N*N*N*N...*N (K vezes)
# 
# N^K

tc = int(input())

for _ in range(tc):
    a = input().split(' ')
    print(pow(int(a[0]), int(a[1]), 1000000007))
