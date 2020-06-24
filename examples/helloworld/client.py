import http.client

conn = http.client.HTTPConnection("127.0.0.1:9527")

conn.request("GET", '/api/v2/hi')

res = conn.getresponse()

print(res.read())

conn.close()