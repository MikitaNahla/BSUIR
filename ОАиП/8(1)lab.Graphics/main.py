import numpy as np
import matplotlib.pyplot as plt
y = lambda x: (1-x*x/2)*np.cos(x)-x*np.sin(x)/2
setka = plt.subplots()
x = np.linspace(-50, 50, 400)
plt.plot(x, y(x))
plt.show()