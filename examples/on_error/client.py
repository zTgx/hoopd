import http.client
import urllib.parse

url = urllib.parse.quote("/api/v2/error1", safe=':/?=&')

conn = http.client.HTTPConnection("127.0.0.1", 9527)

conn.request("GET", url)

res = conn.getresponse()

print(res.read())

conn.close()