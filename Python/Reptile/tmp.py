import Reptile_tools as tool
cur_path = './Reptile/'

if __name__ == "__main__":
    url = 'http://www.baidu.com'
    soup = tool.get_soup(url, 'utf-8')
    print(soup.find('a'))
    print(soup.find(name='mp'))
