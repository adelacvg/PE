from collections import Counter

s=list(map(int,open("59.txt").read().split(',')))

key = [Counter(s[i::3]).most_common(1)[0][0]^32 for i in range(3)]

print(sum(x^y for x,y in list(zip(s,key*(len(s)//3+1)))))

s = [x^y for x,y in list(zip(s,key*(len(s)//3+1)))]

print(''.join(chr(i) for i in s))
