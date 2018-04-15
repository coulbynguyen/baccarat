import numpy as np
from sklearn import tree

resultsfile = open("labels.txt", "r");

countfile = open("newcount.txt", "r");

handcount = open("handnumber.txt", "r");

lastwin = open("lasthandwin.txt", "r");

streakcountfile = open("streakcount.txt", "r")

banklast10 = open("sum10.txt", "r")

banklast20 = open("sum20.txt", "r")

banklast30 = open("sum30.txt", "r")

labels = []

testlabels = []

labelnames = ["Banker", "Player", "Tie"]

descriptors = []

testdescriptors = []

# descriptornames = ["COUNT", "HAND NUMBER", "LAST HAND RESULT", "STREAK COUNT"]
# descriptornames = ["COUNT"]
descriptornames = ["STREAK COUNT", "BANKER IN THE LAST 10", "BANKER IN THE LAST 20", "BANKER IN THE LAST 30"]





for x in range(5000):
   result = int(resultsfile.readline())
   count = int(countfile.readline())
   handnumber = int(handcount.readline())
   lasthand = int(lastwin.readline());
   streakcount = int(streakcountfile.readline())
   bank10 = int(banklast10.readline())
   bank20 = int(banklast20.readline())
   bank30 = int(banklast30.readline())
   # oneset = [count, handnumber, lasthand, streakcount]
   # oneset = [count];
   oneset = [streakcount, bank10, bank20, bank30]
   if x < 4900:
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
import graphviz
dot_data = tree.export_graphviz(clf, out_file=None, feature_names=descriptornames, class_names=labelnames, filled=True, rounded=True, special_characters=True, impurity=False)
graph = graphviz.Source(dot_data)
graph.render("Baccarat")
