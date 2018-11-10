a=1
b=1
c=2

while 1:
    c+=1
    a,b = b,a
    b += a
    if len(str(b))>=1000:
        break
    print(c)

print(c)
