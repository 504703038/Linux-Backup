import xlrd
import xlwt
cur_path = './Others/'


def read():
    # 打开excel
    readbook = xlrd.open_workbook(cur_path+'tmp.xlsx')
    # 读取文件sheet
    sheet: xlrd.sheet.Sheet
    sheet = readbook.sheet_by_index(2)  # 通过索引，索引从0开始
    sheet = readbook.sheet_by_name('Sheet1')  # 通过名称，区分大小写
    # 获取sheet的最大行数和列数
    nrows = sheet.nrows
    ncols = sheet.ncols
    print(nrows, ncols)
    # 获取某个单元格的值
    value = sheet.cell(0, 0).value
    print(value)
    # 获取某一列
    row = sheet.row(0)
    # 获取某一行
    col = sheet.col(0)
    print(row)
    print(col)


def write():
    # 打开一个excel
    writebook = xlwt.Workbook()
    # 添加一个sheet
    sheet: xlwt.Worksheet
    sheet = writebook.add_sheet('Sheet1')
    # 将数据写入单元格
    value = 'test'
    # 将数据写入第0行0列的单元格
    sheet.write(0, 0, value)
    # 保存
    writebook.save(cur_path+'tmp_1.xlsx')


if __name__ == "__main__":
    read()
    write()
