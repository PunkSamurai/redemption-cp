n = int(input())
m = int(input())
answer = 1
a = 2
while(n>0):
    if n%2==1:
        answer=answer*a
    a*=a
    n/=2

print(m%answer)