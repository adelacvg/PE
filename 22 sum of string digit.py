import re

f=open("22.txt","r")

s = f.read()
s = s.replace("\"","")
#print(s)
x=re.split(',',s)

x.sort()

#print(x)

ans=0
print(len(x))
for i,v in enumerate(x):
    t=0
    #print(i,v)
    for j in v:
        #print(j)
        t += ord(j)-ord('A')+1
    ans +=(i+1)*t
print(ans)
