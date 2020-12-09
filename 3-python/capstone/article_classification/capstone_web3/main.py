#-----------------------------------IMPORTS---------------------------------------------------------------------------
import re
import os
import time
import webbrowser
import getpass

import pkg_resources
from sklearn.feature_extraction.text import CountVectorizer

from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split

import pickle


# ----------------------------İNDEX PAGE START---------------------------------------------------------------------------
a = os.getcwd().replace("\\", "/")
webbrowser.open_new_tab(a + '/WebPages/index.html')


while(1):

    # ----------------------------CHECK TEST FİLE EXİST?---------------------------------------------------------------------
    while (1):
        try:
            time.sleep(0.25)
            time.sleep(1)
            if (open('C:/Users/user/Desktop/test.txt', 'r') != ""):
                print("readed")
                break
        except FileNotFoundError:
            print("waiting")
            continue


    # -------------------------LOAD TRAINED DATA-----------------------------------------------------------------------------

    Train_folder_names = ["Sport","Political","Technology","Entertainment","Financial","Travel","World"]
    # "HoleBusinessNews","HoleEntertainmentNews","HolePoliticsNews","HoleSportNews","HoleTechNews"
    # "Sport","Political","Technology","Entertainment","Financial","Travel","World"
    # "toxic","threat","insult","identity_hate","obscene","neutral","severe_toxic"
    test = []
    Test_labels = []

    final_model = []
    for i in range(len(Train_folder_names)):  # create final models list
        final_model.append([])

    # load trained data and append to list
    for i in range(len(Train_folder_names)):
        final_model[i] = LogisticRegression()
        final_model[i] = pickle.load(open('trained sets/' + Train_folder_names[i].__str__() + '.trained', 'rb'))

    # load test data
    temp = ""
    Test_labels.append(test.__len__())
    for line in open('C:/Users/user/Desktop/test.txt', encoding='ISO-8859-1'):
        temp = temp + line.strip().replace("\n", " ")

    test.append(temp)
    print(test)
    Test_labels.append(test.__len__())

    # ----------------------------------------CLEANING---------------------------------------------------------------------

    REPLACE_NO_SPACE = re.compile("(\.)|(\;)|(\:)|(\!)|(\')|(\?)|(\,)|(\")|(\()|(\))|(\[)|(\])")
    REPLACE_WITH_SPACE = re.compile("(<br\s*/><br\s*/>)|(\-)|(\/)")


    def preprocess(value):
        value = [REPLACE_NO_SPACE.sub("", line.lower()) for line in value]
        value = [REPLACE_WITH_SPACE.sub(" ", line) for line in value]
        return value


    test_clean = preprocess(test)

    # -------------------------------------VECTORIZAION--------------------------------------------------------------------

    cv = CountVectorizer(binary=True)
    cv = pickle.load(open('trained sets/' + 'cv.kahve', 'rb'))
    X_test = cv.transform(test)

    # ------------------------------------------------------PREDİCTİON----------------------------------------------------

    All_answers = []
    for i in range(len(Train_folder_names)):  # create answers list
        All_answers.append([])

    Total_test_length = int(Test_labels[len(Test_labels) - 1])  # find length of the text folder

    # calsulate predictions and append them to answers
    for i in range(len(Train_folder_names)):
        for j in range(Total_test_length):
            All_answers[i].append(float("{:.5f}".format(float(final_model[i].predict_proba(X_test[j])[:, 1]))))
        # All_answers[i].append(float(final_model.predict(X_test[j])))

    # ----------------------------------------print learning info----------------------------------------------------------
    print("")
    print("PREDICTED PERCENTAGES ARE")
    for i in range(len(All_answers)):
        print(All_answers[i])
    print("")
    # ---------------------------------------------------------------------------------------------------------------------
    # ---------------------------------------FİNAL RESULTS-----------------------------------------------------------------

    Final_results = []
    for i in range(Total_test_length):
        biggest = 0.0
        count = -1
        for j in range(len(Train_folder_names)):
            if (float(All_answers[j][i]) > biggest):
                biggest = float(All_answers[j][i])
                count = j
        if (biggest < 0.0):  # bilmiyosa bilmiyorum desin
            Final_results.append("idk")
        else:
            Final_results.append(Train_folder_names[count])

    # ----------------------------------------print result-----------------------------------------------------------------
    print("")
    print("FINAL ANSWER IS")
    print(Final_results)
    print("")
    # ---------------------------------------------------------------------------------------------------------------------




    # ----------------------------------------DELETE FILE--------------------------------------------------------------------
    if (open('C:/Users/user/Desktop/test.txt', 'r') != ""):
        os.remove('C:/Users/user/Desktop/test.txt')

    # ------------------------------------LOAD ININDEXSTOP TO ININDEX--------------------------------------------------------
    r = open('WebPages/inindexStop.html', encoding='ISO-8859-1')
    message = r.readlines()
    r.close()

    metin = ""
    for i in message:
        metin += i

    t = open('WebPages/inindex.html', 'w')
    whole = metin % (str((All_answers[0][0]) * 100) + "%", str(round((All_answers[0][0]) * 100)) + "%",
                     str((All_answers[1][0]) * 100) + "%", str(round((All_answers[1][0]) * 100)) + "%",
                     str((All_answers[2][0]) * 100) + "%", str(round((All_answers[2][0]) * 100)) + "%",
                     str((All_answers[3][0]) * 100) + "%", str(round((All_answers[3][0]) * 100)) + "%",
                     str((All_answers[4][0]) * 100) + "%", str(round((All_answers[4][0]) * 100)) + "%",
                     str((All_answers[5][0]) * 100) + "%", str(round((All_answers[5][0]) * 100)) + "%",
                     str((All_answers[6][0]) * 100) + "%", str(round((All_answers[6][0]) * 100)) + "%")
    t.write(whole)
    t.close()




