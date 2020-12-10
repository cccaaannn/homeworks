import warnings
warnings.filterwarnings("ignore")

# keras and tf
import tensorflow as tf
import keras

# models
from keras.models import Sequential
from keras.models import Model

# backend
from keras import optimizers, metrics, models
import keras.backend as K

# layers
from keras.layers import Input, Flatten, Dense, Dropout, Activation
from keras.layers import Convolution2D, MaxPooling2D, ZeroPadding2D, GlobalAveragePooling2D, AveragePooling2D, BatchNormalization, Conv2D

# optimizers
from keras.optimizers import SGD

# training
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ModelCheckpoint, CSVLogger, LearningRateScheduler

# save
import h5py

# keras aplications
from keras.applications import DenseNet201, DenseNet169, InceptionResNetV2, ResNet152V2, InceptionV3, DenseNet121, Xception, MobileNet, VGG19


# other libs
import numpy as np
import math
import pickle
import os


# imagepreprocessing
from  imagepreprocessing.keras_functions import create_training_data_keras, make_prediction_from_array_keras
from  imagepreprocessing.utilities import create_confusion_matrix, train_test_split

dataset_path = "/PetImages"
"""
x, y, test_x, test_y  = create_training_data_keras(dataset_path, save_path="cat_dog", image_size=224, percent_to_use=0.5, validation_split=0.2, grayscale=False)

"""

x = pickle.load(open("cat_dog_x_train.pkl" ,"rb"))
y = pickle.load(open("cat_dog_y_train.pkl" ,"rb"))
test_x = pickle.load(open("cat_dog_x_validation.pkl" ,"rb"))
test_y = pickle.load(open("cat_dog_y_validation.pkl" ,"rb"))

"""
#base_model=DenseNet201(include_top=False)
#base_model=InceptionV3(include_top=False)
base_model=VGG19(include_top=False)

out=base_model.output
out=GlobalAveragePooling2D()(out)
preds=Dense(2,activation='softmax')(out)
model=Model(inputs=base_model.input,outputs=preds)







opt = SGD(lr=0.0001, momentum=0.9)
model.compile(loss = "categorical_crossentropy", optimizer = opt, metrics=['accuracy'])


model.fit(x,y, validation_split=0.2, epochs=10, verbose=1)



model.save("vgg19.model")
"""


class_names = ["cat", "dog"]

# make prediction
predictions = make_prediction_from_array_keras(test_x, "vgg19.model", print_output=False)

# create confusion matrix
cnf_matrix = create_confusion_matrix(predictions, test_y, class_names=class_names, one_hot=True)


accuracy = (cnf_matrix[0][0]+cnf_matrix[1][1]) / sum(sum(cnf_matrix))

prescision_dog = cnf_matrix[1][1]/(cnf_matrix[1][1]+cnf_matrix[0][1])
recall_dog = cnf_matrix[1][1]/(cnf_matrix[1][1]+cnf_matrix[1][0])

prescision_cat = cnf_matrix[0][0]/(cnf_matrix[0][0]+cnf_matrix[1][0])
recall_cat = cnf_matrix[0][0]/(cnf_matrix[0][0]+cnf_matrix[0][1])


print("accuracy {}".format(accuracy))

print("prescision_dog {} recall_dog {}".format(prescision_dog,recall_dog))

print("prescision_cat {} recall_cat {}".format(prescision_cat,recall_cat))
