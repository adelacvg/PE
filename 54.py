from collections import Counter

hands = (x.split() for x in open('54.txt'))

values = {r:i for i,r in enumerate('23456789TJQKA',2)}
straights = [(v,v-1,v-2,v-3,v-4) for v in range(14,5,-1)]+[(14,5,4,3,2)]
ranks = [(1,1,1,1,1),(2,1,1,1),(2,2,1),(3,1,1),(),(),(3,2),(4,1)]

def hand_rank(hand):
    score = list(zip(*sorted(((v,values[k]) for
        k,v in Counter(x[0] for x in hand).items()),reverse=True)))
    score[0] = ranks.index(score[0])
    if len(set(card[1] for card in hand)) == 1:
        score[0] = 5
    if score[1] in straights:
        score[0] = 8 if score[0] == 5 else 4
    if score[0]==5 and score[1]==[(14,13,12,11,10)]:
        score[0]=9
    return score

print(sum(hand_rank(hand[:5])>hand_rank(hand[5:]) for hand in hands))
