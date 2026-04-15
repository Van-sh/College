import requests

response = requests.get("https://jsonplaceholder.typicode.com/users/1")
print("Status Code:", response.status_code)
print("Response Data:", response.json())
