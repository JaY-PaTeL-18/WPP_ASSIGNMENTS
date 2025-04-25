L = int(input())
R = int(input())
l = []

max = 0
for i in range(L, R+1):
    for j in range(i, R+1):
        if max<i^j:
            max = i^j
print(max)