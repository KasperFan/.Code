from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

retry_max = 10
retry_times = 0

print('请输入账号：', end="")
str_1 = '13335243664'
# str_1 = input()
print('请输入密码：', end="")
str_2 = 'FZh02280226'
# str_2 = input()

# 创建 Firefox 浏览器驱动程序
driver = webdriver.Edge()

# 执行 CDP 命令
script = "Object.defineProperty(navigator, 'webdriver', {get: () => false})"
driver.execute_script(
    "const script = document.createElement('script'); script.textContent = arguments[0]; document.documentElement.appendChild(script);",
    script)
driver.maximize_window()
driver.get('https://www.ulearning.cn/sld/pc.html#/login')
# //*[@id="koView757"]/div/div[3]/div[1]/div[2]/div[2]/div/button

# time.sleep(10)
#
# while 10 < 11:
#     try:
#         driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div[3]/div[1]/div[2]/div[2]/div/button').click()
#         break
#     except Exception as e:
#         print('没有定位到元素!')
time.sleep(5)
username = driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[2]/div/div[1]/div/div/div[3]/form/div['
                                         '1]/div/div/input')
password = driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[2]/div/div[1]/div/div/div[3]/form/div['
                                         '2]/div/div/input')
username.send_keys(str_1)
password.send_keys(str_2)
driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[2]/div/div[1]/div/div/div[3]/form/button').click()

all_windows = driver.window_handles

# 切换到新窗口
new_window = all_windows[-1]
driver.switch_to.window(new_window)


def get_element_text():
    try:
        element = driver.find_element(By.XPATH, "/html/body/div[4]/div/div[4]")  # 尝试定位元素
        element_text = element.text
        if element_text == "课堂小测":
            print("课堂小测")
            return False
        else:
            print("观看视频")
            return True

    except NoSuchElementException:
        return False  # 元素未找到，返回false

cookies = driver.get_cookies()

while True:
    result = get_element_text()
    if result:
        #         播放视频

        open = driver.find_element(By.XPATH,
                                   "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div[1]/div["
                                   "1]/div/div/div/div[2]/div[1]/button")
        open.click()
        time.sleep(1)

        time_1 = driver.find_element(By.XPATH,
                                     "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div[1]/div["
                                     "1]/div/div/div/div[2]/div[4]/span")
        time_2 = time_1.get_attribute("textContent")
        print(time_2)
        while True:
            time.sleep(30)
            length = driver.find_element(By.XPATH,
                                         "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div["
                                         "3]/div[1]/div/div[2]/span")
            text = length.text
            print(text)
            if text == "已看完":
                break
        print("观看结束")
        next = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[2]/div/div[2]/div[1]")
        next.click()
        print("开始翻页")

    else:
        time.sleep(10)
        next_1 = driver.find_element(By.XPATH, "/html/body/div[1]/div/div/div[4]/div/div[1]/div[2]/div[3]/div["
                                               "1]/div/div")
        next_1.click()
        time.sleep(1)
        leave = driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div[3]/div[1]/div/a[3]')
        leave.click()
        time.sleep(5)
        box = driver.find_element(By.XPATH,'/html/body/div[1]/div/div/div[3]/div[2]/div/div/div/div[1]/div['
                                           '3]/table/tbody')
        lists = box.find_elements(By.TAG_NAME, 'tr')
        for elem in lists:
            spanlists = elem.find_elements(By.TAG_NAME, 'span')
            # if spanlists[3].text
