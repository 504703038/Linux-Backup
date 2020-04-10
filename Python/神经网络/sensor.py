from numpy import array, exp, random, dot
# 训练样本
# X输入数据集，y输出数据集
X = array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
y = array([[0, 1, 1, 0]]).T
# 随机初始权值
random.seed(1)
W = 2 * random.random((3, 1)) - 1
# 迭代10000次调整权值
for it in range(10000):
    # 计算输出
    # sigmoid激活函数 f(x) = 1/(1+e^(-x))
    output = 1 / (1 + exp(-dot(X, W)))
    # 计算误差
    error = y - output
    # 调整权重
    # sigmoid激活函数的导数 f'(x) = f(x)*(1-f(x))
    delta = error * (output * (1 - output))
    W += dot(X.T, delta)
# print(W)
# 进行测试
print(1 / (1 + exp(-dot([[1, 0, 0]], W))))

# 训练样本
#   A B C D
# a 0 1 1 0
# b 0 1 0 1
# c 1 1 1 1
#
# 测试数据
#   A B C D
# d 1 0 0 ?
#
