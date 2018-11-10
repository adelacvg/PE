f = open("42.txt","r")

s = f.read()
s = s.replace("\"","").split(',')

#print(s)

a = [x*(x+1)/2 for x in range(30)]

ans=0

for i in s:
    t=0
    for j in i:
        t+=ord(j)-ord('A')+1
    if t in a:
        ans+=1
print(ans)
