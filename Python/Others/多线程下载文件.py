import os
import sys
import time
from urllib import request
from threading import Thread


class DownloadThread(Thread):
    def __init__(self, thread_name, url, output_path, file_nam, ranges):
        super().__init__()
        self.name = thread_name
        self.url = url
        self.output_path = output_path
        self.file_name = file_nam
        self.ranges = ranges
        # 已下载大小，从而暂停之后可以继续下载
        self.downloaded = 0

    def run(self):
        """ 运行线程 """
        # 读取已下载文件的大小，从而继续下载
        try:
            self.downloaded = os.path.getsize(
                self.output_path + self.file_name)
        except FileNotFoundError:
            self.downloaded = 0
        self.start_point = self.ranges[0] + self.downloaded
        # 判断文件是否已经下完
        if self.start_point >= self.ranges[1]:
            print('Part %s has been downloaded over.' % self.file_name)
            return
        # 开始下载
        self.one_time_size = 16384  # 16kb
        print('task %s will download from %d to %d' %
              (self.name, self.ranges[0], self.ranges[1]))
        headers = {'Range': 'bytes=%d-%d' % (self.start_point, self.ranges[1])}
        req = request.Request(url, headers=headers)
        urlHandler = request.urlopen(req)
        data = urlHandler.read(self.one_time_size)
        while data:
            file = open(self.output_path + self.file_name, 'ab+')
            file.write(data)
            file.close()
            self.downloaded += len(data)
            data = urlHandler.read(self.one_time_size)


def get_file_inof(url):
    """ 获取文件信息 """
    urlHandler = request.urlopen(url)
    headers = urlHandler.headers
    print(headers)
    file_name = url.split('/')[-1]
    file_size = 0
    for key in headers:
        if key.find('Length') != -1:
            file_size = headers[key]
            file_size = int(file_size)
        if key.find('name') != -1:
            file_name = headers[key]
    return file_name, file_size


def splite_blocks(file_size, block_num):
    """ 将数据划分为对个块，计算每块的范围 """
    block_size = file_size / block_num
    ranges = []
    for i in range(block_num):
        start = i * block_size
        end = start + block_size - 1
        if i == block_num - 1:
            end = file_size - 1
        ranges.append((start, end))
    return ranges


def islive(threads):
    for task in threads:
        if task.isAlive():
            return True
    return False


def download_file(url, output_path, blocks=8):
    """ 下载文件 """
    file_name, file_size = get_file_inof(url)
    # print(file_name, file_size)
    ranges = splite_blocks(file_size, blocks)
    # print(ranges)
    thread_name = ['thread_%d' % i for i in range(blocks)]
    tmpfile_name = [file_name + '.tmp%d' % i for i in range(blocks)]
    # print(thread_name)
    # print(tmpfile_name)
    threads = []
    for i in range(blocks):
        task = DownloadThread(
            thread_name[i], url, output_path, tmpfile_name[i], ranges[i])
        # task.setDamemon(True)
        task.start()
        threads.append(task)
    time.sleep(2)
    while islive(threads):
        downloaded = sum([task.downloaded for task in threads])
        process = downloaded / file_size * 100
        show = u'\rCompleted: %.2f%%' % process
        sys.stdout.write(show)
        sys.stdout.flush()
        time.sleep(0.5)

    with open(output_path + file_name, 'wb+')as file:
        for tmp_file in tmpfile_name:
            with open(output_path + tmp_file, 'rb') as f:
                file.write(f.read())
            try:
                os.remove(output_path + tmp_file)
            except OSError:
                pass

    os.remove(output_path + file_name)


if __name__ == "__main__":
    start = time.time()
    url = 'https://vscode.cdn.azure.cn/stable/5763d909d5f12fe19f215cbfdd29a91c0fa9208a/code_1.45.1-1589445302_amd64.deb'
    output_path = './Download/'
    download_file(url, output_path, blocks=10)
    end = time.time()
    print('\n%.2fs' % (end - start))
