from ctypes import *

a = (c_int*10)()
for i in range(len(a)): print(a[i])