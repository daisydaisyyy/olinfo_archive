#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
S = input().strip()
count = 0

# insert your code here
for i in S:
    if i == "R":
        count -= 1
    else:
        count += 1
        
#print(count)
res = abs(count)
print(res) # print the result
