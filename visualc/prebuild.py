import sys, re, os

def lfcr(file):
    if os.path.isdir(file):
        print file, "Directory!"
        return
    data = open(file, "rb").read()
    if '\0' in data:
        print file, "Binary!"
        return
    newdata = re.sub("\r?\n", "\r\n", data)
    if newdata != data:
        print "Converting '"+file+"' to CRLF format."
        f = open(file, "wb")
        f.write(newdata)
        f.close()


docs = "../docs/"
for doc in os.listdir(docs):
    fullpath = docs+doc
    if os.path.isdir(fullpath): continue
    lfcr(fullpath)


