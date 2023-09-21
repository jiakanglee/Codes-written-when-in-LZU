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

test = pd.read_excel("B题数据处理.xlsx")
x_train = test[['Co负载量/%', "SiO2质量/mg", "HAP质量/mg", "乙醇浓度/ml/min","温度/℃",'装料方式']]
y_train1 = test['乙醇转化率/%']
y_train2 = test['C4烯烃选择性/%']
standard_scaler = preprocessing.StandardScaler()
data = test.iloc[:120, 0:6].copy().values
x_train = standard_scaler.fit_transform(data)
#svr = GridSearchCV(SVR(),
#                   param_grid={"kernel": ("linear", 'rbf'), "C": np.logspace(-3, 3, 7), "gamma": np.logspace(-3, 3, 7)})
svr = SVR(kernel='poly',C = 0.5,gamma = 0.44,degree=7)
#0.7,0.7,7，C4烯烃选择性的参数0.9062159192832485
#0.9939985963848074乙醇
#0.9674582421276634C4烯烃选择性
'''
28.845934494901833
21.63386429125804
6.7581782015125755
4.225573153194718
13.935904993600978
'''
svr.fit(x_train, y_train2)
print(svr.score(x_train,y_train2))

#画拟合曲线

y1 = y_train2
y2 = svr.predict(x_train)

x = np.arange(1,115,1)
plt.figure(num = 3,figsize = (8,5))
plt.plot(x,y1,color = 'red',marker = "o")
plt.plot(x,y2,color = 'blue',marker = "x")
plt.tick_params(labelsize = 16)
plt.xlabel('数据点',fontsize = 16)
plt.ylabel('C4烯烃选择性/%',fontsize = 16)
plt.rcParams['font.family'] = ['sans-serif']
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.legend(['数据点','预测点'],loc = 'upper center',fontsize = 16,frameon=False,ncol=2)
plt.ylim(-5,65)
plt.show()



'''
#LIME 
#categorical_features = np.argwhere(np.array([len(set(x_train[:,x])) for x in range(x_train.shape[1])]) <= 10).flatten()
explainer = lime.lime_tabular.LimeTabularExplainer(x_train, mode = 'regression',feature_names=['Co负载量/%', "SiO2质量/mg", "HAP质量/mg", "乙醇浓度/ml/min","装料方式", "温度/℃"],class_names=['C4烯烃选择性/%'],verbose=True)
# 对局部点的解释
X_train, X_test, y_train, y_test = train_test_split(x_train, y_train2, train_size=1)
#    row = test.iloc[i:i+1, :]
#    row = np.array(row)
#    print(row)
#exp = explainer.explain_instance(X_test[5],svr.predict, num_features=6)

w_Ethanol_concentration = 0
w_Co_ratio = 0
w_Temperature = 0
w_SiO2_quality = 0
w_HAP_quality = 0
w_load_mode = 0
for i in range(len(X_test)):
    exp = explainer.explain_instance(X_test[i],svr.predict, num_features=6)
    for t in exp.as_list():
        a = t[0]
        b = t[1]
        if '乙醇浓度/ml/min' in a:
                w_Ethanol_concentration+=abs(b)
        if '装料方式' in a:
                w_load_mode+=abs(b)
        if '温度/℃' in a:
                w_Temperature+=abs(b)
        if 'Co负载量/%' in a:
                w_Co_ratio+=abs(b)
        if 'SiO2质量/mg' in a:
                w_SiO2_quality+=abs(b)
        if 'HAP质量/mg'  in a:
                w_HAP_quality+=abs(b)
for i in range(len(X_train)):
    exp = explainer.explain_instance(X_train[i],svr.predict, num_features=6)
    for t in exp.as_list():
        a = t[0]
        b = t[1]
        if '乙醇浓度/ml/min' in a:
            w_Ethanol_concentration += abs(b)
        if '装料方式' in a:
            w_load_mode += abs(b)
        if '温度/℃' in a:
            w_Temperature += abs(b)
        if 'Co负载量/%' in a:
            w_Co_ratio += abs(b)
        if 'SiO2质量/mg' in a:
            w_SiO2_quality += abs(b)
        if 'HAP质量/mg' in a:
            w_HAP_quality += abs(b)

# 显示详细信息图
#exp.show_in_notebook(show_table=True, show_all=True)
# 显示权重图
print(w_Co_ratio/114)
print(w_SiO2_quality/114)
print(w_HAP_quality/114)
print(w_Ethanol_concentration/114)
print(w_Temperature/114)
print(w_load_mode/114)


乙醇转化率
R² = 0.9839292429282409
15.730105907979919
1.5014371339519907
5.8811556553277144
3.210122797249917
16.35613348543188
3.270209924114499
C4烯烃选择性
R² = 0.9387308266133269
9.289702586824621
3.560586936222455
2.072701472933637
1.7697485208207504
10.110632569599389
7.228767919974367
'''

'''
from IPython.display import HTML
#exp.save_to_file("classif_explanation.html")
#plt.rcParams['font.family'] = ['sans-serif']
#plt.rcParams['font.sans-serif'] = ['SimHei']
#plt1 = exp.as_pyplot_figure()
#plt1.show()
'''