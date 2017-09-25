#!/bin/python3

# https://www.hackerrank.com/challenges/time-conversion/problem

import sys

def timeConversion(s):
    # Complete this function
    x=s.split(':')
    
    a=x[2][2:4]
    x[2]=x[2][0:2]
    if(a=='AM' and x[0]=='12'):
        x[0]='00'
    elif(a=='PM' and x[0]!='12'):
        x[0]=str(12+int(x[0]))
    
    return x[0]+':'+x[1]+':'+x[2]
        
    
s = input().strip()
result = timeConversion(s)
print(result)
