import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/线性回归案例/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def linear_regression():
    # １、准备数据
    with tf.variable_scope('prepare_data'):
        X = tf.random_normal(shape=[100, 1], name='feature')
        y = tf.matmul(X, [[0.8]]) + 0.7
    # 2、构建模型
    with tf.variable_scope('create_mode'):
        weight = tf.Variable(initial_value=tf.random_normal(
            shape=[1, 1]), name='weight')
        bias = tf.Variable(
            initial_value=tf.random_normal(shape=[1]), name='bias')
        y_predict = tf.matmul(X, weight) + bias
    # 3、构建损失函数
    with tf.variable_scope('loss_function'):
        error = tf.reduce_mean(tf.square(y_predict - y))
    # 4、优化损失函数
    with tf.variable_scope('optimizer'):
        optimizer = tf.train.GradientDescentOptimizer(
            learning_rate=0.01).minimize(error)

    init = tf.global_variables_initializer()
    # 收集变量
    tf.summary.scalar('error', error)
    tf.summary.histogram('weight', weight)
    tf.summary.histogram('bias', bias)
    # 合并变量
    merge = tf.summary.merge_all()

    with tf.Session() as sess:
        # 初始化
        sess.run(init)
        print('查看训练前模型参数:\n权重：%f，偏量：%f，损失：%f' %
              (weight.eval(), bias.eval(), error.eval()))

        # 创建事件文件
        fileWriter = tf.summary.FileWriter(
            cur_path+'15增加命名空间', graph=sess.graph)

        # 开始训练
        for i in range(1000):
            sess.run(optimizer)
            # 运行合并变量
            summary = sess.run(merge)
            # 将变量写入事件文件
            fileWriter.add_summary(summary, i)
            if i % 100 == 0:
                print('训练第%d次后模型参数:\n权重：%f，偏量：%f，损失：%f' %
                      ((i+1), weight.eval(), bias.eval(), error.eval()))


if __name__ == "__main__":
    linear_regression()
