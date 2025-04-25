T = int(input("Enter no. of testcases: "))
l = []

for i in range(T):
    n = input()
    l.append(n)

for i in range(T):
    count = 0
    n = l[i]
    for j in range(len(n)):
        if int(n[j]) == 0: continue
        if int(n)%int(n[j])==0:
            count += 1
    print(count)
