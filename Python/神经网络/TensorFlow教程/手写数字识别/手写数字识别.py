from tensorflow.examples.tutorials.mnist import input_data
import matplotlib.pyplot as plt
import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/手写数字识别/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def mnist_demo():
    # 1、准备数据
    with tf.variable_scope('prepare_data'):
        mnist = input_data.read_data_sets(cur_path + 'data/', one_hot=True)
        X = tf.placeholder(dtype=tf.float32, shape=[
                           None, 784], name='train_images')
        y = tf.placeholder(dtype=tf.float32, shape=[
                           None, 10], name='train_labels')

    # 2、构建模型
    with tf.variable_scope('create_mode'):
        weight = tf.Variable(initial_value=tf.random_normal(
            shape=[784, 10]), name='weight')
        bias = tf.Variable(
            initial_value=tf.random_normal(shape=[10]), name='bias')
        y_predict = tf.matmul(X, weight) + bias

    # ３、构建损失函数
    with tf.variable_scope('loss_function'):
        # 激活函数：softmax
        # 损失函数：交叉熵
        error = tf.reduce_mean(
            tf.nn.softmax_cross_entropy_with_logits(labels=y,
                                                    logits=y_predict))

    # 4、优化损失函数
    with tf.variable_scope('optimizer'):
        optimizer = tf.train.GradientDescentOptimizer(
            learning_rate=0.1).minimize(error)

    init = tf.global_variables_initializer()

    # 收集变量
    tf.summary.scalar('error', error)
    tf.summary.histogram('weight', weight)
    tf.summary.histogram('bias', bias)
    # 合并变量
    merge = tf.summary.merge_all()
    # 保存模型
    saver = tf.train.Saver()

    with tf.Session() as sess:
        # 初始化
        sess.run(init)
        # print('训练前损失：', sess.run(error, feed_dict={X: images, y: labels}))

        # 创建事件文件
        filter_writer = tf.summary.FileWriter(
            cur_path + '手写数字识别', graph=sess.graph)

        # 开始训练
        for i in range(10000):

            images, labels = mnist.train.next_batch(100)

            op, loss = sess.run([optimizer, error], feed_dict={
                X: images, y: labels})
            # 将变量写入事件文件
            summary = sess.run(merge, feed_dict={X: images, y: labels})
            filter_writer.add_summary(summary, i)

            if i % 100 == 0:
                saver.save(sess, cur_path+'./ckpt/mnist_demo.ckpt')
                print('第%d次训练的损失 loss 为: %f' % ((i + 1), loss))

        # 计算准确率
        curr_pre = tf.equal(tf.argmax(y, 1), tf.argmax(y_predict, 1))
        acc = tf.reduce_mean(tf.cast(curr_pre, tf.float32))
        print(sess.run(acc, feed_dict={
              X: mnist.test.images, y: mnist.test.labels}))


if __name__ == "__main__":
    mnist_demo()
