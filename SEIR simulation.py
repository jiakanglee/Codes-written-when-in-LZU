T = 50 #40天
N = 9300000   #总人数
E = [0]*T   #潜伏者人数
I = [1]*T   #感染者
S = [N-I[0]]*T    #易感人数
R =[0]*T     #康复人数

r = 12      #感染者接触易感者的人数
B = 0.053   #传染概率
r2 = 12     #潜伏者接触易感者的人数
B2 = 0.1   #潜伏者传染正常人的概率
a = 0.3    #潜伏者转化为感染者概率
y = 0.6     #康复概率

for i in range(T-1):
    if i+1>=10 :       #从第9天开始，有关部门采取措施，平均接触人数和平均感染率显著下降一直到3月5号左右接触封禁，即到46天解除封禁，
        r=3
        r2=3
        B = 0.001
        B2 = 0.001
    if i+1>=46:
        r= 0
        B= 0
        r2 = 0.000001
        B2 = 0.000001
        a= a* 0.3/2.0
        y = 0.6
    S[i+1] = S[i] - r*B*S[i]*I[i]/N - r2*B2*S[i]*E[i]/N
    E[i+1] = E[i] + r*B*S[i]*I[i]/N - a*E[i] + r2*B2*S[i]*E[i]/N
    I[i+1] = I[i] + a*E[i]#-y*E[i]
    print(I[i])
    R[i+1] = R[i] + y*I[i]


import matplotlib.pyplot as plt
#plt.xlabel('Date')
#plt.ylabel('Number of latent patients')
#plt.plot(S)
#plt.plot(E)
plt.plot(I,label = 'SIER模拟确诊总人数')
#plt.text(,0,' \leftarrow 正弦');
#plt.text(20,400,'number of E');
#plt.plot(R)
plt.show()