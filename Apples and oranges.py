#!/bin/python3

# https://www.hackerrank.com/challenges/apple-and-orange/problem
#Partial answer
import sys


s,t = input().strip().split(' ')
s,t = [int(s),int(t)]
a,b = input().strip().split(' ')
a,b = [int(a),int(b)]
m,n = input().strip().split(' ')
m,n = [int(m),int(n)]
apple = [int(apple_temp) for apple_temp in input().strip().split(' ')]
orange = [int(orange_temp) for orange_temp in input().strip().split(' ')]
x=s-a
y=b-t
count=0
c=[count+1 for p in apple if p>=x and p<=(x+t-s) ]
if c:
    print(c[0])
else:
    print(0)
count=0
c=[count+1 for p in orange if (-p)>=y and (p+t-s)<=s ]
if c:
    print(c[0]) 
else:
    print(0)
