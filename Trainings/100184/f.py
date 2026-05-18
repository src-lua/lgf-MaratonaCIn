def gcd(a, b): return gcd(b, a % b) if b else a
def lcm(a, b): return a // gcd(a, b) * b

mod = int(1000000007)
inv2 = 500000004
inp = input().split(' ')
n = int(inp[0]); a = int(inp[1]); b = int(inp[2])
n-=1
c = lcm(a, b)

qta = (a*(1+(n//a))*(n//a)) % mod;
qtb = (b*(1+(n//b))*(n//b)) % mod
qtc = (c*(1+(n//c))*(n//c)) % mod
ans = ((qta+qtb-qtc) * inv2) % mod;

print(ans)