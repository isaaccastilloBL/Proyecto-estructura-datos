import requests
URL = "https://museosedd.000webhostapp.com/videojuegos.txt"
file = requests.get(URL, stream = True)

with open("museos.txt","wb") as pdf:
    for chunk in file.iter_content(chunk_size=1024):

        if chunk:
            pdf.write(chunk)
