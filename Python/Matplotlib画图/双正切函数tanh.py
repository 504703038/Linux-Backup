import numpy as np
import matplotlib.pyplot as plt


# tanh函数 tanh(x) = sinh(x)/cosh(x) = (e^x-e^(-x))/(e^x+e^(-x))
# def tanh(x):
#     return (np.exp(x) - np.exp(-1)) / (np.exp(x) + np.exp(-1))


x = np.linspace(-10.0, 10.0, 100)
flg, ax = plt.subplots(figsize=(8, 4))
ax.plot(x, np.tanh(x), 'r')
plt.show()
