#!/usr/bin/python
import  sys
import  matplotlib.pyplot as plt
mapread = []
x = []
y = []
name = []
fg_color = 'red'
def connectpoints(x, y, p1, p2, ):
    x1, x2 = x[p1], x[p2]
    y1, y2 = y[p1], y[p2]
    plt.plot([x1, x2], [y1, y2], lw=4)

for line in sys.stdin:
    mapread.append(line)
ant = int(mapread[0])
mapread.pop(0)
for line in mapread:
    if len(line.split()) == 3:
        name.append(line.split()[0])
        x.append(int(line.split()[1]) * 30)
        y.append(int(line.split()[2]) * 30)
    elif len(line.split("-")) == 2:
        ret = line.split("-")
        connectpoints(x, y, name.index(ret[0].rstrip()), name.index(ret[1].rstrip()))
i = 0
while i < len(name):
    plt.text(x[i], y[i], name[i], position=(x[i] + 7, y[i] + 7))
    i += 1
#plt.axis('off')
plt.plot(x, y, 'bs', color=fg_color, markersize=20)
plt.tight_layout()
plt.margins(0.07)
plt.show()
