from datetime import date
from datetime import timedelta
a=0
for year in range(1901,2001):
    d = date(year,1,1)
    d+=timedelta(days = 6-d.weekday())
    while d.year == year:
        if d.day==1:
            a+=1
        d+=timedelta(days=7)
print(a)
