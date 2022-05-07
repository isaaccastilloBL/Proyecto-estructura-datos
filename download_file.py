import requests
from os import system

URL = "https://museosedd.000webhostapp.com/museos.txt"
file = requests.get(URL, stream = True)

with open("museos.txt","wb") as pdf:
    for chunk in file.iter_content(chunk_size=1024):

        if chunk:
            pdf.write(chunk)


system("wget https://museosedd.000webhostapp.com/duende.jpg")
system("wget https://museosedd.000webhostapp.com/ferrocarril.jpg")
system("wget https://museosedd.000webhostapp.com/fotografia.jpg")
system("wget https://museosedd.000webhostapp.com/futbol.jpg")
system("wget https://museosedd.000webhostapp.com/mineria.jpg")
system("wget https://museosedd.000webhostapp.com/miniaturas.jpg")
system("wget https://museosedd.000webhostapp.com/paste.jpg")
system("wget https://museosedd.000webhostapp.com/rehilete.jpg")
system("wget https://museosedd.000webhostapp.com/santo.jpg")
system("wget https://museosedd.000webhostapp.com/tula.jpg")
