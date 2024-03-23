def main():
    check(get_valid())
    exit(0)


def get_valid():
    while True:
        try:
            cardn = int(input("Number: "))
            if cardn >= 0:
                break
        except:
            continue
    return cardn


def check(cardn):
    chksum = str(cardn)
    z = len(chksum)
    if luhns(chksum) == False:
        print("INVALID")
        return
    elif z == 15 and chksum[:2] in ["34", "37"]:
        print("AMEX")
        return
    elif z == 16 and 50 < int(chksum[:2]) < 56:
        print("MASTERCARD")
        return
    elif z in [13, 16] and chksum[0] == "4":
        print("VISA")
        return
    else:
        print("INVALID")
    return


def luhns(chksum):
    card_number = [int(digit) for digit in chksum][::-1]
    # Convert to a list of integers in reverse order
    total = 0
    for i in range(len(card_number)):
        if i % 2 == 1:
            double_digit = card_number[i] * 2
            total += double_digit - 9 if double_digit > 9 else double_digit
        else:
            total += card_number[i]
    return total % 10 == 0


main()
