import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def demo_1():
    print('demo 1:')
    tensor1 = tf.constant(5.0)
    tensor2 = tf.constant([1, 2, 3, 4, 5])
    tensor3 = tf.constant([[1, 2], [3, 4]])
    print(tensor1)
    print(tensor2)
    print(tensor3)
    with tf.Session() as sess:
        value_1 = sess.run(tensor1)
        value_2 = sess.run(tensor2)
        value_3 = sess.run(tensor3)
        print(value_1)
        print(value_2)
        print(value_3)


def demo_2():
    print('demo 2:')
    # 全为1的张量
    tensor1 = tf.ones(shape=[1, 2, 3])
    # 全为0的张量
    tensor2 = tf.zeros(shape=[3, 4])
    # 均匀分布
    tensor3 = tf.random_uniform([2, 3], minval=0, maxval=4)
    # 标准差的正太分布
    tensor4 = tf.random_normal([2, 3], mean=5, stddev=4)
    with tf.Session() as sess:
        value_1 = sess.run(tensor1)
        value_2 = sess.run(tensor2)
        value_3 = sess.run(tensor3)
        value_4 = sess.run(tensor4)
        print(value_1)
        print(value_2)
        print(value_3)
        print(value_4)


if __name__ == "__main__":
    demo_1()
    demo_2()
