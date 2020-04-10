import tensorflow as tf

if __name__ == "__main__":
    a = tf.constant(10)
    b = tf.constant(20)
    c = a + b
    print(c)
    with tf.Session() as sess:
        value = sess.run(c)
        print("value:", value)
