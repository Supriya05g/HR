import numpy as np
from sklearn import linear_model

m,n = [int(i) for i in input().strip().split(' ')]
X = []
Y = []
for i in range(n):
    data = input().strip().split(' ')
    X.append(data[:m])
    Y.append(data[m:])
X = np.array(X,float)
Y = np.array(Y,float)

lm = linear_model.LinearRegression()
lm.fit(X, Y)
a = lm.intercept_
b = lm.coef_
mergedlist = []
mergedlist.extend(a)
mergedlist.extend(b[0])

# print(mergedlist)
n_test=int(input().strip())
X_test=[]
for i in range(n_test):
    data = input().strip().split(' ')
    X_test.append(data)
X_test = np.array(X_test,float)
X_test=np.c_[np.ones(n_test),X_test  ]
B=np.array(mergedlist,float)
Y_test=[]
Y_test=np.dot(X_test,B.T)
for i in Y_test:
    print(round(i,2))