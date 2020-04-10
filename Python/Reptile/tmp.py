if __name__ == "__main__":
    with open('./Others/tmp.txt', 'r') as file:
        content = file.readlines()
    with open('./Others/tmp.html', 'w') as file:
        for line in content:
            vdriver, vchrome = line.split(' ')
            vchrome = vchrome[:-1]
            file.write('<option vchrome="' + vchrome + '" vdriver="' +
                       vdriver + '">' + vchrome + '</option>\n')
