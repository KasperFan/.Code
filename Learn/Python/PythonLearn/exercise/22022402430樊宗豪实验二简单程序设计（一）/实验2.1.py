cock, hen, chicken = 0, 0, 0
for cock in range(0, 21):
    for hen in range(0, 34):
        chicken = 100 - cock - hen
        if 5 * cock + 3 * hen + chicken / 3 == 100: print("cock={},hen={},chicken={}".format(cock, hen, chicken))
        hen += 1
    cock += 1
