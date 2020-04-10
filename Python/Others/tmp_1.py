import time
from selenium import webdriver
if __name__ == "__main__":
    url_baidu = 'http://www.baidu.com'
    url_bing = 'https://cn.bing.com'
    # 设置浏览器属性，无窗口化后台运行
    options = webdriver.ChromeOptions()
    # options.add_argument('--headless')
    # 打开浏览器
    browser = webdriver.Chrome(chrome_options=options)
    # 访问网页
    browser.get(url_baidu)
    print('百度finish.')
    time.sleep(5)
    browser.get(url_bing)
    print('必应finish.')
    time.sleep(5)
    # 退出浏览器
    browser.quit()
