import math
def count_step_pandigital(max_k):
    total = 0
    counts = []
    for i in range(10):
        if i == 0:
            counts.append([0, 0, 0, 0])
        elif i == 9:
            counts.append([0, 0, 1, 0])
        else:
            counts.append([1, 0, 0, 0])
    for k in range(2, max_k+1):
        temp = []
        for i in range(10):
            temp.append([0, 0, 0, 0])
        temp[0][1] += counts[1][0] + counts[1][1]
        temp[0][3] += counts[1][2] + counts[1][3]
        temp[9][2] += counts[8][0] + counts[8][2]
        temp[9][3] += counts[8][1] + counts[8][3]

        for i in range(1, 9):
            temp[i][0] += counts[i - 1][0] + counts[i + 1][0]
            temp[i][1] += counts[i - 1][1] + counts[i + 1][1]
            temp[i][2] += counts[i - 1][2] + counts[i + 1][2]
            temp[i][3] += counts[i - 1][3] + counts[i + 1][3]

        for i in range(0, 10):
            counts[i] = temp[i]

        for c in counts:
            total += c[3]
    return str(total)
s = input()
n = int(math.log10(int(s)))
print(count_step_pandigital(n))
