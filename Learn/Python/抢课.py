from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import random

# 打开Edge浏览器，打开教务系统登录入口

driver = webdriver.Edge()

driver.implicitly_wait(7)

driver.maximize_window()
driver.get('https://jw.wfu.edu.cn/jsxsd/')


class Courses:
    def __init__(self, courseName, courseID):
        self.courseName = courseName
        self.courseID = courseID




def login():
    # inp_1 = input('请输入学号:')
    # inp_2 = input('请输入密码:')
    inp_1 = str(22022402430)
    inp_2 = [106, 105, 118, 115, 111, 118, 45, 113, 117, 116, 110, 97, 51, 45, 118, 105, 119, 107, 97, 80]
    # inp_3 = input("请输入验证码：")
    username = driver.find_element(By.ID, 'userAccount')
    password = driver.find_element(By.ID, 'userPassword')
    # numcode = driver.find_element(By.ID, 'RANDOMCODE')
    # 检查页面元素，修改相应ID
    time.sleep(random.random() * 3)
    username.send_keys(inp_1)
    time.sleep(random.random() * 3)
    password.send_keys(''.join(map(chr, inp_2)))
    # numcode.send_keys(inp_3)
    time.sleep(random.random() * 3)
    driver.find_element(By.XPATH, '//*[@id="ul1"]/li[5]/button').click()  # 检查页面元素，复制登录按钮的xpath
    # driver.find_element(By.LINK_TEXT, '登录').click()
    print("---------- 正在登陆 ----------")

3
def getcourses():
    time.sleep(random.random() * 3)
    driver.find_element(By.XPATH, '//*[@id="dataList"]/tbody/tr[1]/td/a').click()
    time.sleep(random.random() * 3)


if __name__ == '__main__':
    login()
    getcourses()
    print('完成')
