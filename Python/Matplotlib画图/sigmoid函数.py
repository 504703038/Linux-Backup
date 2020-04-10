import numpy as np
import matplotlib.pyplot as plt


# sigmoid函数
def sigmoid(x):
    return 1/(1+np.exp(-x))


x = np.arange(-10, 10)
flg, ax = plt.subplots(figsize=(8, 4))
ax.plot(x, sigmoid(x), 'r')
plt.show()
