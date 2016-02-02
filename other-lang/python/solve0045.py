import math

tri = []
penta = []
hexa = []
max = 100000

for n in range(0,max):
    a = (n * (n + 1)) / 2
    b = (n * (3 * n - 1)) /2
    c = (n * (2 * n - 1))

    tri.append(a)
    penta.append(b)
    hexa.append(c)


def check_cond():

    for i in tri:
        if i in penta:
            if i in hexa:
                print "Val %d" % i


def solve():
    check_cond()

solve()
# print mp_penta

# Debug
# for idx, val in enumerate(mp_penta):
#    print "Index is %d, Val is %d" % (idx, val)
