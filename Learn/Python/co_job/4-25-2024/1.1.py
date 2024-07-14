with open("learning_python.txt", 'r') as f:
    # 使用read()读取并输出整个文件
    all_text = f.read()
    print(all_text, end="")

with open("learning_python.txt", 'r') as f:
    # 使用readline()按行读取文件
    while True:
        line = f.readline()
        if not line: break
        print(line, end="")

with open("learning_python.txt", 'r') as f:
    # 使用readlines()读取文件的所有行
    lines = f.readlines()
    for line in lines:
        print(line, end="")
