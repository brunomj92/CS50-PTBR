from collections import Counter

def generate_anagrams(input_string):
    # Helper function to recursively generate anagrams
    def backtrack(anagram):
        if len(anagram) == len(input_string):
            anagrams.append(anagram)
            return
        for char in sorted(unique_chars):
            if counter[char] > 0:
                counter[char] -= 1
                backtrack(anagram + char)
                counter[char] += 1

    counter = Counter(input_string)
    unique_chars = set(input_string)
    anagrams = []

    backtrack('')
    return anagrams

# Example usage:
input_string = "ABEEIJMMNNNOOORRRTUYZ"
anagrams = generate_anagrams(input_string)
with open('result.txt', 'w') as f:
    for word in anagrams:
        f.write(word + "\n")
