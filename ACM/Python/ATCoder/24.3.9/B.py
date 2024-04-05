from sys import stdin
from io import StringIO

input = lambda: stdin.readline().strip()

buffer = StringIO()

arr = [int(i) for i in stdin.read().split()]
# arr.sort()
for i in arr[::-1]:
    buffer.write("%d\n" % i)
print(buffer.getvalue(), end="")
