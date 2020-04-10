# coding=utf-8
import requests
from bs4 import BeautifulSoup
import gzip
import os
import csv

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:74.0) Gecko/20100101 Firefox/74.0'
}

root_path = './Reptile/Linux中国开源社区/'
gz_file_path = './Reptile/Linux中国开源社区/sitemap_gz_files/'
sitemap_path = './Reptile/Linux中国开源社区/sitemap_files/'


def download_sitemap_file_urls():
    url = 'https://linux.cn/sitemap.xml'
    res = requests.get(url, headers=headers)
    soup = BeautifulSoup(res.text, 'xml')
    locs = soup.find_all(name='loc')
    with open(root_path + 'sitemap_file_urls.txt', 'w') as file:
        for loc in locs:
            file.writelines(loc.get_text() + '\n')


def download_sitemap_files_gz():
    with open(root_path + 'sitemap_file_urls.txt') as file:
        file_urls = file.readlines()
    print(type(file_urls))
    for url in file_urls:
        url = url[:-1]
        res = requests.get(url, headers=headers)
        if (res.status_code != 200):
            print('failed')
            continue
        else:
            print('success')
        filename = url.split('/')[-1]
        try:
            with open(gz_file_path + filename, 'ab') as file:
                file.write(res.content)
        except Exception as err:
            print(str(err))


def decompress_gz_files():

    for file_dir, sub_dir, file_name in os.walk(gz_file_path):
        for gz_filename in file_name:
            gz_file = gzip.GzipFile(gz_file_path + gz_filename)
            content = gz_file.read()
            gz_file.close()
            filename = gz_filename.replace('.gz', '')
            file = open(sitemap_path + filename, 'wb')
            file.write(content)
            file.close()


# 下载站点地图文件
def download_sitemap():
    download_sitemap_file_urls()
    download_sitemap_files_gz()
    decompress_gz_files()


def crawl_articles():
    # articles = []
    for file_dir, sub_dir, file_name in os.walk(sitemap_path):
        for sitemap_filename in file_name:
            file = open(sitemap_path + sitemap_filename)
            content = file.read()
            file.close()
            soup = BeautifulSoup(content, 'xml')
            locs = soup.find_all(name='loc')
            articles = []
            for loc in locs:
                url = loc.get_text()
                res = requests.get(url, headers=headers)
                html = res.text
                soup = BeautifulSoup(html, 'lxml')
                title = soup.find(id='article_title')
                if title is None:
                    continue
                title = title.get_text()
                articles.append({'title': title, 'url': url})
                print('    '+url+'has finished.')
            print(sitemap_filename + 'has finished.')
            store_data(articles)
    # return articles


def store_data(articles):
    with open(root_path + 'articles.csv', 'a') as file:
        writer = csv.writer(file)
        writer.writerow(['title', 'url'])
        for article in articles:
            writer.writerow([article['title'], article['url']])


if __name__ == "__main__":
    # download_sitemap()
    # articles = crawl_articles()
    # store_data(articles)
    crawl_articles()
