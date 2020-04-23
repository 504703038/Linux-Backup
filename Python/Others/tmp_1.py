import time
from selenium import webdriver
cur_path = './Others/'
if __name__ == "__main__":
    with open(cur_path + 'tmp.txt') as file:
        content = file.readlines()
    for line in content:
        # tmp = line.split(' ')
        # print(tmp)
        (adress, port, password, method) = line.split(' ')
        method = method[:-1]
        print('{')
        print('"method": "{}",'.format(method))
        print('"password": "{}",'.format(password))
        print('"remarks": "1",')
        print('"server": "{}",'.format(adress))
        print('"server_port": {}'.format(port))
        print('},')
