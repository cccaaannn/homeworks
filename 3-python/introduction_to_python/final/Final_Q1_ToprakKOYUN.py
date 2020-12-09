# -*- coding: utf-8 -*-
"""
Created on Mon May 18 22:36:00 2020

"""
import numpy as np
import matplotlib.pyplot as plt

#load doctor names from "doctor.txt" into doctors numpy array
doctors = np.loadtxt("doctor.txt", dtype=np.str, skiprows=1)


#load years and number of patients in that year from "patients.txt" into #patients numpy array
patients = np.loadtxt("patients.txt", dtype=np.int, skiprows=1)

#extract the patients data for year 2019 into pat2019

pat2019 = patients[np.where(patients==2019)[0]][:,1]

#extract the doctors data for year 2019 into doc2019

doc2019 = doctors[np.where(patients==2019)[0]]

#find and display the total number of patients in 2019

print(sum(pat2019))

#find and display the name of the doctor with the highest number of patients in 2019

print(doctors[np.where(patients==max(pat2019))[0]])

#create the histogram of the number of patients in 2019 with 4 bins
fig1, axs = plt.subplots(1,2)
axs[0].hist(pat2019,  bins=4)
axs[0].title.set_text("distribution of 2019 patients")

#create the chart of doctor names versus the number of patients in 2019
axs[1].plot(doc2019,pat2019,"-o")

plt.show()