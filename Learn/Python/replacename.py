import os
import xml.etree.ElementTree as ET

# 定义data文件夹的路径
data_dir = "/Users/kasperfan/Desktop/office20190902"

# 遍历data文件夹及其子文件夹中的所有xml文件
for root, dirs, files in os.walk(data_dir):
    for file in files:
        # 如果文件名以.xml结尾，说明是一个xml文件
        if file.endswith(".xml"):
            # 拼接xml文件的完整路径
            xml_path = os.path.join(root, file)
            # 解析xml文件，获取根元素
            tree = ET.parse(xml_path)
            xml_root = tree.getroot()
            # 查找path标签，获取其文本内容
            path = xml_root.find("path")
            path_text = path.text
            # 从path文本内容中分离出图片文件名
            img_name = os.path.basename(path_text)
            # 拼接图片文件的实际路径，即当前文件夹下的图片文件名
            img_path = os.path.join(root, img_name)
            # 将path标签的文本内容替换为图片文件的实际路径
            path.text = img_path
            # 将修改后的xml文件保存到原路径
            tree.write(xml_path, encoding="utf-8")
