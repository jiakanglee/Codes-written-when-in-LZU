import joblib
from sklearn.cluster import KMeans
from sklearn import neural_network
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
import sklearn
from sklearn import svm
from sklearn import datasets
import pandas as pd
import ssl
from datetime import datetime
from pandas import Series, DataFrame
from openpyxl.workbook import Workbook
import pickle
from sklearn2pmml import PMMLPipeline, sklearn2pmml

'''
#But before processing we are gonna drop ignore the X and Y coordinations for its not been pre_settled 
#data processing for organizing the data for each individual title
test = pd.read_excel('汇总表.xlsx')
test['ANSWER'] = test['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})  # 结果索引
test['EVAL'] = test['EVAL'].map({'很不认真':1,'不太认真':2,'一般':3,'比较认真':4,'非常认真':5})
test = test.drop(['USERNAME','SEX','AGE','EDU'], axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
test1 = test.groupby('ID')
test1 = test1.get_group(1)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title1.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(2)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title2.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(3)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title3.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(4)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title4.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(5)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title5.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(6)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title6.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(7)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title7.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(8)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title8.xlsx', sheet_name='Sheet2', index=False, header=True)
test1 = test.groupby('ID')
test1 = test1.get_group(9)
test1 = test1.reset_index()
DataFrame(test1).to_excel('title9.xlsx', sheet_name='Sheet2', index=False, header=True)
'''

#assume we've already got the data
test1 = pd.read_excel('title1.xlsx')
test1_target = test1['EVAL']
test1 = test1.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
test2 = pd.read_excel('title2.xlsx')
test2_target = test2['EVAL']
test2 = test2.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test3 = pd.read_excel('title3.xlsx')
test3_target = test3['EVAL']
test3 = test3.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test4 = pd.read_excel('title4.xlsx')
test4_target = test4['EVAL']
test4 = test4.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test5 = pd.read_excel('title5.xlsx')
test5_target = test5['EVAL']
test5 = test5.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test6 = pd.read_excel('title6.xlsx')
test6_target = test6['EVAL']
test6 = test6.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test7 = pd.read_excel('title7.xlsx')
test7_target = test7['EVAL']
test7 = test7.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test8 = pd.read_excel('title8.xlsx')
test8_target = test8['EVAL']
test8 = test8.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行
test9 = pd.read_excel('title9.xlsx')
test9_target = test9['EVAL']
test9 = test9.drop(["index",'ID','EVAL'], axis=1)  # axis=1 是跨列，axis=0 是跨行



#we start training each model
nw1 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=10000 ,tol=1e-4)
nw1.fit(test1,test1_target)
#print(accuracy_score(test1_y,nw1.predict(test1_x)))
nw2 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=5000 ,tol=1e-4)
nw2.fit(test2,test2_target)
#print(accuracy_score(test1_y,nw2.predict(test1_x)))
nw3 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw3.fit(test3,test3_target)
#print(accuracy_score(train11['predict'],nw1.predict(train3)))
nw4 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw4.fit(test4,test4_target)
#print(accuracy_score(train11['predict'],nw1.predict(train44)))
nw5 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw5.fit(test5,test5_target)
#print(accuracy_score(train11['predict'],nw1.predict(train5)))
nw6 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw6.fit(test6,test6_target)
#print(accuracy_score(train11['predict'],nw1.predict(train6)))
nw7 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw7.fit(test7,test7_target)
#print(accuracy_score(train11['predict'],nw1.predict(train7)))
nw8 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw8.fit(test8,test8_target)
#print(accuracy_score(train11['predict'],nw1.predict(train8)))
nw9 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw9.fit(test9,test9_target)
#print(accuracy_score(train11['predict'],nw1.predict(train9)))


#Then we start by combining each model to get a final
#but before that we are gonna create a pandas attribute-like dataframe with the nine network above to feed it in the API
df = pd.read_excel('汇总表.xlsx')
df['ANSWER'] = df['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})  # 结果索引
df['EVAL'] = df['EVAL'].map({'很不认真':1,'不太认真':2,'一般':3,'比较认真':4,'非常认真':5})
df = df.drop(['SEX','AGE','EDU'], axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
df = df.groupby("USERNAME")
data = []
test10_target = []
for name,group in df:
    temp = []
    temp.append(name)
    group = group.reset_index()
    group0 = group.loc[group['ID'] == 1]
    test10_target.append(group0['EVAL'])
    group = group.drop(['USERNAME','EVAL','index'], axis=1)
    group1 = group.loc[group['ID'] == 1]
    temp.append(nw1.predict(group1.drop(['ID'],axis = 1)))
    group2 = group.loc[group['ID'] == 2]
    temp.append(nw2.predict(group2.drop(['ID'],axis = 1)))
    group3 = group.loc[group['ID'] == 3]
    temp.append(nw3.predict(group3.drop(['ID'],axis = 1)))
    group4 = group.loc[group['ID'] == 4]
    temp.append(nw4.predict(group4.drop(['ID'],axis = 1)))
    group5 = group.loc[group['ID'] == 5]
    temp.append(nw5.predict(group5.drop(['ID'],axis = 1)))
    group6 = group.loc[group['ID'] == 6]
    temp.append(nw6.predict(group6.drop(['ID'],axis = 1)))
    group7 = group.loc[group['ID'] == 7]
    temp.append(nw7.predict(group7.drop(['ID'],axis = 1)))
    group8 = group.loc[group['ID'] == 8]
    temp.append(nw8.predict(group8.drop(['ID'],axis = 1)))
    group9 = group.loc[group['ID'] == 9]
    temp.append(nw9.predict(group9.drop(['ID'],axis = 1)))
    data.append(temp)
test10 = pd.DataFrame(data,columns = ['USERNAME','title1','title2','title3','title4','title5','title6','title7','title8','title9'])
test10 = test10.drop(['USERNAME'],axis = 1)

nw10 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw10.fit(test10,test10_target)
joblib.dump(nw10, 'neuralnetwork1.model')
joblib.dump
#首先我们在本地训练好模型，10个，然后我们对于新的数据传入模型进行训练得到预测值
def process_data(data1,data2,data3,data4,data5,data6,data7,data8,data9):




def predict(data):
    process_data(data)
    f = open('neuralnetwork.model1', 'rb')  # 注意此处model是rb
    s = f.read()
    network1 = pickle.loads(s)
    f = open('neuralnetwork.model2', 'rb')  # 注意此处model是rb
    s = f.read()
    network2 = pickle.loads(s)
    f = open('neuralnetwork.model3', 'rb')  # 注意此处model是rb
    s = f.read()
    network3 = pickle.loads(s)
    f = open('neuralnetwork.model4', 'rb')  # 注意此处model是rb
    s = f.read()
    network4 = pickle.loads(s)
    f = open('neuralnetwork.model5', 'rb')  # 注意此处model是rb
    s = f.read()
    network5 = pickle.loads(s)
    f = open('neuralnetwork.model6', 'rb')  # 注意此处model是rb
    s = f.read()
    network6 = pickle.loads(s)
    f = open('neuralnetwork.model7', 'rb')  # 注意此处model是rb
    s = f.read()
    network7 = pickle.loads(s)
    f = open('neuralnetwork.model8', 'rb')  # 注意此处model是rb
    s = f.read()
    network8 = pickle.loads(s)
    f = open('neuralnetwork.model9', 'rb')  # 注意此处model是rb
    s = f.read()
    network9 = pickle.loads(s)
    f = open('neuralnetwork.model10', 'rb')  # 注意此处model是rb
    s = f.read()
    network10 = pickle.loads(s)
    result = network10.predict()
