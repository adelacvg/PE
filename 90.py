from itertools import combinations,product

comb = list(combinations([0,1,2,3,4,5,6,7,8,9],6))
comb = [[6 if y==9 else y for y in x ] for x in comb]
valid = [tuple(map(int, list(str(s*s).zfill(2)))) for s in range(1,10)]
valid.remove((0,9))
valid.remove((4,9))
valid.append((0,6))
valid.append((4,6))
def isvalid(comb1,comb2):

    combx = list(product(comb1, comb2))+list(product(comb2,comb1))

    for i in valid:
        if i not in combx:
            return False
    return True
res=0


for i in range(len(comb)):
    for j in range(i+1,len(comb)):
        if isvalid(comb[i],comb[j])==True:
            res+=1
'''
a = [0,5,6,7,8,6]
b = [1,2,3,4,8,6]
print(isvalid(a,b))
'''
print(res)
