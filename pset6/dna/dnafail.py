import sys
import csv

def main():
   if len(sys.argv) != 3:
      print("Usage: python dna.py data.csv sequence.txt")
      sys.exit(1)

   # Example usage:
   csv_filename = sys.argv[1]
   txt_filename = sys.argv[2]
   process_csv(csv_filename, txt_filename)
   sys.exit(0)


def process_csv(csv_filename, txt_filename):
    with open(csv_filename, 'r') as csvfile:
        dna = open(txt_filename, 'r')
        csv_reader = csv.reader(csvfile)
        headers = next(csv_reader)  # Get the header row

        for row in csv_reader:
            name = row[0]
            str_counts = {header: int(count) for header, count in zip(headers[1:], row[1:])}

            found_match = all(
                find_longest_run(str_name * str_count, dna.read()) == str_count
                for str_name, str_count in str_counts.items()
            )

            if found_match:
                print(name)
            else:
                print("No match")


def find_longest_run(search_string, text):
    max_run = 0
    current_run = 0

    for i in range(len(text)):
        if text[i:i+len(search_string)] == search_string:
            current_run += 1
            i += len(search_string) - 1
        else:
            max_run = max(max_run, current_run)
            current_run = 0

    return max(max_run, current_run)


main()
