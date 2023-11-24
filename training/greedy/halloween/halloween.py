#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, M = map(int, input().strip().split())
C = list(map(int, input().strip().split()))

i=0
sum=0
# insert your code here

for el in C:
    sum+=el

i=0
if M>sum:
    if M%sum!=0:
        M%=sum
    else:
        M/=M/sum


    
while M>0:
        M-=C[i]
        i+=1

    


print(i-1)  # print the result
