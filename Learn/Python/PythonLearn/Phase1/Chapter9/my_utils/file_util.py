# -*- coding: utf-8 -*-
# @FileCreateTime    : 2024/3/5 18:09
# @Author            : kasperfan
# @Site              :
# @File              : file_util.py
# @Path              :
# @Software          : PyCharm
# @Comment           :

# 接收传入文件的路径，打印文件的全部内容，如文件不存在则捕获异常，输出提示信息，通过finally关闭文件对象
def print_file_info(file_name):
    try:
        f = open(file_name, 'r')
        print(f.read())
    except Exception as e:
        print(e)
    finally:
        f.close()


# 接收文件路径以及传入数据，将数据追加写入到文件中
def append_to_file(file_name, data):
    try:
        with open(file_name, 'a') as f:
            f.write(data)
            f.flush()
    except Exception as e:
        print(e)
