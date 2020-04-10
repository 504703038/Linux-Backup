import tensorflow as tf
import numpy as np
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

if __name__ == "__main__":
    sess = tf.Session()
    A = tf.random_uniform([3, 2])
    B = tf.fill([2, 4], 3.5)
    C = tf.random_normal([3, 4])
    print('A:\n', sess.run(A))
    print('B:\n', sess.run(B))
    print('C:\n', sess.run(C))
    print('A*B:\n', sess.run(tf.matmul(A, B)))
    print('A*B+C:\n', sess.run(tf.matmul(A, B)+C))
