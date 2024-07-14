flag = None
n = 10
i = 2
while n < 1000:
	while i < n:					# 判断是否是素数
		flag = 1
		if n % i == 0: flag = 0; break
		i += 1
	if flag == 1:							# 判断是否是回文素数
		if n // 100 == 0:					# 判断是否是两位数
			if n // 10 == n % 10: print(n)  # 判断十位和个位是否相同
		elif n // 100 == n % 10: print(n)
	n += 1
