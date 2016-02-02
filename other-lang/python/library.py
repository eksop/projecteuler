import math

mp_penta = []

def check_cond(i, j):
    if i == j:
        return False

    # try:
    sum = mp_penta[i] + mp_penta[j]
    # except IndexError:
    # return False

    if sum in mp_penta:
        # print "Oh yeah! %d" % sum
        pass
    else:
        return False

    diff = mp_penta[i] - mp_penta[j];

    if diff < 0:
        diff = -1 * diff

    if diff in mp_penta:
        pass
    else:
        return False

    print "Oh yes! sum = %d, diff = %d" % (sum, diff)
    return True


def check_sum_num(a, b):
    rt = sqrt(1 - 12 * ( -3 * ( (a * a) + (b * b)) + a + b))

    x = (1 + rt) / 6.0
    y = (1 - rt) / 6.0





for var in range(1,10000):
    pentagonal_num(var)


def solve():
    for i, ival in enumerate(mp_penta):
        for j, jval in enumerate(mp_penta):
            if check_cond(i, j):
                print "I is %d, J is %d" % (i, j)

solve()
# print mp_penta

# Debug
# for idx, val in enumerate(mp_penta):
#    print "Index is %d, Val is %d" % (idx, val)
