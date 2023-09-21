import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime
from pandas import Series,DataFrame
"""
数据读取部分
注意如果想根据列生成子表，则用df['Chemistry']"""

df = pd.read_excel('test.xlsx')
print(df.shape)
"""
显示数据格式
"""
print(df.dtypes)
"""显示数据类型"""
print(df.columns)
"""显示数据列的index"""
print(df.tail(5))
"""显示数据的后5行，如果用head则是前5行"""
"""
df = pd.read_excel('test.xlsx',skiprows = [2])//跳过第i行不读取
"""
print(df.isnull())
"""显示数据缺失值，true则是缺失，false则是未缺失"""
"""删除空值df.dropna(how='any')"""
df.fillna(99,inplace = True)
df['wages'].astype('float64')
"更改数据格式"
"""自动填充空值为100,这里inplace = True 才是允许直接修改原数据，否则没用，这里还可以用
df['经纪人响应时长'].fillna(df['经纪人响应时长'].mean())来特别对某一列的缺失值进行填充"""
"""保存修改"""

print(df['wages'].corr(df['ages']))
"相关性分析，相同的还有cov协方差，std某一列的标准差"

print(pd.pivot_table(df,index=["KPI"],values=["ages"],
          columns=["wages"],fill_value=0,margins=True))
"这个类似于绘图横纵坐标为index和columns，表格里面的值是ages"
print(df.groupby('ages')['wages'].count())
"这个不用管有点狗和难以理解"
print(df.sort_values(by=['wages']).head(10))
"数据排序"
"""new_row = {'person_name':'Max', 'wages':10000, 'ages':33, 'KPI':np.nan,'height':190}
df = df.append(new_row, ignore_index=True)"""
"插入新行"
"""sex = ['Male','Female','Male','Female','Male','Female','Female','Male']
df['Sex'] = sex
"""
"插入新列"
DataFrame(df).to_excel('test.xlsx', sheet_name='Sheet2', index=False, header=True)




print(df.groupby(['Sex'])) # Returns a groupby object for values from one column
print(df.groupby('Sex').agg(np.mean))#计算性别分组的所有列的平均值
print(df.describe())
"一些常用数据分析配套集合"
"""
df.loc[0:3]返回前三行的数据
df.iloc[:4, :5] 返回前四行，前5列
average = df.groupby(‘Sex’).agg(np.mean)计算性别分组的所有列的平均值
df[df['KPI'] > 80] 返回行
df.iloc[0] # 选取第一行的数据
df.iloc[:,1] # 第二列的所有数据
df.iloc[0,1] # 第二列的第一个元素
df.dropna()Drop all rows that contain null values
 df.dropna(axis=1) 删除具有缺失值的列
df['大区'].astype('float64') 更改数据格式
df.rename(columns={'IM渠道': '渠道'}) 更改列名称
df['门店'].drop_duplicates()删除重复值（第一次出现的保留，后面的删除
df['客户UCID'].replace('10531975','110')对列表的值进行更换
离散的数据处理
包含离散的feature的数据无法直接作为输入进行机器学习。例如性别，男跟女，例如工资，low，medium，high。 需要做一个向量化处理。有人说不能直接用0,1,2来表示吗，例如0表示low，1表示medium， 2表示high。emmmm，当然不行。怎么向量化呢？以该数据中的工作岗位与工资为例， 001 表示low ，010表示medium，100表示表示high。

categorical_features = ['sales', 'salary']

hr_cat = pd.get_dummies(hr[categorical_features])

hr = hr.drop(categorical_features, axis=1)

hr = pd.concat([hr, hr_cat], axis=1)
!!!!!!!!!!!!!!!!!!!!!!!!!!!get_dummies函数可以将一个列（如果不加列的话可以是整个数据里面的每一列的所有可能取值都变为新df的列）里面的所有可能取值作为列来向量化，并且将指定列进行get_dummies 后合并到元数据中
df = df.join(pd.get_dummies(df.color))将新得到的表与元表进行合并
很简单的代码，值得一提的事get_dummies这个函数。该函数的作用是将离散的变量转化为向量化，一两句说不清，这里只告诉你可以这么处理离散变量，想要细细了解看一下文档就明白了，我把文档贴过来也没有意思。
"""