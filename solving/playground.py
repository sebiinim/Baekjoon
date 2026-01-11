import time
import sys

a = time.time()
sys.stdout.write(str(a) + "\n")

sys.stdout.write("sys" + "\n")

b = time.time()
sys.stdout.write(str(b) + "\n")

sys.stdout.write(str(b - a) + "\n\n\n")

a = time.time()
print(a)

print("print")

b = time.time()
print(b)

print(b - a)
