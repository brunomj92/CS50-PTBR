def main():
    h = get_height()
    pyramids(h)
    exit(0)


def get_height():
    while True:
        try:
            a = int(input("Height: "))
            if (a > 0) and (a < 9):
                break
        except:
            continue
    return a


def pyramids(h):
    for i in range(h):
        for j in range(h + i + 3):
            if (i + j) < (h - 1) or j == h or j == (h + 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()


main()
