#!/Library/Frameworks/Python.framework/Versions/3.7/bin/python3
#/usr/bin/python
import  sys
import  matplotlib.pyplot as plt
import	pygame as pg
from	random import *
import	time
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
darkBlue = (0,0,128)
white = (255,255,255)
black = (0,0,0)
pink = (255,200,200)
brown = (61, 31, 33)
colors = [red, green, blue, white , pink]
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
        x.append(int(line.split()[1]))
        y.append(int(line.split()[2]))
    elif len(line.split("-")) == 2:
        ret = line.split("-")
        connectpoints(x, y, name.index(ret[0].rstrip()), name.index(ret[1].rstrip()))
i = 0
while i < len(name):
    plt.text(x[i], y[i], name[i], position=(x[i] + 7, y[i] + 7))
    i += 1
plt.axis('off')
plt.plot(x, y, 'bs', color=fg_color, markersize=20)
plt.tight_layout()
plt.margins(0.07)
#plt.show()
done = False
pg.init()
width = 800
height = 535
rectw = 40
recth = 30
size = (width, height)
i = 0
j = 0
coordxprev = 0
coordyprev = 0
screen = pg.display.set_mode(size)
bg = pg.image.load("dirt800x535.jpg").convert()
screen.blit(bg, [0, 0])
while not done:
	for event in pg.event.get():
		if event.type == pg.QUIT:
			done = True
	while (i < len(x)):
		coordx = randint(0, width - rectw)
		#int((x[i]*(width-rectw))/max(x))
		coordy = randint(0, height - recth)
		#int((y[i]*(height-recth))/max(y))
		print (coordx, coordy)
		if (i > 0):
			pg.draw.line(screen, white, ((coordx+rectw/2), (coordy+recth/2)), ((coordxprev+rectw/2), (coordyprev+recth/2)), 2)
		pg.draw.rect(screen, brown, pg.Rect(coordx, coordy, rectw, recth))
		pg.draw.rect(screen, white, pg.Rect(coordx, coordy, rectw, recth), 2)
		coordxprev = coordx
		coordyprev = coordy
		i += 1
	pg.display.flip()
pg.quit()
sys.exit()
