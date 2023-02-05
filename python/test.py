import requests


for i in range(1):
    x = requests.get("https://pokeapi.co/api/v2/pokemon/1/")
    print(x.json)