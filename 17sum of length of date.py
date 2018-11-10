import inflect
p = inflect.engine()
a=0
for i in range(1,1001):
    x = p.number_to_words(i).replace('-','').replace(' ','')
    a+=len(x)
    print(x)
print(a)
