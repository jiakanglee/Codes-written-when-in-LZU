import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from datetime import datetime
from pandas import Series,DataFrame
import warnings
warnings.filterwarnings('ignore', 'statsmodels.tsa.arima_model.ARMA',
                        FutureWarning)
warnings.filterwarnings('ignore', 'statsmodels.tsa.arima_model.ARIMA',
                        FutureWarning)
data = pd.read_excel('testdf.xlsx',index_col= u'日期')
data.index = pd.DatetimeIndex(data.index).to_period()
data1 = pd.read_excel('testdf1.xlsx',index_col = u'日期')
forecastnum = 5
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
data.plot()
data1.plot()
plt.show()
#以上是画时序图
from statsmodels.graphics.tsaplots import plot_acf
plot_acf(data).show()
#以上是自相关图
from statsmodels.tsa.stattools import adfuller as ADF
#print(u'原始序列的ADF检验结果为：', ADF(data[u'确诊总人数']))
#原始序列的ADF检验结果为： (-3.7667177304726867, 0.003266793578451666, 9, 19, {'1%': -3.8326031418574136, '5%': -3.0312271701414204, '10%': -2.655519584487535}, 114.61375882813807)
#得出的结论是不平稳
D_data = data.diff().dropna()
D_data.columns = [u'确诊总人数差分']
#差分后的结果
D_data.plot()
plt.show()
#时序图
plot_acf(D_data).show()
plt.show()
#自相关图
from statsmodels.graphics.tsaplots import plot_pacf

#偏自相关图

#plot_pacf(D_data).show()
#平稳性检测
#print(u'差分序列的ADF检验结果为：', ADF(D_data[u'确诊总人数差分']))
#差分序列的ADF检验结果为： (-1.2113874732141632, 0.6686780253791897, 9, 18, {'1%': -3.859073285322359, '5%': -3.0420456927297668, '10%': -2.6609064197530863}, 123.53995327978535)
#from statsmodels.stats.diagnostic import acorr_ljungbox
#print(u'差分序列的白噪声检验结果为：', acorr_ljungbox(D_data, lags=1))
#差分序列的白噪声检验结果为： (array([15.83641633]), array([6.90605033e-05]))
from statsmodels.tsa.arima_model import ARIMA
#定阶

#一般阶数不超过length/10

pmax = int(len(data)/30)

#一般阶数不超过length/10

qmax = int(len(data)/20)

#bic矩阵

bic_matrix = []
for p in range(pmax+1):
    tmp = []
    for q in range(qmax+1):
        try:
            tmp.append(ARIMA(data,(p,1,q)).fit().bic)
        except:
            tmp.append(None)
    bic_matrix.append(tmp)
#从中可以找出最小值

bic_matrix = pd.DataFrame(bic_matrix)

#先用stack展平，然后用idxmin找出最小值位置。

p,q = bic_matrix.stack().idxmin()


print(u'BIC最小的p值和q值为：%s、%s' %(p,q))

#取BIC信息量达到最小的模型阶数，结果p为0，q为1，定阶完成。

 #建立ARIMA(0, 1, 1)模型

model = ARIMA(data, (p,1,q)).fit(disp =0)

#给出一份模型报告

print(model.summary2())

#作为期5天的预测，返回预测结果、标准误差、置信区间。

print(model.forecast(20))