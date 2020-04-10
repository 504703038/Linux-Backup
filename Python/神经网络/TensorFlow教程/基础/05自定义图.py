import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def graph_demo():
    # 默认图
    a = tf.constant(10)
    b = tf.constant(20)
    c = a + b

    with tf.Session() as sess:
        c_value = sess.run(c)
        print('默认图：', sess.graph)
        print(c_value)
    # 自定义图
    new_g = tf.Graph()
    with new_g.as_default():
        a_new = tf.constant(100)
        b_new = tf.constant(200)
        c_new = a_new + b_new
    with tf.Session(graph=new_g) as sess:
        c_new_value = sess.run(c_new)
        print('自定义图：', sess.graph)
        print(c_new_value)


if __name__ == "__main__":
    graph_demo()
