import sklearn
import sklearn.datasets
import sklearn.ensemble
import numpy as np
import lime
import lime.lime_tabular
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPRegressor
from sklearn.model_selection import GridSearchCV
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn.preprocessing import MinMaxScaler
from sklearn.svm import SVR
from pandas import DataFrame
combination = [[1,198,200,1.68,1],[2,196,200,1.68,1],[1,198,200,0.9,1],[2,196,200,0.3,1],[5,190,200,1.68,1],[1,49.5,50,0.3,1],[1,49.5,50,0.9,1],[1,49.5,50,2.1,1],[2,47.6,50,2.1,1],[1,139.5,0.1,1.68,1],[1,49.5,50,1.68,1],[1,66.3,33,1.68,1],[1,32.7,67,1.68,1],[1,49.5,50,1.68,2],[1,99,100,1.68,2],[1,9.9,10,1.68,2],[1,24.8,25,1.68,2],[1,49.5,50,2.1,2],[1,74.3,75,1.68,2],[1,99,100,0.9,2],[0.5,199,200,1.68,1]]
test = pd.read_excel("B题数据处理.xlsx")
x_train = test[['Co负载量/%', "SiO2质量/mg", "HAP质量/mg", "乙醇浓度/ml/min", "温度/℃","装料方式"]]
data = []
for i in combination:
    for t in range(250,455,5):
        i_temp = i.copy()
        i_temp.append(t)
        data.append(i_temp)

df = pd.DataFrame(data,columns=['Co负载量/%', "SiO2质量/mg", "HAP质量/mg", "乙醇浓度/ml/min", "装料方式","温度"],dtype=float)
DataFrame(df).to_excel('test.xlsx', index=False, header=True)

y_train1 = test['乙醇转化率/%']
y_train2 = test['C4烯烃选择性/%']
y_train3 = test['C4烯烃收率/%']
standard_scaler = preprocessing.StandardScaler()
data = test.iloc[:120, 0:6].copy().values
data1 = df.iloc[:,:].copy().values
x_test = standard_scaler.fit_transform(data1)
x_train = standard_scaler.fit_transform(data)
param = {'criterion':['gini'],'max_depth':[30,50,60,100],'min_samples_leaf':[2,3,5,10],'min_impurity_decrease':[0.1,0.2,0.5]},
         #{'criterion':['gini','entropy']},
        # {'max_depth': [30,60,100], 'min_impurity_decrease':[0.1,0.2,0.5]}
#svr = GridSearchCV(SVR(), param_grid={"kernel": ["linear"], "C": np.logspace(-3,3 , 7), "gamma": np.logspace(-3,3, 7)})
svr = SVR(kernel='poly',C = 0.7,gamma = 0.44,degree = 7)
np.set_printoptions(suppress=True)
svr.fit(x_train,y_train3)
print(svr.dual_coef_)
#result = svr.predict(x_train)
#result = pd.DataFrame(result)
#DataFrame(result).to_excel('C4烯烃收率预测结果.xlsx', index=False, header=True)

#print(svr.score(x_train,y_train3))
#print(svr.predict(x_train))
#result = svr.predict(x_test)
#print((result).max())
#print(np.argmax(result))
'''
#画拟合曲线


y1 = y_train3
y2 = svr.predict(x_train)

x = np.arange(1,115,1)
plt.figure(num = 3,figsize = (8,5))
plt.plot(x,y1,color = 'red',marker = "o")
plt.plot(x,y2,color = 'blue',marker = "x")
plt.tick_params(labelsize = 16)
plt.xlabel('数据点',fontsize = 16)
plt.ylabel('C4烯烃收率/%',fontsize = 16)
plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.legend(['数据点','预测点'],loc = 'upper center',fontsize = 16,frameon=False,ncol=2)
plt.ylim(-5,55)
plt.show()

'''