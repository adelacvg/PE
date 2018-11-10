import itertools

cnt=0
for i in itertools.count(100):
    t="".join(sorted(str(i)))
    if str(i)!=t and str(i)[::-1]!=t:
        cnt+=1
    if cnt*100 >=99*i:
        print(str(i))
        break;
