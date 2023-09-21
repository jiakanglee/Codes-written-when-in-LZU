import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from datetime import datetime
from pandas import Series,DataFrame
data2 = pd.read_excel('testdf1.xlsx')
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
data2.plot(label = 'Arima预测确诊总人数')
plt.show()