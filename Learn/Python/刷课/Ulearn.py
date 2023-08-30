from selenium import webdriver

# 创建 Firefox 浏览器驱动程序
driver = webdriver.Edge()

# 执行 CDP 命令
script = "Object.defineProperty(navigator, 'webdriver', {get: () => false})"
driver.execute_script("const script = document.createElement('script'); script.textContent = arguments[0]; document.documentElement.appendChild(script);", script)

driver.get('https://www.ulearning.cn/ulearning/index.html#/textbookContent?textbookId=42990')

from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
import time
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
while True:
    result = get_element_text()
    if result:
        #         播放视频


        open = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div[1]/div[1]/div/div/div/div[2]/div[1]/button")
        open.click()
        time.sleep(1)

        time_1 = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div[1]/div[1]/div/div/div/div[2]/div[4]/span")
        time_2 = time_1.get_attribute("textContent")
        print(time_2)
        while True:
            time.sleep(30)
            length = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[1]/div[1]/div/div[2]/div/div/div[3]/div[1]/div/div[2]/span")
            text = length.text
            print(text)
            if text == "已看完":
                break
        print("观看结束")
        next = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[2]/div/div[2]/div[1]")
        next.click()
        print("开始翻页")

    else:
        time.sleep(1)
        print(1111)
        next_1 = driver.find_element(By.XPATH, "/html/body/div[5]/div/div[2]/div/div[2]/div/div[2]/div[1]")
        next_1.click()
        time.sleep(1)
        leave = driver.fin