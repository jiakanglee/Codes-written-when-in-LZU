import pandas as pd
import numpy as np
from pandas import DataFrame
test = pd.read_excel("B题数据处理.xlsx")
x_train = test[['Co负载量/%',"SiO2质量/mg","HAP质量/mg","乙醇浓度/ml/min","温度/℃","装料方式"]]
y_train1 =test['乙醇转化率/%']
y_train2 =test['C4烯烃选择性/%']
#标准化数据，这里一行代码处理简直玄学
data = x_train
data = (data - data.min())/(data.max() - data.min())
m,n=data.shape
#第一步读取文件，如果未标准化，则标准化
data.fillna(0.5)
data=np.array(data)
#将dataframe格式转化为matrix格式
k=1/np.log(m)
yij=data.sum(axis=0)
pij=data/yij
#第二步，计算pij
test=pij*np.log(pij)
test=np.nan_to_num(test)
ej=-k*(test.sum(axis=0))
#计算每种指标的信息熵
wi=(1-ej)/np.sum(1-ej)
print(wi)
