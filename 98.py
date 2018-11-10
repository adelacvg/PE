import math
def is_square(x):
    return int(math.sqrt(x))*int(math.sqrt(x))==int(x)
def max_pair(a,b,index,assignments,isdigitused):
    if index == len(a):
        if a[0] in assignments and assignments[a[0]] == 0 or b[0] in assignments and assignments[b[0]] == 0:
            return 0
        anum=0
        bnum=0
        for (x,y) in zip(a,b):
            anum = anum*10+assignments[x]
            bnum = bnum*10+assignments[y]
        if(is_square(anum) and is_square(bnum)):
            return max(anum,bnum)
        else:
            return 0
    elif a[index] in assignments:
        return max_pair(a,b,index+1,assignments,isdigitused)
    else:
        result = 0
        for i in range(10):
            if not isdigitused[i]:
                isdigitused[i]=True
                assignments[a[index]]=i
                result = max(max_pair(a,b,index+1,assignments,isdigitused),result)
                del assignments[a[index]]
                isdigitused[i]=False
        return result
s = open("98.txt","r").read().replace('"','').split(',')
s = list(filter(None,s))
anagrams = {}
for i in s:
    key = "".join(sorted(i))
    if key not in anagrams:
        anagrams[key]=[]
    anagrams[key].append(i)
ans=0
for (key,words) in anagrams.items():
    for i in range(len(words)):
        for j in range(i+1,len(words)):
            assignments = {}
            ans=max(ans,max_pair(str(words[i]),str(words[j]),0,assignments,[False]*10))
print(ans)


