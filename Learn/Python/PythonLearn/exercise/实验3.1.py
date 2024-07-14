salary = 2000
sale = int(input('请输入销售额：'))
if sale % 1000 == 0: k = sale / 1000  		# 计算销售系数
else: k = sale / 1000 + 1
if 3 < k <= 7: salary += sale * 0.1  		# 计算薪水
elif 7 < k <= 10: salary += sale * 0.15
elif k > 10: salary += sale * 0.2
print('薪水总计：{}'.format(salary))
