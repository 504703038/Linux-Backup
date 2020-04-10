from matplotlib import pyplot as plt
import numpy as np


def sigmoid(x):
    return 1.0 / (1 + np.exp(-x))


if __name__ == "__main__":
    nums = np.arange(-10, 10, step=1)
    fig, ax = plt.subplots(figsize=(8, 4))
    ax.plot(nums, sigmoid(nums), 'r')
    plt.show()
