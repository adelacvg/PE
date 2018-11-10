def area(x1,y1,x2,y2,x3,y3):
    return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2
def judge(x1,y1,x2,y2,x3,y3):
    A = area(x1,y1,x2,y2,x3,y3)
    area1 = area(0,0,x2,y2,x3,y3)
    area2 = area(x1,y1,0,0,x3,y3)
    area3 = area(x1,y1,x2,y2,0,0)
    return (area1+area2+area3) == A
f = open('102.txt').read().split('\n')
ans=0
for i in f:
    j = i.split(',')
    if(j[0]!=''):
        x1,y1,x2,y2,x3,y3 = float(j[0]),float(j[1]),float(j[2]),float(j[3]),float(j[4]),float(j[5])
    ans+=judge(x1,y1,x2,y2,x3,y3)
print(ans)
