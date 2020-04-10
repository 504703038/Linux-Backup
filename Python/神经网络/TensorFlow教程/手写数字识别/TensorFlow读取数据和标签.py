from tensorflow.examples.tutorials.mnist import input_data
import matplotlib.pyplot as plt
import os
# import tensorflow

# 当前文件路径
cur_path = './神经网络/TensorFlow教程/手写数字识别/'
# 不提示警告信息
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

if __name__ == "__main__":
    mnist = input_data.read_data_sets(cur_path + 'data/', one_hot=True)
    # load images
    train_X = mnist.train.images
    validation_X = mnist.validation.images
    test_X = mnist.test.images
    # load labels
    train_y = mnist.train.labels
    validation_y = mnist.validation.labels
    test_y = mnist.test.labels

    # 输出训练集样本和标签的大小
    print(train_X.shape, train_y.shape)
    # 查看训练集中第一个样本的 image 和 label
    print(train_X[0])
    print(train_y[0])
    # 获取数据集中的１００行
    image, label = mnist.train.next_batch(100)
    print(image.shape, label.shape)

    # 可视化样本，提取训练集中前２０个样本
    fig, ax = plt.subplots(nrows=4, ncols=5, sharex='all', sharey='all')
    ax = ax.flatten()
    for i in range(20):
        img = train_X[i].reshape(28, 28)
        ax[i].imshow(img, cmap='Greys')
    ax[0].set_xticks([])
    ax[0].set_yticks([])
    plt.tight_layout()
    plt.show()
