import numpy as np
from sklearn import tree

resultsfile = open("results.txt", "r")

countfile = open("reg_count.txt", "r")

playerfile = open("player_count.txt", "r")

bankfile = open("bank_count.txt", "r")

tiefile = open("tie_count.txt", "r")

labels = []

testlabels = []

labelnames = ["Player", "Banker", "Tie"]

descriptors = []

testdescriptors = []

descriptornames = ["Regular Count", "Player Count", "Bank Count", "Tie Count"]




for x in range(5100):
   result = int(resultsfile.readline())
   count = int(countfile.readline())
   player = int(playerfile.readline())
   bank = int(bankfile.readline())
   tie = int(tiefile.readline())
   oneset = [count,player,bank,tie]
   if x < 5000:
      descriptors.append(oneset)
      labels.append(result)
   else:
      testdescriptors.append(oneset)
      testlabels.append(result)

clf = tree.DecisionTreeClassifier()
clf.fit(descriptors, labels)

print (testlabels)
print ("\n")
print (clf.predict(testdescriptors))

import graphviz
dot_data = tree.export_graphviz(clf, out_file=None, feature_names=descriptornames, class_names=labelnames, filled=True, rounded=True, special_characters=True)
graph = graphviz.Source(dot_data)
graph.render("Baccarat")
