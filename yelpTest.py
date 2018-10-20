import requests

API_KEY = "DXT5Ta-H8o4Q7SuBuSD3Hr_HQmYO_7s7_cfFZiMGZ_P4L-lT1vv1JtnsPx56yFZouXR1fOZ_UWpDQbOxz4OYuipm1fBUVtrTsa_iZLk6zD-Hcl8ZQ4X6t7Kl4K7LW3Yx"

API_HOST = 'https://api.yelp.com'
BUSINESS_PATH = '/v3/businesses/'

def get_business(business_id):
    business_path = BUSINESS_PATH + business_id
    url = API_HOST + business_path + '/reviews'
    headers = {'Authorization': f"Bearer {API_KEY}"}

    response = requests.get(url, headers=headers)

    return response.json()

results = get_business('la-taqueria-san-francisco-2')
print(results)
