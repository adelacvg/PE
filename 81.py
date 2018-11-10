f = open("81.txt").read().split(',')
o = open("81(1).txt","w")

for item in f:
    o.write("%s "%item)
