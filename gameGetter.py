from bs4 import BeautifulSoup
import requests

filename = "games.txt"
website = "https://store.steampowered.com/search/?sort_by=Reviews_DESC&filter=topsellers"

try:
    page = requests.get(website)
except:
    print("Connection Error.")
    f = open(filename, "w")
    f.write("Connection Error.")
    f.close()
    exit()
soup = BeautifulSoup(page.text, 'html.parser')

#Get names
allGames = []
for i in soup.find_all("span"):
    if i.get("class") == ["title"]:
        newGame = {}
        newGame['name'] = i.string
        allGames.append(newGame)

#Get prices
index = 0
for i in soup.find_all("div"):
    if i.get("class") == ['col', 'search_price', 'responsive_secondrow']:
        price = int(round(float(i.string[11:len(i.string)-7])))
        if price == 0:
            allGames[index]['price_rating'] = "free"
        else:
            number_of_dollar_signs = int(round(price/12))+1
            dollar_signs = ""
            for x in range(number_of_dollar_signs):
                dollar_signs+="$"
            allGames[index]['price_rating'] = dollar_signs
        index+=1

#Get Descriptions
index = 0
for i in allGames:
        allGames[index]['description'] = "(Couldn't Retrieve)"
        index+=1

#Get Ratings
index = 0
for i in soup.find_all("span"):
    if i.get("class") == ['search_review_summary', 'positive']:
        allGames[index]['score'] = int(i.get('data-tooltip-html')[27:29])/10
        index+=1

#Get Tags
for i in allGames:
    i['tags'] = ['game']

#Write
f = open(filename, "w")
for i in allGames:
    try:
        f.write(str(i)+"\n")
    except:
        continue
f.close()

