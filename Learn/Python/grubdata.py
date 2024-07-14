from selenium import webdriver
from selenium.webdriver.common.by import By


url = 'http://www.tianqihoubao.com/aqi/beijing-202108.html#:~:text=%E5%8C%97%E4%BA%AC08%E6%9C%88%E4%BB%BD%E7%A9%BA%E6' \
      '%B0%94%E8%B4%A8%E9%87%8F%E6%8C%87%E6%95%B0%28AQI%29%E6%95%B0%E6%8D%AE%EF%BC%9A,' \
      '%E6%95%B0%E5%80%BC%E5%8D%95%E4%BD%8D%EF%BC%9A%CE%BCg%2Fm3%28CO%E4%B8%BAmg%2Fm3%29%20%E6%AF%8F%E6%97%A5AQI%E6' \
      '%95%B0%E6%8D%AE%E5%92%8CPM2.5%E6%B5%93%E5%BA%A6%E6%95%B0%E6%8D%AE%E6%98%AF%E6%A0%B9%E6%8D%AE%E6%AF%8F%E5%B0%8F' \
      '%E6%97%B6%E6%95%B0%E6%8D%AE%E7%AE%97%E6%9C%AF%E5%B9%B3%E5%9D%87%E7%9A%84%E7%BB%93%E6%9E%9C%EF%BC%88%E6%9C%AA' \
      '%E5%AF%B9%E5%A4%B1%E7%9C%9F%E6%95%B0%E6%8D%AE%E4%BF%AE%E6%AD%A3%EF%BC%89%E3%80%82'
file = open("./data.txt", mode="w+")
driver = webdriver.Safari()
driver.get(url)
form = driver.find_element(By.XPATH, "/html/body/form/div[2]/div[7]/div[1]/div[1]/div[3]/table/tbody")
lists = form.find_elements(By.TAG_NAME, "tr")
for element in lists:
    arrs = element.text.split()
    file.write("%s\t%s\n" % (arrs[1], arrs[2]))
file.close()
print("2021年北京市天气数据爬取完毕")
