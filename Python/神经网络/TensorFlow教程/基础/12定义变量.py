import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# 定义一个变量
# tf.Variable(inital_value=None,
#             trainable=None,
#             collections=None,
#             validate_shape=True,
#             caching+device=None,
#             name=None)


def create_variable():
    x = tf.constant([1, 2, 3, 4])
    y = tf.Variable(x * 2 + 10)
    # 初始化变量
    model = tf.global_variables_initializer()
    with tf.Session() as sess:
        # 运行初始化
        sess.run(model)
        print(sess.run(y))


def change_spacename():
    # 默认命名空间
    x = tf.constant(10)
    # 自定义命名空间
    with tf.variable_scope('my_scope'):
        y = tf.constant(20)
    print(x)
    print(y)


if __name__ == "__main__":
    # 定义变量
    create_variable()
    # 修改命名空间
    change_spacename()
