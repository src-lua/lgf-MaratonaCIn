
# Time complexity: O(n)
fact = []; 
def precalc_fact(n):
    fact.append(1)
    fact.append(1)

    for i in range (2, n+1):
        fact.append(fact[i - 1] * i)

def choose(n, k):
    return fact[n] / (fact[k] * fact[n-k])

def main():
    i = input().split()
    n = int(i[0])
    m = int(i[1])
    t = int(i[2])
    
    precalc_fact(60);
    
    answ = 0

    for i in range(4, min(n,t)):
        if (m >= t-i):
            answ += choose(n,i) * choose(m,t-i)

    print(int(answ))

main()