fac=list(i for i in range(21))
fac[0]=1
for i in range(2,20):
    fac[i]*=fac[i-1]
ans=0
for i in range(0,7):
    for j in range(0,10):
        for k in range(0,11):
            if 3*i+2*j+k==18 and i+j+k<=10:
                a = fac[10]//(fac[i]*fac[j]*fac[k]*fac[10-i-j-k])
                b = fac[18]
                for t in range(i):
                    b//=fac[3]
                for t in range(j):
                    b//=fac[2]
                ans+=a*b
print(int(ans*9/10))

