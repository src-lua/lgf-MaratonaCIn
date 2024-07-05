tc = int(input())
for _ in range(tc):
    s = input()

    if s == "P=NP": 
        print("skipped")
    else:
        print(eval(s))