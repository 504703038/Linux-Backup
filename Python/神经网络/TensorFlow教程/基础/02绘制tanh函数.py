import matplotlib.pyplot as plt
import numpy as np

if __name__ == "__main__":
    x = np.linspace(-10, 10, 100)
    y = np.tanh(x)
    plt.plot(x, y)
    plt.show()
