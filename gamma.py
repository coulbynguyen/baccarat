import numpy as np
from sklearn import tree

resultsfile = open("results.txt", "r")

countfile = open("reg_count.txt", "r")

playerfile = open("player_count.txt", "r")

bankfile = open("bank_count.txt", "r")

tiefile = open("tie_count.txt", "r")

streakcountfile = open("streakcount_file.txt", "r")

streaktypefile = open("streaktype_file.txt", "r")

lasthandfile = open("last_hand.txt", "r")

labels = []

testlabels = []

labelnames = ["Player", "Banker", "Tie"]

descriptors = []

testdescriptors = []

# descriptornames = ["Regular Count", "Player Count", "Bank Count", "Tie Count", "Last Hand Result", "Streak Type", "Streak Count"]
descriptornames = ["Player Count", "Streak Count", "Streak Type", "Last Hand Result"]





for x in range(11000):
   result = int(resultsfile.readline())
   # count = int(countfile.readline())
   player = int(playerfile.readline())
   # bank = int(bankfile.readline())
   # tie = int(tiefile.readline())
   streakcount = int(streakcountfile.readline())
   streaktype = int(streaktypefile.readline())
   lasthand = int(lasthandfile.readline())
   # oneset = [count,player,bank,tie,lasthand,streaktype,streakcount]
   oneset = [player, streakcount, streaktype, lasthand]
   if x < 10000:
      descriptors.append(oneset)
      labels.append(result)
   else:
      testdescriptors.append(oneset)
      testlabels.append(result)

clf = tree.DecisionTreeClassifier()
clf.fit(descriptors, labels)

predictions = clf.predict(testdescriptors)

print (testlabels)
print ("\n")
print (clf.predict(testdescriptors))

from sklearn.metrics import accuracy_score
print (accuracy_score(testlabels, predictions))



# below is the code that creates the graph but right now i need to work on finding out what data is relevant
# import graphviz
# dot_data = tree.export_graphviz(clf, out_file=None, feature_names=descriptornames, class_names=labelnames, filled=True, rounded=True, special_characters=True, impurity=False)
# graph = graphviz.Source(dot_data)
# graph.render("Baccarat")
