from sys import argv

script,input_file = argv

sum = 0;

file_in = open(input_file)

for i in range(0,100):
    x=int(file_in.readline())
    print(x)
    sum+=x
print(int(str(sum)[:10]))
print(len(str(sum)))
