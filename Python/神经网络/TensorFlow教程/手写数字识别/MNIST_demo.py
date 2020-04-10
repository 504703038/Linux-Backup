from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
import os

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/手写数字识别/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


class Mnist(object):
    def __init__(self):
        self.load_data()
        self.create_mode()

    # 准备数据
    def load_data(self):
        with tf.variable_scope('prepare_data'):
            self.mnist = input_data.read_data_sets(
                cur_path + 'data/', one_hot=True)
            self.X = tf.placeholder(dtype=tf.float32, shape=[
                None, 784], name='train_images')
            self.y = tf.placeholder(dtype=tf.float32, shape=[
                None, 10], name='train_labels')

    # 构建模型
    def create_mode(self):
        # 构建模型
        with tf.variable_scope('create_mode'):
            self.weight = tf.Variable(initial_value=tf.random_normal(
                shape=[784, 10]), name='weight')
            self.bias = tf.Variable(
                initial_value=tf.random_normal(shape=[10]), name='bias')
            self.y_predict = tf.matmul(self.X, self.weight) + self.bias

        # 损失函数
        with tf.variable_scope('loss_function'):
            # 激活函数：softmax
            # 损失函数：交叉熵
            self.error = tf.reduce_mean(
                tf.nn.softmax_cross_entropy_with_logits(labels=self.y,
                                                        logits=self.y_predict))

        # 优化
        with tf.variable_scope('optimizer'):
            self.optimizer = tf.train.GradientDescentOptimizer(
                learning_rate=0.1).minimize(self.error)

        # 准确率
        predict = tf.equal(tf.argmax(self.y, 1),
                           tf.argmax(self.y_predict, 1))
        self.accurate = tf.reduce_mean(tf.cast(predict, tf.float32))

        # 模型初始化
        self.sess = tf.Session()
        self.sess.run(tf.global_variables_initializer())
        self.saver = tf.train.Saver()

    # 训练模型
    def train(self):
        # print('Start training.')
        for i in range(1000):
            images, labels = self.mnist.train.next_batch(100)
            op, loss = self.sess.run([self.optimizer, self.error], feed_dict={
                self.X: images, self.y: labels})
            # 保存模型
            if i % 100 == 0:
                # 保存模型
                self.saver.save(self.sess, cur_path +
                                'ckpt/mnist_demo.ckpt')

    # 测试模型
    def test(self):
        # print('Start test.')
        acc = 0
        images = self.mnist.test.images
        labels = self.mnist.test.labels
        acc = self.sess.run(self.accurate, feed_dict={
            self.X: images, self.y: labels})
        return acc

    # 保存模型
    def save(self, path):
        self.saver.save(self.sess, path+'mnist_demo.ckpt')

    # 读取模型
    def restore(self, path):
        ckpt = tf.train.get_checkpoint_state(path)
        if ckpt and ckpt.model_checkpoint_path:
            self.saver.restore(self.sess, path+'mnist_demo.ckpt')

    def __del__(self):
        self.sess.close()


if __name__ == "__main__":
    path = cur_path + 'ckpt/'

    # 训练并保存模型
    # mnist_1 = Mnist()
    # mnist_1.train()
    # mnist_1.save(path)

    # 读取并测试模型
    mnist_2 = Mnist()
    mnist_2.restore(path)
    acc = mnist_2.test()
    print(acc)
