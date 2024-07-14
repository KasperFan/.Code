num = 100
print('水仙花数：')
while num < 1000:
    a = num % 10 					# num的个位数字
    b = num // 10 % 10 				# num的十位数字
    c = num // 100 					# num的百位数字
    if (num == (a*a*a + b*b*b + c*c*c)): print(num)
    num += 1
