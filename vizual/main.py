#!/Usr/bin/python
import  sys
import  matplotlib.pyplot as plt
mapread = []
x = []
y = []
name = []
def connectpoints(x, y, p1, p2):
    x1, x2 = x[p1], x[p2]
    y1, y2 = y[p1], y[p2]
    plt.plot([x1, x2], [y1, y2])

for line in sys.stdin:
    mapread.append(line)
ant = int(mapread[0])
mapread.pop(0)
for line in mapread:
    if len(line.split()) == 3:
        name.append(line.split()[0])
        x.append(int(line.split()[1]))
        y.append(int(line.split()[2]))
    elif len(line.split("-")) == 2:
        ret = line.split("-")
        connectpoints(x, y, name.index(ret[0].rstrip()), name.index(ret[1].rstrip()))
i = 0
while i < len(name):
    plt.text(x[i], y[i], name[i])
    i += 1
plt.axis('off')
plt.plot(x, y, 'bs')
plt.show()
