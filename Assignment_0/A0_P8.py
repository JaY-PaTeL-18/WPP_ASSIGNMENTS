I = [60, 70, 80, 100, 90, 75, 80, 20]
l = [1]

for i in range(1, len(I)):
    if I[i-1]>I[i]:
        l.append(1)
    elif I[i-1]==I[i]:
        last_elem = l[(len(l)-1)]
        l.append(last_elem+1)
    else:
        count = 0
        for j in range(i, -1, -1):
            if(I[j]<=I[i]): count += 1
            else: break
        l.append(count)

print(l)