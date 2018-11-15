'''
this code is from the pe thread implement with markov chain
Wrriten By philiplu
Sat, 14 May 2016, 20:01
philiplu
Python
'''
from time import time
import sys
import numpy

start = time()

NumSquares = 40
NumStates = NumSquares * 3

GO   = 0
CC1  = 2
R1   = 5
CH1  = 7
JAIL = 10
C1   = 11
U1   = 12
R2   = 15
CC2  = 17
CH2  = 22
E3   = 24
R3   = 25
U2   = 28
G2J  = 30
CC3  = 33
R4   = 35
CH3  = 36
H2   = 39

def matrix_mult(a, b):
    a_rows, b_rows, b_cols = len(a), len(b), len(b[0])
    assert(len(a[0]) == b_rows)
    return [[sum([a[i][k] * b[k][j] for k in range(b_rows)])
                 for j in range(b_cols)] for i in range(a_rows)]

def normalize(a):
    result = []
    for row in a:
        total = sum(row)
        result.append([x/total for x in row])
    return result

def distance(v1, v2):
    return sum((v1[i]-v2[i])**2 for i in range(len(v1)))**0.5

def identity_matrix():
    return [[1.0 if i == j else 0 for j in range(NumStates)] for i in range(NumStates)]

def roll_matrix(die_size):
    m = [[0.0] * NumStates for i in range(NumStates)]
    die_prob = [0.0] * (2*die_size + 1)

    # Compute base probabilities for 2 dice
    die_prob[die_size+1] = 1/die_size
    for d in range(1, die_size):
        die_prob[d+1] = d/(die_size * die_size)
        die_prob[2*die_size+1-d] = d/(die_size * die_size)
    # Back out the probabilities for each throw of a double
    for d in range(1, die_size+1):
        die_prob[2*d] -= 1/(die_size * die_size)

    for sq in range(NumSquares):
        # Handle non-doubles - all states go back to non-double states
        for i in range(0, NumStates, NumSquares):
            for d_sum in range(2, 2*die_size+1):
                m[sq+i][(sq+d_sum)%NumSquares] = die_prob[d_sum]
        # Handle doubles - states 0-39 move to states 40-79, states 40-79 move
        # to states 80-119, and states 80-119 all go to Jail
        for d in range(1, die_size+1):
            m[sq][NumSquares + (sq+2*d)%NumSquares] = 1/(die_size*die_size)
            m[sq+NumSquares][2*NumSquares+(sq+2*d)%NumSquares] = 1/(die_size*die_size)
        m[sq+2*NumSquares][JAIL] += 1/die_size
    return m

def chance_matrix():
    # There are 10 of 16 cards that move elsewhere
    m = identity_matrix()
    for i in range(0, NumStates, NumSquares):
        for sq, rr, ut in zip((CH1,CH2,CH3),(R2,R3,R1),(U1,U2,U1)):
            m[sq+i][sq+i] = 6/16    # 6 cards stay put
            m[sq+i][GO+i] = 1/16    # Advance to GO
            m[sq+i][JAIL] = 1/16    # Go to Jail clears the double count
            m[sq+i][C1+i] = 1/16    # Go to St. Charles Place
            m[sq+i][E3+i] = 1/16    # Go to Illinois Avenue
            m[sq+i][H2+i] = 1/16    # Go to Boardwalk
            m[sq+i][R1+i] = 1/16    # Go to Reading Railroad
            m[sq+i][rr+i] += 2/16   # Advance to nearest railroad (add in case that's Reading RR)
            m[sq+i][ut+i] = 1/16    # Advance to nearest utility
            m[sq+i][(sq+i-3)%NumSquares] = 1/16 # Go back 3 squares
    return m

def community_chest_matrix():
    # There are 2 of 16 cards that move elsewhere
    m = identity_matrix()
    for i in range(0, NumStates, NumSquares):
        for sq in (CC1, CC2, CC3):
            m[sq+i][sq+i] = 14/16   # 14 cards stay put
            m[sq+i][GO+i] = 1/16    # Advance to GO preserves double count
            m[sq+i][JAIL] = 1/16    # Go to Jail clears the double count
    return m

def go_to_jail_matrix():
    m = identity_matrix()
    for i in range(0, NumStates, NumSquares):
        m[G2J+i][G2J+i] = 0.0
        m[G2J+i][JAIL]  = 1.0
    return m

def p84(die_size = 4):
    P = matrix_mult(roll_matrix(die_size), chance_matrix())
    P = matrix_mult(P, community_chest_matrix())
    P = matrix_mult(P, go_to_jail_matrix())
    # repeatedly square the transition matrix until it stabilizes
    stable = False
    while not stable:
        prev = P[0]
        P = normalize(matrix_mult(P, P))    # normalize to reduce round-off error accumulation
        error = distance(prev, P[0])
        stable = error < 1e-6
    # sum up the square probabilities over the 3 double states
    probs = [sum(P[0][i:NumStates:NumSquares]) for i in range(NumSquares)]
    sort = sorted(zip(probs, range(NumSquares)), key=lambda x: -x[0])
    for prob, sqnum in sort:
        print("{0:2} {1}%".format(sqnum, prob*100))
    return ''.join(["{0:02}".format(sqnum) for _, sqnum in sort[:3]])

print(p84(*(int(arg) for arg in sys.argv[1:])))

print("Time: {0} secs".format(time()-start))
