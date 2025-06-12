import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from matplotlib import pyplot as plt

# Read dataset
url = 'https://raw.githubusercontent.com/melwinlobo18/K-Nearest-Neighbors/master/Dataset/data.csv'
df = pd.read_csv(url)  # Dataset - Breast Cancer Wisconsin Data

# Map non numeric columns, in this case, diagnosis
df['diagnosis'] = df['diagnosis'].map({
    'M': 1,
    'B': 2
})  # Label values - 1 for Malignant and 2 for Benign

labels = df['diagnosis'].tolist()
df['Class'] = labels  #Copying values of diagnosis to newly alreated labels column
df = df.drop(['id', 'Unnamed: 32', 'diagnosis'], axis=1)  #Dropping unncessary columns
df.head(5)  #Displaying first five rows of the dataset

df.shape
target_names = ['', 'M', 'B']
df['attack_type'] = df.Class.apply(lambda x: target_names[x])
df.head(5)
df1 = df[df.Class == 1]
df2 = df[df.Class == 2]

plt.xlabel('concavity_worst')
plt.ylabel('symmetry_worst')
plt.scatter(df1['concavity_worst'], df1['symmetry_worst'], color='green', marker='+')
plt.scatter(df2['concavity_worst'], df2['symmetry_worst'], color='blue', marker='.')

X = df.drop(['Class', 'attack_type'], axis='columns')
X.head()

y = df.Class
y.head()

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

print(len(X_train))
print(len(X_test))

model = SVC(kernel='linear')
model.fit(X_train, y_train)

predictions = model.predict(X_test)

print(predictions)

percentage = model.score(X_test, y_test)


from sklearn.metrics import confusion_matrix
res = confusion_matrix(y_test, predictions)
print("Confusion Matrix")
print(res)
TN, FP, FN, TP = confusion_matrix(y_test, predictions).ravel()

# Stampa dei risultati
print("True Negatives:", TN)
print("False Positives:", FP)
print("False Negatives:", FN)
print("True Positives:", TP)
print(f"Test Set: {len(X_test)}")
print(f"Accuracy = {percentage*100} %")

import numpy as np

nr = [19.81,22.15,350,1260,0.09831,0.1027,0.1479,0.09498,0.1582,0.05395,5.7582,1.017,18.865,3000.4,0.006494,0.01893,0.03391,0.01521,0.1,0.001997,27.32,30.88,186.8,2398,0.1512,0.315,0.5372,0.2388,0.2768,0.076155]
nr_reshaped = np.array(nr).reshape(1, -1)

predictions = model.predict(nr_reshaped)
print(predictions)
