#populates a python dict of top movies in theaters.
from bs4 import BeautifulSoup
import requests

try:
    page = requests.get('https://www.imdb.com/movies-in-theaters/?ref_=nv_mv_inth')
except:
    print("Connection Error.")
    f = open("movies.txt", "w")
    f.write("Connection Error.")
    f.close()
    exit()
soup = BeautifulSoup(page.text, 'html.parser')

numNones = 0


#Get all movie titles
movies = soup.find_all("h4")
isFirst = True
inTheaters = []
for i in movies:
    if (i.string is not None) and (isFirst == False):
        info = {'name':i.string[1:]}
        inTheaters.append(info)
    else:
        isFirst = False
        numNones+=1

#Get all movie descriptions
desc = soup.find_all("div")
cur = 0
index = 0
for i in desc:
    if ((i.get("class") == ["outline"]) and (cur >= numNones)):
        if (i.string is not None):
            inTheaters[index]['description'] = i.string[5:][:len(i.string)-25]
        else:
            inTheaters[index]['description'] = "(None Given)"
        index+=1
    elif ((i.get("class") == ["outline"])):
        cur+=1

#Get all IMDB scores
allSpans = soup.find_all("span")
allRatings = []
isFirst = True
index = 0
for i in allSpans:
    if (i.get("class") is not None):
        if ((i.get("class") == ["value"])):
            inTheaters[index]['score'] = float(i.string)
            index+=1

for i in inTheaters:
    print(i)            
