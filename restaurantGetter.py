import requests
import json

API_KEY = "DXT5Ta-H8o4Q7SuBuSD3Hr_HQmYO_7s7_cfFZiMGZ_P4L-lT1vv1JtnsPx56yFZouXR1fOZ_UWpDQbOxz4OYuipm1fBUVtrTsa_iZLk6zD-Hcl8ZQ4X6t7Kl4K7LW3Yx"

API_HOST = 'https://api.yelp.com'
BUSINESS_PATH = '/v3/businesses/'

def get_business(business_id):
    business_path = BUSINESS_PATH + business_id
    url = API_HOST + business_path + '/reviews'
    headers = {'Authorization': f"Bearer {API_KEY}"}

    response = requests.get(url, headers=headers)

    return response.json()

def get_ip_address():
    print("HEY YOU, FIX ME")

def get_location_string():
    response = requests.get("http://api.ipstack.com/check?access_key=4f22d0655bcc617eea48e0ee383e599d&fields=zip")
    print(response)
    responseString = response.content.decode("utf-8")
    print(responseString)
    responseJSON = json.loads(responseString)
    print(responseJSON)
    return response.json()['zip']

def get_search_parameters(lat,long):
  #See the Yelp API for more details
  params = {}
  params["term"] = "restaurant"
  #params["latitude"] = str(lat)
  #["longitude"] = str(long)
  #params["radius"] = "10000"
  params["limit"] = "10"
  params['location'] = get_location_string()
 
  return params

url = "https://api.yelp.com/v3/businesses/search"
response = requests.get(url, headers = {'Authorization': f"Bearer {API_KEY}"}, params = get_search_parameters(38.9, 94.7))
responseJSON = response.json()
#print(response.json())

f = open("restaurants.txt", "w")
for i in responseJSON['businesses']:
    newRestaurant = {}
    newRestaurant['name'] = i['name']
    newRestaurant['price_rating'] = i['price']
    newRestaurant['description'] = "(None Given)"
    newRestaurant['score'] = i['rating']
    allTags = []
    for x in i['categories']:
        allTags.append(x['title'])
    newRestaurant['tags'] = allTags
    f.write(str(newRestaurant)+"\n")
f.close()
