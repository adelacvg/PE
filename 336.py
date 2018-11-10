def maximix(p):
    if len(p) == 2:
        yield p[1:] + p[:1]
        return
    for q in maximix(p[1:]):
        for i in range(1,len(q)):
            yield q[i:][::-1] + p[:1] + q[:i]

print(sorted(list(maximix("ABCDEFGHIJK")))[2011-1])
