from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Flatten
from tensorflow.keras.layers import Conv2D
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.layers import MaxPooling2D
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from keras.preprocessing import image
import matplotlib.pyplot as plt
from keras.models import load_model
import numpy as np

from PIL import Image as ImagePIL ,ImageFont,ImageDraw
from PIL import Image

#This is a training process of typical CNN using keras model
'''
train_dir = 'C:/Users/45373/Desktop/private file/校创/fer2013/train'
val_dir = 'C:/Users/45373/Desktop/private file/校创/fer2013/test'


num_train = 28709
num_val = 7178
batch_size = 64
num_epoch = 50

train_datagen = ImageDataGenerator(rescale=1./255)
val_datagen = ImageDataGenerator(rescale=1./255)

train_generator = train_datagen.flow_from_directory(
        train_dir,
        target_size=(48,48),
        batch_size=batch_size,
        color_mode="grayscale",
        class_mode='categorical')

validation_generator = val_datagen.flow_from_directory(
        val_dir,
        target_size=(48,48),
        batch_size=batch_size,
        color_mode="grayscale",
        class_mode='categorical')


model = Sequential()

model.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(48,48,1)))
model.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.25))

model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.25))

model.add(Flatten())
model.add(Dense(1024, activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(7, activation='softmax'))

model.compile(loss='categorical_crossentropy',optimizer=Adam(learning_rate=0.0001, decay=1e-6),metrics=['accuracy'])
model_info = model.fit(
    train_generator,
    steps_per_epoch=num_train // batch_size,
    epochs=num_epoch,
    validation_data=validation_generator,
    validation_steps=num_val // batch_size)
model.save_weights('model.h5')
'''
#model.h5 is the trained CNN model

import cv2
import os
import glob
    # 最后剪裁的图片大小
size_m = 48
size_n = 48
#This is set the size of the frame and cast
def detect(img):
        cascade = cv2.CascadeClassifier(
            "C:\\Users\\45373\\Desktop\\private file\\Mathematical modelling\\Matlab2020b\\toolbox\\vision\\visionutilities\\classifierdata\\cascade\\haar\\haarcascade_frontalface_alt2.xml")
        rects = cascade.detectMultiScale(img, scaleFactor=1.3, minNeighbors=4, minSize=(30, 30),
                                         flags=cv2.CASCADE_SCALE_IMAGE)
        if len(rects) == 0:
            return []
        rects[:, 2:] += rects[:, :2]
        return rects
#cast in detail and rewrite
def cast_face(img):
    img_path = img
    imglist = glob.glob(img)
    for list in imglist:

        # print(list)
        # cv2读取图像
        img = cv2.imread(list)
        dst = img
        rects = detect(dst)
        for x1, y1, x2, y2 in rects:
            # 调整人脸截取的大小。横向为x,纵向为y
            roi = dst[y1 + 10:y2 + 20, x1 + 10:x2]
            img_roi = roi
            re_roi = cv2.resize(img_roi, (size_m, size_n))

            # 新的图像存到data/image/jaffe_1
            f = img_path

            if not os.path.exists(f):
                os.mkdir(f)
            # 切割图像路径
            path = list.split(".")

            # 新的图像存到data/image/jaffe_1   并以jpg 为后缀名
            cv2.imwrite(img_path, re_roi)
#this is the predict func
def predict_emo(path):
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(48, 48, 1)))
    model.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Flatten())
    model.add(Dense(1024, activation='relu'))
    model.add(Dropout(0.5))
    model.add(Dense(7, activation='softmax'))

    model.compile(loss='categorical_crossentropy', optimizer=Adam(learning_rate=0.0001, decay=1e-6),
                  metrics=['accuracy'])

    model.weight = model.load_weights('C:\\Users\\45373\\Desktop\\private file\\校创\\model.h5')
    img = image.load_img(path,
                   target_size=(48, 48), color_mode="grayscale")
    #img.save(path,quality = 100)

    img.show()
    img = np.array(img)

    img = np.expand_dims(img, axis=0)  # makes image shape (1,48,48)
    img = img.reshape(1, 48, 48, 1)

    result = model.predict(img)
    result = list(result[0])
    final_score_one = 50+25*(0.6*result[0]+ -0.3*result[1]+result[2]*0.5+result[3]*(-0.4)+result[4]*1+0.4*result[5]+result[6]*1.65)

    label_dict = {0: 'Angry', 1: 'Disgust', 2: 'Fear', 3: 'Happy', 4: 'Neutral', 5: 'Sad', 6: 'Surprise'}
    img_index = result.index(max(result))
    print(label_dict[img_index])
    print(final_score_one)
    return final_score_one
#test part,to see the efficiency and accuracy
#the more score the more focused根据文献Angry，sad 赋值权重为-1，disgust为-2，fear和neutral为0，happy为1，surprise为2
#cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\6.jpg")
final_score = 0
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\1.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\1.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\2.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\2.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\3.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\3.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\4.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\4.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\5.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\5.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\6.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\6.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\7.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\7.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\8.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\8.jpg")
cast_face("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\9.jpg")
final_score+=predict_emo("C:\\Users\\45373\\Documents\\Tencent Files\\453731389\\FileRecv\\MobileFile\\already_processed\\9.jpg")
print(final_score/9)
#final_score =final_score /16.0



