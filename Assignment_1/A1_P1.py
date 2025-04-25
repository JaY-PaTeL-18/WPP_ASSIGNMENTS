# (a) A list consisting of the integers 0 through 49
a = [i for i in range(50)]
print(a)

# (b) A list containing the squares of the integers 1 through 50.
b = [i**2 for i in range(1, 51)]
print(b)

# (c) The list ['a','bb','ccc','dddd', ...] that ends with 26 copies of the letter z.
c = []
for i in range(26):
    c.append("")
    for j in range(i+1):
        c[i] = c[i] + chr(97+i)
print(c)