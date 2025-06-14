from warnings import simplefilter

# ignore all future warnings
simplefilter(action='ignore', category=FutureWarning)

from sklearn.feature_extraction.text import TfidfVectorizer

docA = "The car is driven on the read"
docB = "The truck is driven on the highway"

tfidf = TfidfVectorizer()

response = tfidf.fit_transform([docA, docB])

feature_names = tfidf.get_feature_names_out(input_features=None)

for col in response.nonzero()[1]:
    print (feature_names[col], ' - ', response[0, col])
