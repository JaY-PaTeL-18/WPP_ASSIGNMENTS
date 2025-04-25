T = int(input("Enter number of test cases : "))

for i in range(T):
    
    n = int(input("Enter number of cycle : "))

    hight = 1

    if (n == 0):
        print(hight)
    else:
        for i in range(n):
            if (i % 2 == 0):
                hight = (2*hight)
            elif (i % 2 == 1):
                hight = hight + 1
        print(hight)

