import numpy as np
import matplotlib.pyplot as plt
import scipy as sc

outf = open("output.txt")
out = outf.readlines()
n = len(out)
outf.close()
data = []
for k in range(n):
    data.append(out[k].split())
data = np.array(data,float)

variances = np.zeros(n)
N=np.zeros(n)

def lin(x,a,b):
    return a*x+b
for i in range(n):
    variances[i]=data[i,1:].var()
    N[i] = data[i,0]

start = 5

plt.figure(figsize=(12,4))
plt.subplot(121)
plt.title("MonteCarlo integrálás szórása gömbi gauss integrálon")
plt.xlabel("random pontok száma")
plt.ylabel("az eredmény szórása 100 újraszámolás után")
plt.plot(N[start:],variances[start:],color="black")

plt.subplot(122)
x = np.log(N[start:])
y = np.log(variances[start:])
p,M = sc.optimize.curve_fit(lin,x,y)
X = np.linspace(x[0],x[-1])
Y = lin(X,p[0],p[1])
print(p)
plt.title("MonteCarlo integrálás szórása gömbi gauss integrálon log-log")
plt.xlabel("random pontok számának logaritmusa")
plt.ylabel("az eredmény szórásának logaritmusa 100 újraszámolás után")


plt.plot(x,y,color="black")
plt.plot(X,Y,color="red")
plt.show()
