import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from pyparsing import alphas

np.random.seed(42)

def binomial_tree(mu, sigma, S0, N, T, step):
    # compute state price and probability
    u = np.exp(sigma * np.sqrt(step))
    d = 1.0 / u
    p = 0.5 + 0.5 * (mu / sigma) * np.sqrt(step)

    # binomial tree simulation
    up_times = np.zeros((N, len(T)))
    down_times = np.zeros((N, len(T)))
    for idx in range(len(T)):
        up_times[:, idx] = np.random.binomial(T[idx] / step, p, N)
        down_times[:, idx] = T[idx] / step - up_times[:, idx]

    # compute terminal price
    ST = S0 * u ** up_times * d ** down_times

    return ST

def plot(ST):
    #generate plots
    plt.figure()
    plt.plot(ST[:, 0], color='b', alpha=0.5, label='1 month horizon')
    plt.plot(ST[:, 1], color='r', alpha=0.5, label='1 year horizon')
    plt.xlabel('time step, day')
    plt.ylabel('price')
    plt.title('Binomial-Tree Stock Simulation')
    plt.legend()
    plt.show()

    plt.figure()
    plt.plot(ST[:, 0], color='b', alpha=0.5, label='1 month horizon')
    plt.plot(ST[:, 1], color='r', alpha=0.5, label='1 year horizon')
    plt.xlabel('price')
    plt.ylabel('count')
    plt.title('Binomial-Tree Stock Simulation')
    plt.legend()
    plt.show()

if __name__ == "__main__":
    #model parameters
    mu = 0.1
    sigma = 0.15
    S0 = 1

    N = 10000
    T = [21.0 / 252, 1.0]
    step = 1.0 / 252

    cal_values = binomial_tree(mu, sigma, S0, N, T, step)
    plot(cal_values)