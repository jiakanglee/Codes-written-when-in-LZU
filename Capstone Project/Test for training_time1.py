import sklearn
from sklearn import svm
from sklearn import datasets
import pandas as pd
import ssl
from datetime import datetime
from pandas import Series, DataFrame
from openpyxl.workbook import Workbook

# data processsing
'''time0 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/01/t_time.xls')  # 导入数据
time1 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/02/t_time.xls')
time2 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/03/t_time.xls')
time3 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/04/t_time.xls')
time4 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/05/t_time.xls')
time5 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/06/t_time.xls')
time6 = pd.read_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/07/t_time.xls')
time0['ANSWER'] = time0['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})  # 结果索引
time1['ANSWER'] = time1['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
time2['ANSWER'] = time2['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
time3['ANSWER'] = time3['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
time4['ANSWER'] = time4['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
time5['ANSWER'] = time5['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
time6['ANSWER'] = time6['ANSWER'].map({'没有': 1, '有几天': 2, '一半以上时间': 3, '几乎天天': 4})
test = pd.concat([time0, time1, time2, time3, time4, time5, time6], axis=0)

# 第一题的模型训练
test1 = test.loc[test['ID'] == 1]  # 取出ID为1的test中的行
DataFrame(test1).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test1.xlsx', sheet_name='Sheet1', index=False, header=True)
test1 = test1.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train1 = test1.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第二题的模型训练
test2 = test.loc[test['ID'] == 2]  # 取出ID为2的test中的行
DataFrame(test2).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test2.xlsx', sheet_name='Sheet1', index=False, header=True)
test2 = test2.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train2 = test2.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第三题的模型训练
test3 = test.loc[test['ID'] == 3]  # 取出ID为3的test中的行
DataFrame(test3).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test3.xlsx', sheet_name='Sheet1', index=False, header=True)
test3 = test3.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train3 = test3.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第四题的模型训练
test4 = test.loc[test['ID'] == 4]  # 取出ID为4的test中的行
DataFrame(test4).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test4.xlsx', sheet_name='Sheet1', index=False, header=True)
test4 = test4.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train4 = test4.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第五题的模型训练
test5 = test.loc[test['ID'] == 5]  # 取出ID为5的test中的行
DataFrame(test5).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test5.xlsx', sheet_name='Sheet1', index=False, header=True)
test5 = test5.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train5 = test5.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第六题的模型训练
test6 = test.loc[test['ID'] == 6]  # 取出ID为6的test中的行
DataFrame(test6).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test6.xlsx', sheet_name='Sheet1', index=False, header=True)
test6 = test6.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train6 = test6.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第七题的模型训练
test7 = test.loc[test['ID'] == 7]  # 取出ID为7的test中的行
DataFrame(test7).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test7.xlsx', sheet_name='Sheet1', index=False, header=True)
test7 = test7.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train7 = test7.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第八题的模型训练
test8 = test.loc[test['ID'] == 8]  # 取出ID为8的test中的行
DataFrame(test8).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test8.xlsx', sheet_name='Sheet1', index=False, header=True)
test8 = test8.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train8 = test8.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)

# 第九题的模型训练
test9 = test.loc[test['ID'] == 9]  # 取出ID为9的test中的行
DataFrame(test9).to_excel('C:/Users/xycy1/Desktop/暑期校创/now_data/test9.xlsx', sheet_name='Sheet1', index=False, header=True)
test9 = test9.drop('USERNAME', axis=1)  # axis=1 是跨列，axis=0 是跨行 删除时是删除一列，求和时是求一行
train9 = test9.iloc[[1]]  # 以DataFrame的格式读取test的第2行
# print(train)
'''
import joblib
from sklearn.cluster import KMeans
from sklearn import neural_network
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
test11 = pd.read_excel('01.xlsx')
test22 = pd.read_excel('02.xlsx')
test33 = pd.read_excel('03.xlsx')
test44 = pd.read_excel('04.xlsx')
test55 = pd.read_excel('05.xlsx')
test66 = pd.read_excel('06.xlsx')
test77 = pd.read_excel('07.xlsx')
test88 = pd.read_excel('08.xlsx')
test99 = pd.read_excel('09.xlsx')



test1_target = test11['predict']
test2_target = test22['predict']
test3_target = test33['predict']
test4_target = test44['predict']
test5_target = test55['predict']
test6_target = test66['predict']
test7_target = test77['predict']
test8_target = test88['predict']
test9_target = test99['predict']


test1 = test11.drop(['USERNAME','predict','ID'], axis=1)
test2 = test22.drop(['USERNAME','predict','ID'], axis=1)
test3 = test33.drop(['USERNAME','predict','ID'], axis=1)
test4 = test44.drop(['USERNAME','predict','ID'],axis=1)
test5 = test55.drop(['USERNAME','predict','ID'],axis=1)
test6 = test66.drop(['USERNAME','predict','ID'],axis=1)
test7 = test77.drop(['USERNAME','predict','ID'],axis=1)
test8 = test88.drop(['USERNAME','predict','ID'],axis=1)
test9 = test99.drop(['USERNAME','predict','ID'],axis=1)
train1_x,test1_x,train1_y,test1_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train2_x,test2_x,train2_y,test2_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train3_x,test3_x,train3_y,test3_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train4_x,test4_x,train4_y,test4_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train5_x,test5_x,train5_y,test5_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train6_x,test6_x,train6_y,test6_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train7_x,test7_x,train7_y,test7_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train8_x,test8_x,train8_y,test8_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
train9_x,test9_x,train9_y,test9_y = train_test_split(test1, test1_target, test_size=.5, random_state=0)
nw1 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=10000 ,tol=1e-4)
nw1.fit(train1_x,train1_y)
print(accuracy_score(test1_y,nw1.predict(test1_x)))
nw2 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=5000 ,tol=1e-4)
nw2.fit(train2_x,train2_y)
print(accuracy_score(test1_y,nw2.predict(test1_x)))
nw3 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw3.fit(test3,test33['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train3)))
nw4 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw4.fit(test4,test44['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train44)))
nw5 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw5.fit(test5,test55['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train5)))
nw6 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw6.fit(test6,test66['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train6)))
nw7 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw7.fit(test7,test77['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train7)))
nw8 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw8.fit(test8,test88['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train8)))
nw9 = neural_network.MLPClassifier(hidden_layer_sizes=(10), activation="relu",
                 solver='adam', alpha=0.0001,
                 batch_size='auto', learning_rate="constant",
                 learning_rate_init=0.001, power_t=0.5, max_iter=900 ,tol=1e-4)
nw9.fit(test9,test99['predict'])
print(accuracy_score(train11['predict'],nw1.predict(train9)))
#kmeans_sk = KMeans(n_clusters=2, random_state=30).fit(test1)
#joblib.dump(kmeans_sk, 'kmeans.pkl')
#print(kmeans_sk.predict(train1))
