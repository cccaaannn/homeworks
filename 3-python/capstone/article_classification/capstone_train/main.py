#-----------------------------------IMPORTS---------------------------------------------------------------------------
import re

from sklearn.feature_extraction.text import CountVectorizer

from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split

import pickle

#-------------------------READ DATASET--------------------------------------------------------------------------------

train = []
Train_folder_names = ["Sport","Political","Technology","Entertainment","Financial","Travel","World"]
Train_labels = []
#"HoleBusinessNews","HoleEntertainmentNews","HolePoliticsNews","HoleSportNews","HoleTechNews"
#"Sport","Political","Technology","Entertainment","Financial","Travel","World"
#"toxic","threat","insult","identity_hate","obscene","neutral","severe_toxic"
test = []
Test_labels = []

Filereedprogress = ""

for i in range(len(Train_folder_names)):
    Train_labels.append(train.__len__())
    for line in open('Dataset/' + Train_folder_names[i] + '.txt', encoding='ISO-8859-1'):
        train.append(line.strip())
    Train_labels.append(train.__len__())

    Filereedprogress += (Train_folder_names[i] + ",")


Test_labels.append(test.__len__())
for line in open('Dataset/test.txt', encoding = 'ISO-8859-1'):
    test.append(line.strip())
Test_labels.append(test.__len__())

Filereedprogress += "test.txt"

#----------------------------------------print data read info---------------------------------------------------------
print("")
print("SELECTED FILES ARE")
print(Filereedprogress)
print("")
print("TRAIN LABELS ARE: ")
print(Train_labels)
print("TEST LABEL IS: ")
print(Test_labels)
print("")
#---------------------------------------------------------------------------------------------------------------------
#----------------------------------------CLEANING---------------------------------------------------------------------

REPLACE_NO_SPACE = re.compile("(\.)|(\;)|(\:)|(\!)|(\')|(\?)|(\,)|(\")|(\()|(\))|(\[)|(\])")
REPLACE_WITH_SPACE = re.compile("(<br\s*/><br\s*/>)|(\-)|(\/)")

def preprocess(value):
    value = [REPLACE_NO_SPACE.sub("", line.lower()) for line in value]
    value = [REPLACE_WITH_SPACE.sub(" ", line) for line in value]
    return value

train_clean = preprocess(train)
test_clean = preprocess(test)


#-------------------------------------VECTORIZAION--------------------------------------------------------------------

cv = CountVectorizer(binary = True)
#cv = CountVectorizer()
cv.fit(train_clean)
X_train = cv.transform(train_clean)
X_test = cv.transform(test_clean)                                     #---------------------------------------
pickle.dump( cv, open('trained sets/' + 'cv.kahve', 'wb' ) )          #save train vestorizer object to a file-
                                                                      #---------------------------------------
#--------------------------------------LABELING-----------------------------------------------------------------------

All_train_labels = []
for i in range(len(Train_folder_names)):              #total folder count
     All_train_labels.append([])


Total_train_length = int(Train_labels[len(Train_labels)-1])

for i in range(len(Train_folder_names)):
    for j in range(Total_train_length):
        if (j >= Train_labels[(2 * i)] and j < Train_labels[(2 * i) + 1]):       #ilk kısımın hep çift olması ikinci kısımın da he tek oolması lazım doğru labellemesi için  ayrıca ikinci kısım küçük eşit değil 0 dan başladığı için aslında sondan bir öncekinde bitiyo
            All_train_labels[i].append(1)
        else:
            All_train_labels[i].append(0)

#----------------------------------------print labeling info---------------------------------------------------------
print("")
print("LABELS CREATED")
print(str(All_train_labels.__len__()) + " different lists created and labeled")
for i in range(len(All_train_labels)):
    print(All_train_labels[i])
print("")
#--------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------PREDİCTİON----------------------------------------------------

All_answers = []
for i in range(len(Train_folder_names)):              #create answers list
     All_answers.append([])

final_model = []
for i in range(len(Train_folder_names)):              #create final models list
     final_model.append([])


for i in range(len(Train_folder_names)):              #create a model for all catagories
    final_model[i] = LogisticRegression()
    final_model[i].fit(X_train,All_train_labels[i])                                                            #----------------------------
    pickle.dump(final_model[i], open('trained sets/' + Train_folder_names[i].__str__() + '.trained', 'wb'))    #save trained data to a file-
                                                                                                               #----------------------------

Total_test_length = int(Test_labels[len(Test_labels) - 1])    #find length of the text folder


#calsulate predictions and append them to answers
for i in range(len(Train_folder_names)):
    for j in range(Total_test_length):
        All_answers[i].append(float("{:.5f}".format(float(final_model[i].predict_proba(X_test[j])[:,1]))))
       # All_answers[i].append(float(final_model.predict(X_test[j])))

#----------------------------------------print learning info----------------------------------------------------------
print("")
print("PREDICTED PERCENTAGES ARE")
for i in range(len(All_answers)):
    print(All_answers[i])
print("")
#---------------------------------------------------------------------------------------------------------------------
#---------------------------------------FİNAL RESULTS-----------------------------------------------------------------

Final_results = []
for i in range(Total_test_length):
    biggest = 0.0
    count = -1
    for j in range(len(Train_folder_names)):
        if(float(All_answers[j][i]) > biggest):
            biggest = float(All_answers[j][i])
            count = j
    if(biggest < 0.0):                                    #bilmiyosa bilmiyorum desin
        Final_results.append("idk")
    else:
        Final_results.append(Train_folder_names[count])

#----------------------------------------print result-----------------------------------------------------------------
print("")
print("FINAL ANSWER IS")
print(Final_results)
print("")
#---------------------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------------------


print("\n\n")

feature_to_coef = {word: coef for word, coef in zip(cv.get_feature_names(), final_model[0].coef_[0])}

for best_positive in sorted(feature_to_coef.items(),key=lambda x: x[1],reverse=True)[:100]:
    print(best_positive)


print("\n\n")

for best_negative in sorted(feature_to_coef.items(),key=lambda x: x[1])[:100]:
    print(best_negative)