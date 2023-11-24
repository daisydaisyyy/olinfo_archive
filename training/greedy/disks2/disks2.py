
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, T = map(int, input().strip().split())
A = [0] * N
B = [0] * N

for i in range(N):
    A[i], B[i] = map(int, input().strip().split())


# insert your code here
i=0

while (i+1<N):
    sum=T
    sum-=24-B[i]+A[i+1]
    # print(sum)
    if sum<=0: break
    i+=1
    
else: 
    i=-1


print(i)  # print the result
