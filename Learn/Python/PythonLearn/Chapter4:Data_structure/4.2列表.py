# 1.列表更新：列表可以像数组一样使用下标索引获取其中的元素，也可以通过索引更新其中元素
a1 = [1, 2, 3, 4, 5]
print(a1[2])
a1[2] = "Hello"
print(a1)

# 列表的索引必须是已存在的索引，不能对超出列表长度的索引进行操作
# a1[10] = 1000
"""
Traceback (most recent call last):
  File "/Users/kasperfan/Desktop/.Code/Learn/Python/PythonLearn/Chapter4:Data_structure/4.2列表.py", line 8, in <module>
    a1[10] = 1000
IndexError: list assignment index out of range
"""

# 2.增加元素：列表不能通过索引来添加元素，索引只能修改更新现有的元素。
# 如果想要添加新元素，可以使用append方法在列表的最后追加新元素。
a1.append("Hello")
print(a1)
# 执行结果如下
"""[1, 2, 'Hello', 4, 5, 'Hello']"""

# append直接在原来的列表上新增了一个元素。
# 但是要注意，append每次只能新增一个元素，
# 如果想新增多个元素就要使用extend方法。
a1 = [1, 2, 3, 4, 5]
a1.append([6, 7])
print("append")
print(a1)

print("-------------------")

a2 = [1, 2, 3, 4, 5]
a2.extend([6, 7])
print("append")
print(a2)
# 执行结果如下：
"""
append
[1, 2, 3, 4, 5, [6, 7]]
-------------------
append
[1, 2, 3, 4, 5, 6, 7]
"""
# append无论后面是单个元素还是一个列表，都会把它当成新元素追加到原来列表的后面，
# 而extend则会展开，把新列表拆开追加在原来列表的后面

# append和extend两种方法都是在列表的最后追加元素，那有没有什么方法可以在列表中间插入元素呢？
# Python里当然也提供了相应的方法，就是方法insert。
a1 = [1, 2, 3, 4, 5]
print(a1)
print("insert")
a1.insert(2, "Hello")
print(a1)
# 执行结果如下：
"""
[1, 2, 3, 4, 5]
insert
[1, 2, 'Hello', 3, 4, 5]
"""

# 3.删除元素：能够添加元素，自然也可以删除元素。Python也提供了好几种对列表删除元素的方法。
# (1) pop函数用于移除列表中的一个元素（默认是最后一个元素），并且返回该元素的值。
a1 = [1, 2, 3, 4, 5]
print(a1)
print("pop()")
r1 = a1.pop()
print("result", r1)
print("list", a1)
print("-------------------")
a2 = [1, 2, 3, 4, 5]
print("pop(2)")
r2 = a2.pop(2)
print("result", r2)
print("list", a2)
# 执行结果如下：
"""
[1, 2, 3, 4, 5]
pop()
result 5
list [1, 2, 3, 4]
-------------------
pop(2)
result 3
list [1, 2, 4, 5]
"""
# pop函数可以删除指定位置的元素(可指定位置以模拟队列或栈)，
# 并且把这个元素作为返回值返回，
# 如果不指定位置则默认选择最后一个元素(类似于栈的后进先出)。

# (2) 不但可以根据位置删除元素，还可以根据元素内容来对元素进行删除。
# remove方法就提供了这样的功能。
a1 = ["Hello", "Google", "Baidu", "QQ"]
print(a1)
print("remove")
a1.remove("Baidu")
print(a1)
# 执行结果如下：
"""
['Hello', 'Google', 'Baidu', 'QQ']
remove
['Hello', 'Google', 'QQ']
"""
# "remove" 会删除查找到的第一个元素，并且没有返回值。

## (3) 不但可以使用列表自带的方法对列表元素进行删除，也可以使用关键字 "del" 来删除列表元素。
a1 = ['Hello', 'Google', 'Baidu', 'QQ']
print(a1)
print("del")
del a1[2]
print(a1)
# 执行结果如下：
"""
['Hello', 'Google', 'Baidu', 'QQ']
del
['Hello', 'Google', 'QQ']
"""
# 关键字 "del" 后是指定的列表元素和索引，
# 从例子中可以看出，"del" 删除了其中一个元素，元素数量从四个变成了三个。
# "del" 不仅可以删除列表的元素，还能删除其他元素，具体操作在后续章节中会涉及

# 4. 查找元素：Python提供了index方法用于查找元素在列表中的索引位置。
a1 = ['Hello', 'Google', 'Baidu', 'QQ']
print("Baidu index is", a1.index("Baidu"))
print("QQ index is", a1.index("QQ"))
# 执行结果如下：
"""
Baidu index is 2
QQ index is 3
"""
# 但是要注意，如果元素不在列表中，Python解释器就会输出错误信息。
# 错误
# print("Taobao index is", a1.index("Taobao"))
"""
Traceback (most recent call last):
  File "/Users/kasperfan/Desktop/.Code/Learn/Python/PythonLearn/Chapter4:Data_structure/4.2列表.py", line 133, in <module>
    print("Taobao index is", a1.index("Taobao"))
ValueError: 'Taobao' is not in list
"""
# Python解释器会提示错误“ValueError: 'Taobao' is not in list”告诉我们这个元素不在列表中

# 5.队列的其他操作：

