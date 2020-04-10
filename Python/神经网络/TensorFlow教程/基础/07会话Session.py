import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


def sess_demo():
    a = tf.constant(10)
    b = tf.constant(20)
    c = a + b
    print(c)
    config = tf.ConfigProto(allow_soft_placement=True,
                            log_device_placement=True)
    with tf.Session(config=config) as sess:
        values = sess.run([a, b, c])
        print(values)
        c_value = c.eval()
        print(c_value)


if __name__ == "__main__":
    sess_demo()
