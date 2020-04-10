import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def demo_1():
    print('demo 1:')
    a = tf.placeholder(dtype=tf.float32, shape=[None, None])
    b = tf.placeholder(dtype=tf.float32, shape=[None, 5])
    print('修改前：')
    print('a:', a)
    print('b:', b)
    a.set_shape([2, 5])
    b.set_shape([5, 5])
    print('修改后：')
    print('a:', a)
    print('b:', b)


def demo_2():
    print('demo 2:')
    a = tf.placeholder(dtype=tf.float32, shape=[3, 4])
    print('修改前：')
    print('a:', a)
    a = tf.reshape(a, shape=[2, 6])
    print('修改后：')
    print('a:', a)


if __name__ == "__main__":
    demo_1()
    demo_2()
