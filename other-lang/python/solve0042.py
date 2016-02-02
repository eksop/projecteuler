mp_triagonal = []

for num in range(1,100000):
    x = (num * (num + 1)) / 2
    mp_triagonal.append(x)


def get_all_words():
    fname = "0042_words.txt"
    words = []

    with open(fname) as f:
        for i, w in enumerate(f.readlines()):
            for j, c in enumerate(w.split(",")):
                words.append(c.translate(None, '"'))

    return words


def check_cond(word):
    sum = 0
    letters = list(word)

    for l in letters:
        sum += ord(l) - ord('A') + 1

    if sum in mp_triagonal:
        return True
    else:
        return False


def solve():
    words = get_all_words()
    sum = 0

    for i, w in enumerate(words):
        if check_cond(w):
            sum += 1

    print sum

# Debug
def debug():
    words = get_all_words()

    for i, w in enumerate(words):
        print "word is %s" % (w)

solve()
# debug()
