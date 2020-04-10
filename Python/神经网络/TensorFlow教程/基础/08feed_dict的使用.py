import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

if __name__ == "__main__":
    a = tf.placeholder(tf.float32)
    b = tf.placeholder('float32')
    c = a + b
    cc = tf.add(a, b)
    x = tf.placeholder(tf.float32, None)
    y = x * 20 + 100
    with tf.Session() as sess:
        c_value = sess.run(c, feed_dict={a: 10, b: 20})
        cc_value = sess.run(cc, feed_dict={a: 10, b: 20})
        print(c_value)
        print(cc_value)
        y_value = sess.run(y, feed_dict={x: [10, 20, 30, 40]})
        print(y_value)
