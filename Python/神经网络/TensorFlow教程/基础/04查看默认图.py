import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

if __name__ == "__main__":
    print(tf.get_default_graph())
    a = tf.constant(10)
    print(a.graph)
    b = tf.constant(20)
    print(b.graph)
    c = a + b
    print(c.graph)

    with tf.Session() as sess:
        c_value = sess.run(c)
        print(sess.graph)
        print(c_value)
