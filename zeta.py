import numpy as np
from sklearn import tree

resultsfile = open("labels.txt", "r");

countfile = open("newcount.txt", "r");

labels = []

testlabels = []

labelnames = ["Banker", "Player", "Tie"]

descriptors = []

testdescriptors = []

descriptornames = ["COUNT"]





for x in range(6000):
   result = int(resultsfile.readline())
   count = int(countfile.readline())
   oneset = [count]
   if x < 5000:
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
