from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import random

# 打开Edge浏览器，打开超星学习通登录入口

driver = webdriver.Edge()

driver.implicitly_wait(7)

driver.maximize_window()
driver.get('https://passport2.chaoxing.com/login?fid=&newversion=true&refer=http%3A%2F%2Fi.chaoxing.com')


class Course:
    def __init__(self, id, name, complete):
        self.id = id
        self.name = name
        self.complete = complete


# 学校 学号 密码 验证码登陆
def login():
    # inp_1 = input('请输入电话号码:')
    # inp_2 = input('请输入密码:')
    inp_1 = str(13411878396)
    inp_2 = 'FZh5201314lwj'
    # inp_3 = input("请输入验证码：")
    username = driver.find_element(By.ID, 'phone')
    password = driver.find_element(By.ID, 'pwd')
    # numcode = driver.find_element(By.ID, 'numcode')
    # 检查页面元素，修改相应ID
    time.sleep(random.random() * 3)
    username.send_keys(inp_1)
    time.sleep(random.random() * 3)
    password.send_keys(inp_2)
    # numcode.send_keys(inp_3)
    time.sleep(random.random() * 3)
    driver.find_element(By.XPATH, '//*[@id="leftdiv"]/form/div[3]/button').click()  # 检查页面元素，复制登录按钮的xpath
    # driver.find_element(By.LINK_TEXT, '登录').click()
    print("---------- 正在登陆 ----------")


# 进入主页 开始选择课程 xpath匹配
def html_1():
    courses = []
    time.sleep(random.random() * 5)
    # 选择我需要学的课的xpath
    print("---------- 登录成功 ----------\n----------正在进入课程----------")
    time.sleep(3)
    driver.switch_to.frame('frame_content')
    time.sleep(2)
    driver.find_element(By.XPATH, '//*[@id="course_232587482_72371742"]/div[1]/a/img').click()  # 对应课程选项的xpath
    print("----------进入课程成功----------\n----------正在进入小结----------")


# 进入指定小结
def html_2():
    time.sleep(1)
    # 浏览器标签页跳转设置
    driver.switch_to.window(driver.window_handles[1])
    # 进入课程中的指定小节
    time.sleep(random.random() * 3)
    driver.find_element(By.XPATH, '//*[@id="boxscrollleft"]/div/ul[1]/li[2]/a/i').click()
    time.sleep(random.random() * 3)
    driver.switch_to.frame('frame_content-zj')
    time.sleep(1)
    # 添加指定小节的xpath

    driver.find_element(By.XPATH, '//*[@id="fanyaChapter"]/div/div[2]/div[2]/div[16]/div[2]/ul').click()
    time.sleep(random.random() * 3)
    driver.find_element(By.XPATH, '//*[@id="cur707739688"]').click()
    print('----------进入小结成功----------')
    time.sleep(1)


# button模拟点击播放
def button():
    time.sleep(random.random() * 5)
    try:
        # 进入frame播放框架
        driver.switch_to.frame('iframe')
        frame = driver.find_element(By.XPATH, '//*[@id="ext-gen1049"]/iframe')
        driver.switch_to.frame(frame)
        time.sleep(random.random() * 5)  # 此处等待需要久一些就不会报错终止程序
        driver.find_element(By.XPATH, '//*[@id="video"]/button').click()
        time.sleep(random.random() * 2)
        print('---------- 等待播放 ----------')
        # 判断右下角笔记框是否需要关闭，因为它会挡着静音按钮那一块导致静音按钮操作会点到它身上！！！！！！Cao！！！！！！！
        if not driver.find_element(By.XPATH, '//*[@id="ext-gen1048"]/div[2]/div[4]/div[2]/div').get_attribute('style'):
            driver.find_element(By.XPATH, '//*[@id="ext-gen1048"]/div[2]/div[4]/div[2]/div/div/div[2]/a').click()
        time.sleep(random.random() * 3)
        driver.find_element(By.XPATH, '//*[@id="video"]/div[5]/div[6]/button').click()
        time.sleep(random.random() * 2)
        print('---------- 页面静音 ----------')
        time.sleep(2)
        print("----------课程正在播放中----------")

    except Exception as e:
        print('Error at:', e.args[0], e.args[1])
        # 回到主框架
        driver.switch_to.default_content()
        print("----------此处不是视频，即将点击下一页----------")
        time.sleep(2)
        driver.find_element(By.XPATH, '//*[@id="prevNextFocusNext"]').click()
        time.sleep(2)
        # 判断完重新回到button函数再进行判断
        button()


# 判断视频是否播放完
def video_if():
    time.sleep(1)
    # noinspection PyBroadException
    try:
        video_stat_time = driver.find_element(By.XPATH, '//*[@id="video"]/div[5]/div[2]/span[2]').get_attribute(
            "textContent")  # 此处是视频已播放时间的xpath
        video_end_time = driver.find_element(By.XPATH, '//*[@id="video"]/div[5]/div[4]/span[2]').get_attribute(
            "textContent")  # 此处是视频总时间的xpath
        # print("播放时间：", video_stat_time, '结束时间：', video_end_time, '种类：', type(video_stat_time))
        time.sleep(1)

        # 存在时间是 0:01 的情况需要单独处理！！！！！！！！！cao！！！！！！！！！纯纯老六
        if len(video_stat_time) == 4:
            video_stat_time = '0' + video_stat_time

        if len(video_end_time) == 4:
            video_end_time = '0' + video_end_time

        # 修改时间格式为int
        first_start = int(video_stat_time[0] + video_stat_time[1])
        back_start = int(video_stat_time[3] + video_stat_time[4])
        first_end = int(video_end_time[0] + video_end_time[1])
        back_end = int(video_end_time[3] + video_end_time[4])
        return first_start, back_start, first_end, back_end
    except Exception:
        pass


# 翻页，若没有下一页则结束
def video_if2():
    time.sleep(1)
    # noinspection PyBroadException
    try:
        driver.switch_to.default_content()
        time.sleep(2)
        # 此处是下一页按钮的xpath
        driver.find_element(By.XPATH, '//*[@id="prevNextFocusNext"]').click()
        time.sleep(2)
        print("----------即将进入下一页----------")

    except Exception:
        print('---------课程播放结束----------')


if __name__ == '__main__':
    play_flag = True
    circulate_flag = True
    login()
    html_1()
    html_2()
    while circulate_flag:
        if play_flag:
            button()
            play_flag = False

        time_tuple = video_if()
        time.sleep(1)
        print('已经播放：', time_tuple[0], ':', time_tuple[1], '总时长：', time_tuple[2], ':', time_tuple[3])

        # return first_start, back_start, first_end, back_end
        if time_tuple[0] == time_tuple[2] and (time_tuple[1] == time_tuple[3] or time_tuple[1] + 2 == time_tuple[3]
                                               or time_tuple[1] + 3 == time_tuple[3]):
            # 翻页
            video_if2()
            play_flag = True
