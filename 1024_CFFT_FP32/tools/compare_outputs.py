def read_numbers_from_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    return {tuple(round(float(num), 1) for num in line.split()) for line in lines}

# Specify the paths to your input files
file_path1 = 'optimized_numbers2.txt'
file_path2 = 'numbers_python_1024.txt'

# Read the numbers and convert them to sets of tuples
set1 = read_numbers_from_file(file_path1)
set2 = read_numbers_from_file(file_path2)

# Check if the sets match
if set1 == set2:
    print("The entries in both sets match.")
else:
    print("The entries in both sets do not match.")
    print("Entries in set1 but not in set2:", set1 - set2)
    print("Entries in set2 but not in set1:", set2 - set1)
