import sys
import matplotlib.pyplot as plt
import pandas as pd

try:
    df = pd.read_csv('validate.csv', header=None)
except:
    print("Could not find file: 'validate.csv'")
    sys.exit(-1)

df.plot(x=1, y=3, label="Mohr's circle")

plt.xlabel('$\sigma_x$')
plt.ylabel('$\\tau_{xy}$')
plt.grid(True)
plt.axis('equal')
plt.show()
