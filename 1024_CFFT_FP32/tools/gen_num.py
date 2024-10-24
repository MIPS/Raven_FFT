import numpy as np

# Generate a random list of float32 numbers where the first index is a number and the next index is 0
random_numbers = np.zeros(2048, dtype=np.float32)
random_numbers[::2] = np.random.rand(1024).astype(np.float32)

# Write the generated list to a text file
with open('random_numbers.txt', 'w') as f:
    for number in random_numbers:
        f.write(f"{number}\n")

print("The random numbers have been written to random_numbers.txt")

