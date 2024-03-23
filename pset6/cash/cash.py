def main():
    show_change(get_valid())
    exit(0)


def get_valid():
    while True:
        try:
            change_d = float(input("Change owed: "))
            if change_d >= 0:
                break
        except:
            continue
    chg = int(change_d * 100)
    return chg


def show_change(chg):
    coins = 0
    while chg > 0:
        if chg - 25 >= 0:
            chg -= 25
            coins += 1
        elif chg - 10 >= 0:
            chg -= 10
            coins += 1
        elif chg - 5 >= 0:
            chg -= 5
            coins += 1
        else:
            chg -= 1
            coins += 1
    print(coins)


main()
