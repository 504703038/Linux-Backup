import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/线性回归案例/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


"""
线性回归原理:
1、构造模型
    y = w1*x1　+ w2*x2 + ... + wn*xn + b
2、损失函数
    均方误差
3、优化损失
    梯度下降
"""

"""
设计方案:
1、准备数据
    随机１００个点，只有一个特征，x和ｙ之间满足关系 y = kx _b
    X = (100,1)
    y = (100,1)
    数据分布满足 y = 0.8x + 0.7
    y_predict = tf.matual(X, weight) + bias
2、构造损失函数
    error = tf.reduce_mean(tf.square(y_predicty-y))
3、优化损失
    tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(error)
"""


def linear_regression():
    # １、准备数据
    X = tf.random_normal(shape=[100, 1])
    y = tf.matmul(X, [[0.8]]) + 0.7
    # 2、构建模型
    weight = tf.Variable(initial_value=tf.random_normal(shape=[1, 1]))
    bias = tf.Variable(initial_value=tf.random_normal(shape=[1]))
    y_predict = tf.matmul(X, weight) + bias
    # 3、构建损失函数
    error = tf.reduce_mean(tf.square(y_predict-y))
    # 4、优化损失函数
    optimizer = tf.train.GradientDescentOptimizer(
        learning_rate=0.01).minimize(error)

    init = tf.global_variables_initializer()
    with tf.Session() as sess:
        # 初始化
        sess.run(init)
        print('查看训练前模型参数:\n权重：%f，偏量：%f，损失：%f' %
              (weight.eval(), bias.eval(), error.eval()))
        # 开始训练
        for i in range(1000):
            sess.run(optimizer)
            if i % 100 == 0:
                print('训练第%d次后模型参数:\n权重：%f，偏量：%f，损失：%f' %
                      ((i+1), weight.eval(), bias.eval(), error.eval()))


if __name__ == "__main__":
    linear_regression()
