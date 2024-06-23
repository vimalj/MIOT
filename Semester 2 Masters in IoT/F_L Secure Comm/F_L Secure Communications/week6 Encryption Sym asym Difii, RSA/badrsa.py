from functools import reduce
from Crypto.PublicKey import RSA

def text2Int(text):
    """Convert a text string into an integer"""
    return reduce(lambda x, y : (x << 8) + y, map(ord, text))


key = RSA.generate(4096, e=5)
msg = "welcome Zerodays\n The flag is: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
m = text2Int(msg)
c = pow(m, key.e, key.n)

f = open("outout.txt", "w")
f.write("n = {}".format(key.n))
f.write("\ne = {}".format(key.e))
f.write("\nc = {}".format(c))
f.close()
