import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

if __name__ == "__main__":
    a = tf.constant(10)
    b = tf.constant(20)
    c = a + b
    print(c)
    with tf.Session() as sess:
        value = sess.run(c)
        print("value:", value)
