import sys
import os as o
import re as r
from time import sleep
from tqdm import tqdm as t
from selenium import webdriver
from selenium.webdriver.common.by import By


class YearNotValidException(Exception):
    def __str__(self):
        return '输入的年份不合理'


class SchoolNullException(Exception):
    def __str__(self):
        return '查询的学校为空'


def input_school_name(message: str) -> None:
    global schoolName
    schoolName = input(message)
    if len(schoolName) == 0:
        raise SchoolNullException()


def input_year_search(message: str) -> None:
    global yearSearch
    yearSearch = input(message)
    if len(yearSearch) == 0 or int(yearSearch) not in range(1979, 2024):
        raise YearNotValidException()


schoolName: str = None
yearSearch: str = None
allPage: int = None

while True:
    try:
        input_school_name("请输入要抓取的学校:")
        input_year_search("请输入要查询的年份:")
        break

    except SchoolNullException:
        while True:
            try:
                input_school_name("请重新输入要抓取的学校:")
                break
            except SchoolNullException:
                pass
        break
    except YearNotValidException:
        while True:
            try:
                input_year_search("请重新输入要查询的年份:")
                break
            except YearNotValidException:
                pass
        break

try:
    o.makedirs(f"./{schoolName}/{yearSearch}")
except FileExistsError:
    pass

schoolFileSave = open(f"./{schoolName}/{yearSearch}/{yearSearch}年{schoolName}大创项目汇总.csv",
                      mode="w+")
programFileSave = None
schoolFileSave.write(
    "大创,,,,,,,,,,,,\n项目编号,项目名称,项目类型,所属学校,项目期限,所属一级学科,所属二级学科,项目级别,,,,\n")

driver = webdriver.Edge()

driver.get("http://cxcy.sdei.edu.cn/cxxl/Index/ItemPageDashboard?LXYear=2023")

driver.find_element(By.XPATH, '//*[@id="SchoolName"]').send_keys(schoolName)
driver.find_element(By.XPATH, '//*[@id="SearchForm_1"]/div[2]/div[2]/div/button').click()
sleep(1)
driver.find_element(By.XPATH, '//*[@id="SearchForm_1"]/div[3]/div/span[1]/i').click()
sleep(2)
driver.find_element(By.XPATH, '//*[@id="SearchForm_1"]/div[4]/button').click()

pattern = "共(\d+)页"
match = r.search(pattern, driver.find_element(By.XPATH, '/html/body/div[2]/div/div[2]/div[2]/div[2]/span').text)
if match:
    allPage = int(match.group(1))
    print(f"共有{allPage}页")

for page in range(allPage):
    sleep(1)
    print(f"正在处理第{page + 1}页", file=sys.stderr)
    programBoxs = driver.find_element(By.XPATH, '/html/body/div[2]/div/div[2]/div[1]/table/tbody').find_elements(
        By.TAG_NAME, 'tr')
    programBoxs = programBoxs[::4]

    for i in t(range(len(programBoxs))):
        projectGrade = programBoxs[i].text.split("\n")[0].split()[-1]
        infoButton = programBoxs[i].find_element(By.TAG_NAME, 'a')
        infoButton.click()
        elements = driver.find_element(By.XPATH, '/html/body/div[2]/div/div/div').find_elements(By.TAG_NAME, 'div')
        elements = elements[1::2]
        elements = elements[:8] + elements[9::2]
        programName = elements[1].text
        if '/' in programName:
            programName = programName.replace('/', '_')
        programFileSave = open(f"./{schoolName}/{yearSearch}/{programName}.csv", mode="w+")
        for element in elements[:7]:
            schoolFileSave.write(f"{element.text},")
        schoolFileSave.write("%s\n" % projectGrade)
        for element in elements[8:]:
            lines = element.text.split("\n")
            for line in lines:
                words = line.split()
                for word in words:
                    programFileSave.write(f"{word},")
                programFileSave.write("\n")
        programFileSave.close()
        driver.back()

    if page in range(allPage - 1):
        sleep(1)
        driver.find_element(By.XPATH, '/html/body/div[2]/div/div[2]/div[2]/div[1]/div/ul').find_elements(
            By.TAG_NAME, 'a')[-2].click()

schoolFileSave.close()
print(f"{schoolName}{yearSearch}年的大创数据已爬取完毕！")
print(f"文件已保存在路径: {o.getcwd()} 下！", file=sys.stderr)
