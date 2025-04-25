#Write a program that generates 100 random integers that #are either 0 or 1. Then find the
#longest run of zeros, the largest number of zeros in a #row. For instance, the longest run of
#zeros in [1,0,1,1,0,0,0,0,1,0,0] is 4.

import random

a = [random.randint(0, 1) for _ in range(10)]
print(a)
max_count_zeros = 0
count_zero = 0

for i in range(10):
    if a[i]==0:
        count_zero += 1
    else:
        max_count_zeros = max(max_count_zeros,count_zero)
        count_zero = 0

print(max_count_zeros)