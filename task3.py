import numpy as np
import matplotlib.pyplot as plt
data=np.loadtxt("file3.txt")
data2=np.loadtxt("file33.txt")
plt.plot(data[:,0],data[:,1])
plt.plot(data2[:,0],data2[:,1], 'o')
plt.grid(True)
plt.show()

