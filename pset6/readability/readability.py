def main():
    grade = col_liau(str(input("Text: ")))
    if grade < 1:
        print("Before Grade 1")
    elif 1 <= grade <= 15.5:
        print(f"Grade {round(grade)}")
    else:
        print("Grade 16+")
    exit(0)


def col_liau(text):
    letter_count = sum(c.isalpha() for c in text)
    word_count = len(text.split())
    sentence_count = text.count(".") + text.count("!") + text.count("?")
    L = letter_count / word_count * 100
    S = sentence_count / word_count * 100
    return 0.0588 * L - 0.296 * S - 15.8


main()
