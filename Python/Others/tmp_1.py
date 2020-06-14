cur_path = './Others/'


def get_data():
    with open(cur_path + 'tmp.txt', 'r') as file:
        lines = file.readlines()
    data = []
    for line in lines:
        lis = line.split('\t')
        data.append({
            'ip': lis[1],
            'port': lis[2],
            'method': lis[3],
            'password': lis[4]
        })
    return data


def creat_config(data):
    with open(cur_path + 'gui-config.json', 'w') as file:
        file.write('{\n')
        file.write('\t"configs": [\n')
        for i in range(len(data)):
            file.write('\t\t{\n')
            tmp = data[i]
            file.write('\t\t\t"method": "' + tmp['method'] + '", \n')
            file.write('\t\t\t"password": "' + tmp['password'] + '",\n')
            file.write('\t\t\t"remarks": "' + str(i) + '", \n')
            file.write('\t\t\t"server": "' + tmp['ip'] + '",\n')
            file.write('\t\t\t"server_port": ' + tmp['port'] + ' \n')
            if i == len(data) - 1:
                file.write('\t\t}\n')
            else:
                file.write('\t\t},\n')

        file.write('\t],\n')
        file.write('\t"localPort": 8888,\n')
        file.write('\t"shareOverLan": false\n')
        file.write('}\n')


if __name__ == "__main__":
    data = get_data()
    creat_config(data)
