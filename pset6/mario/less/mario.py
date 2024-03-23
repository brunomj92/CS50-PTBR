def main():
    h = get_height()
    pyramid(h)
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


def pyramid(h):
    for i in range(h):
        for j in range(h):
            if (i + j) < (h - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()


main()
