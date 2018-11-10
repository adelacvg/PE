import re
f = open("89.txt").read()
p = "DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII"
r = "aa"
ans = len(f) - len(re.sub(p,r,f))
print(ans)
