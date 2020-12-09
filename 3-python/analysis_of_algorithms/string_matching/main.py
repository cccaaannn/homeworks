import time
from nltk import PorterStemmer
start_time = time.time()
stopwords = ["a","the","an","and","but","by","than","in","all","of","ll","he","i","was","is","from","at","as",
"she","his","her","to","up","on","does","have","their","be","that","you","too","we","it","him","will",
"can","out","all","got","some","this","our","do","has","for","they","them","much","off","just","then","very",
"yes","yet","your","with","she","willing","wish","wished","wishing","within","without","such","as" ,"what","what time","who","m.",
"how","many","where","himself", "s","re", "i'm","doesn't", "i'd","haven't","everybody's","isn't","we're","it's","int.",
"what's","ext.","don't","wanna","you're","t","i'll","how many","shouldn't","not","if" ,"color"]
punctuation = [',',';','-','(',')','!','"','?',':'];
#question ve ayıklaması--------------------------------------------------------------
questions = []
lines = [line.rstrip('\n') for line in open('questions.txt')]

for i in  lines:
    questions.append(i.split())

for i in range(questions.__len__()):
    for j in range(punctuation.__len__()):
        questions[i] = [x.lower() for x in questions[i]]
        questions[i] = [s.strip(punctuation[j]) for s in questions[i]]

for i in  questions:
    for j in range(stopwords.__len__()):
        while stopwords[j] in i: i.remove(stopwords[j])

#texti okuma
all = ""
with open ("the_truman_show_script.txt", "r") as myfile:
    all = myfile.readlines()
for i in questions:
    print(i)
#--------------------------------------------------------------------------------------
#cevabi iceren cumlerelri cekme
for x in range(questions.__len__()):
    p = questions[x][0]
    sentences = []
    sentences.append([])
    temp = ""
    counter = 0
    flag = 0
    for i in range(all[0].__len__()):
        if ((all[0][i] != ' ') and (all[0][i] != '.')):
            temp += all[0][i]
        else:
            if (temp == p):
                flag = 1
            sentences[counter].append(temp)
            temp = ""
        if (all[0][i] == '.'):
            if (flag == 1):
                sentences.append([])
                counter = counter + 1
                flag = 0
            else:
                sentences[counter].clear()
                temp = ""
    sentences = sentences[:-1]
#cevabi iceren cumleleri ayiklama
    for i in range(sentences.__len__()):
        sentences[i] = list(filter(None, sentences[i]))

    for i in range(sentences.__len__()):
        for j in range(punctuation.__len__()):
            sentences[i] = [x.lower() for x in sentences[i]]
            sentences[i] = [s.strip(punctuation[j]) for s in sentences[i]]

    for i in sentences:
        for j in range(stopwords.__len__()):
            while stopwords[j] in i: i.remove(stopwords[j])

    from collections import OrderedDict
    for i in range(sentences.__len__()):
        list(OrderedDict.fromkeys(sentences[i]))
#cevabi bulma
    counter = 0
    for i in range(sentences.__len__()):
        for j in range(sentences[i].__len__()):
            for k in range(questions[x].__len__()):
                if (PorterStemmer().stem(sentences[i][j]) == PorterStemmer().stem(questions[x][k])):
                    sentences[i][j] = "0"
                    counter = counter + 1
                    break
        if (counter < questions[x].__len__()):
            sentences[i].clear()
        counter = 0
    sentences = [x for x in sentences if x != []]
#cevabi ekrana yazdirma
    print()
    if not sentences:
        print("QUESTION" , x+1  , "NO ANSWER")
    else:
        print("QUESTION" , x+1  , "ANSWER")

    for i in sentences:
        print(i)
    print()
#--------------------------------------------------------------------------------------
#gecen sure
print("Total time: " , (time.time() - start_time) ," seconds")