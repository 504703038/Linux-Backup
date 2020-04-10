import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def event_demo():
    a = tf.constant(10)
    b = tf.constant(20)
    c = a + b
    print(c)
    with tf.Session() as sess:
        c_value = sess.run(c)
        print(c_value)
        print(sess.graph)
        writer = tf.summary.FileWriter(
            cur_path + '06图的可视化', graph=tf.get_default_graph())
        writer.close()


if __name__ == "__main__":
    event_demo()
