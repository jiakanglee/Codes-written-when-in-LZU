import AHP
from AHP import AHP1
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from datetime import datetime
from pandas import Series,DataFrame
df  =  pd.read_excel('判断矩阵.xlsx')
df2 = pd.read_excel('14天新增标准化.xlsx')
df2 = np.array(df2[['confirmed','14天新增人数','density','pergdp']])
df2 = np.transpose(df2)
df = np.array(df)
t = AHP1(df)
a = t.get_eig()
result = np.dot(df,df2)
dataf = pd.DataFrame(result)
print(result)