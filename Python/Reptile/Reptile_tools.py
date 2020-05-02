import requests
from bs4 import BeautifulSoup
cur_path = './Reptile/'


def get_soup(url, encoding=None):
    try:
        res = requests.get(url)
        if encoding is not None:
            res.encoding = encoding
        html = res.text
        soup = BeautifulSoup(html, 'lxml')
    except Exception as err:
        print(str(err))
    return soup


if __name__ == "__main__":
    url = 'http://www.baidu.com'
    soup = get_soup(url, 'utf-8')
    print(soup.find('a'))
    print(soup.find(name='mp'))
