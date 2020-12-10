# -*- coding: utf-8 -*-
"""
Created on Wed Apr  8 16:04:52 2020

@author: Okan
"""
# -*- coding: utf-8 -*-
"""
@author: Okan
"""

import numpy as np
import pandas as pd
from tensorflow.keras.models import Sequential, load_model
from tensorflow.keras.layers import Dense, Dropout, LSTM, Activation
from tensorflow.keras.callbacks import EarlyStopping
from sklearn.preprocessing import StandardScaler, MinMaxScaler
import matplotlib.pyplot as plt
import math
from sklearn.metrics import mean_squared_error

df = pd.read_csv('time_series_data.csv', sep = ',')

plt.plot(df)

np.random.seed(13)

mydataset = df.values

myscaler = StandardScaler()
mydataset = myscaler.fit_transform(mydataset)

# split into train and test sets
train_size = int(len(mydataset) * 0.5)
test_size = len(mydataset) - train_size
train, test = mydataset[0:train_size,:], mydataset[train_size:len(mydataset),:]
print(len(train), len(test))

batch_size = 8 #
timestep = 16  
n_epochs = 50

def create_sequence(dataset, window):
    dataX, dataY = [], []
    for i in range(len(dataset)-(window+1)):
        a = dataset[i:(i+window), 0]
        dataX.append(a)
        dataY.append(dataset[i + window, 0])
    
    return np.array(dataX), np.array(dataY)

# reshape into X=t and Y=t+1
trainX, trainY = create_sequence(train, timestep)
testX, testY = create_sequence(test, timestep)

# convert [samples, features] to [samples, timesteps, features]
trainX = np.reshape(trainX, (trainX.shape[0], timestep, 1))
testX = np.reshape(testX, (testX.shape[0], timestep, 1))

#input shape: timesteps, input_dim

#If stateful=True, the last state for each sample at index i in a batch will be used 
#as initial state for the sample of index i in the following batch. 

print('LSTM model...')
model = Sequential()
model.add(LSTM(20, input_shape=(timestep, 1),
               return_sequences=True, stateful=False))
model.add(Dropout(0.2))

model.add(LSTM(units=40, input_shape=(timestep, 1),
               return_sequences=True, stateful=False))
model.add(Dropout(0.2))

model.add(LSTM(units=20, input_shape=(timestep, 1),
               return_sequences=False, stateful=False))
model.add(Dropout(0.2))

model.add(Dense(1)) 
model.compile(loss='mean_squared_error', optimizer='adam')

#without early stopping
#model.fit(trainX, trainY, batch_size=batch_size, epochs=n_epochs, verbose=2)

#with early stopping
#the loss function should be minimized (decreased)
#training will stop when the performance metric does not improve anymore
es = EarlyStopping(monitor='loss', mode='min', verbose=1) 
model.fit(trainX, trainY, batch_size=batch_size, epochs=n_epochs, 
          verbose=2, callbacks=[es])

trainPredict = model.predict(trainX, batch_size=batch_size)
testPredict = model.predict(testX, batch_size=1)

# invert predictions
trainPredict = myscaler.inverse_transform(trainPredict)
trainY = myscaler.inverse_transform([trainY])
testPredict = myscaler.inverse_transform(testPredict)
testY = myscaler.inverse_transform([testY])

# calculate root mean squared error
trainScore = math.sqrt(mean_squared_error(trainY[0], trainPredict[:,0]))
print('Train Score: %.2f RMSE' % (trainScore))
testScore = math.sqrt(mean_squared_error(testY[0], testPredict[:,0]))
print('Test Score: %.2f RMSE' % (testScore))


# shift train predictions for plotting
trainPredictPlot = np.empty_like(mydataset)
trainPredictPlot[:, :] = np.nan
trainPredictPlot[timestep:len(trainPredict)+timestep, :] = trainPredict
# shift test predictions for plotting
testPredictPlot = np.empty_like(mydataset)
testPredictPlot[:, :] = np.nan
testPredictPlot[len(trainPredict)+(timestep*2)+1:len(mydataset)-1, :] = testPredict
# plot baseline and predictions
plt.plot(myscaler.inverse_transform(mydataset))
plt.plot(trainPredictPlot, color = "red")
plt.plot(testPredictPlot, color = "blue")
plt.show()
