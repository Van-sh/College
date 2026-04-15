from sklearn import tree

X = [[0, 0], [1, 1]]
Y = [0, 1]

model = tree.DecisionTreeClassifier()
model.fit(X, Y)

prediction = model.predict([[2, 2]])
print("Prediction:", prediction)
