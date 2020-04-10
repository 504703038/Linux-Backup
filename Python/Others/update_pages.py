import time
from selenium import webdriver


def login():
    global browser
    try:
        browser.get('https://gitee.com/login')
        user_name = browser.find_element_by_id('user_login')
        password = browser.find_element_by_id('user_password')
        butn = browser.find_element_by_css_selector(
            'div.field:nth-child(4) > input:nth-child(1)')
        user_name.clear()
        password.clear()
        user_name.send_keys('15898985611')
        password.send_keys('yangSHIFA12345')
        butn.click()
        time.sleep(3)
    except Exception as error:
        print('\033[31mError  \033[0m' + 'Login failed.')
        print('\033[31mError  \033[0m' + 'In method "login"')
        print('\033[31mError  \033[0m' + str(error))


def update_pages():
    global browser
    try:
        browser.get(
            'https://gitee.com/Oort_t/dashboard/projects/Oort_t/Oort_t/pages')
        butn = browser.find_elements_by_tag_name('button')
        print(butn[2])
        input()
        butn[2].click()
        print('\033[32mINFO  \033[0m' + 'Deploying...')
        time.sleep(3)
    except Exception as error:
        print('\033[31mError  \033[0m' + 'Deploy failed.')
        print('\033[31mError  \033[0m' + 'In method "update_pages"')
        print('\033[31mError  \033[0m' + str(error))
    browser.quit()


if __name__ == '__main__':
    options = webdriver.ChromeOptions()
    # options.add_argument('--headless')
    browser = webdriver.Chrome(chrome_options=options)
    print('\033[32mINFO  \033[0m' + 'Start deploy.')
    login()
    update_pages()
    print('\033[32mINFO  \033[0m' + 'Deployment is completed.')
