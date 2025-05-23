import numpy as np

a = np.array([[1, 2, 3], [4, 5, 6]])
b = a.reshape(3, 2)

print("Original array:\n", a)
print("Reshaped array:\n", b)

# Modifying b to see if it affects a
b[0, 0] = 99
print("Modified b:\n", b)
print("Modified a:\n", a)  # Changes only if b is a view
