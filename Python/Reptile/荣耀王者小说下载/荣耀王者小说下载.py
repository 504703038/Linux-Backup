# coding=utf-8
import requests
from bs4 import BeautifulSoup
cur_path = './Reptile/荣耀王者小说下载/'
home_url = 'https://www.xs880.com'


# 获取章节链接
def get_ch_url(contest_urls):
    ch_urls = []
    for con_url in contest_urls:
        res = requests.get(con_url)
        html = res.text
        soup = BeautifulSoup(html, 'lxml')
        soup.encode('gbk')
        ch_list = soup.find(id='section-list').find_all('a')
        for url in ch_list:
            ch_urls.append(home_url + url['href'])
    return ch_urls


# 下载内容
def get_content(url):
    res = requests.get(url)
    res.encoding = 'gbk'
    soup = BeautifulSoup(res.text, 'lxml')
    con_tag = soup.select('#dx')[0]
    content = con_tag.get_text()
    # 判断是否是最后一节
    nxt_con = soup.select('#nextChapterBtn')[0]
    if nxt_con.get_text() == '下一页':
        nxt_url = home_url + nxt_con['href']
        return content + get_content(nxt_url)
    return content


def download(ch_urls):
    for url in ch_urls:
        res = requests.get(url)
        res.encoding = 'gbk'
        soup = BeautifulSoup(res.text, 'lxml')
        # 获取标题
        title = soup.select('#wrap > div.article-title.mt10 > h1')[0]
        title = title.get_text()
        title = title.split('(')[0]
        print(title)
        content = get_content(url)
        with open(cur_path + '荣耀王者.txt', 'a', encoding='utf-8') as file:
            file.write(title + '\n' + content + '\n\n')


if __name__ == "__main__":
    contest_urls = ['https://www.xs880.com/mulu/16599_1.html',
                    'https://www.xs880.com/mulu/16599_2.html']
    # 获取章节链接
    ch_urls = get_ch_url(contest_urls)
    # 下载内容
    download(ch_urls)
