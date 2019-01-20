#!/Library/Frameworks/Python.framework/Versions/3.7/bin/python3
#/usr/bin/python
import  sys
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
colors = [red, green, blue, white, pink]
win_w = 800
win_h = 535
room_w = 40
room_h = 30
def	read_stdin():
	l_stdin = []
	for line in sys.stdin:
		l_stdin.append(line)
	return l_stdin;

def	parse_stdin(l_stdin):
	x = []
	y = []
	name = []
	pipe_l = []
	pipe_r = []
	room = [name, x, y, pipe_l, pipe_r]
	ant = int(l_stdin[0])
	l_stdin.pop(0)
	for line in l_stdin:
	    if len(line.split()) == 3:
	        name.append(line.split()[0])
	        x.append(int(line.split()[1]))
	        y.append(int(line.split()[2]))
	    elif len(line.split("-")) == 2:
		    ret = line.split("-")
		    pipe_l.append(name.index(ret[0].rstrip()))
		    pipe_r.append(name.index(ret[1].rstrip()))
	return room;
def	print_map(room):
	done = False
	i = 0
	j = 0
	pg.init()
	tmp_x = 0
	tmp_y = 0
	screen = pg.display.set_mode([win_w, win_h])
	bg = pg.image.load("dirt800x535.jpg").convert()
	screen.blit(bg, [0, 0])
	while not done:
		for event in pg.event.get():
			if event.type == pg.QUIT:
				done = True
		while (i < len(room[1])):
			coordx = randint(0, win_w - room_w)
			#int((x[i]*(width-rectw))/max(x))
			coordy = randint(0, win_h - room_h)
			#int((y[i]*(height-recth))/max(y))
#				pg.draw.line(
#					screen,
#					white,
#					(coordx+room_w/2 + 2, coordy+room_h/2 + 2),
#					(tmp_x+room_w/2 + 2, tmp_y+room_h/2 + 2), 2)
			room[1][i] = coordx
			room[2][i] = coordy
			pg.draw.rect(
				screen,
				brown,
				pg.Rect(coordx, coordy, room_w, room_h))
			pg.draw.rect(
				screen,
				white,
				pg.Rect(coordx, coordy, room_w, room_h),
				2)
			tmp_x = coordx
			tmp_y = coordy
			i += 1
		j = 0
		while j < len(room[3]):
			src_x = room[1][room[3].index(room[3][j])]
			src_y = room[2][room[3].index(room[3][j])]
			dst_x = room[1][room[4].index(room[4][j])]
			dst_y = room[2][room[4].index(room[4][j])]
			print(src_x)
			pg.draw.line(
				screen,
				white,
				(src_x, src_y),
				(dst_x, dst_y),
				2
			)
			j += 1
		pg.display.flip()
	pg.quit()

def	main():
	l_stdin = read_stdin()
	room = parse_stdin(l_stdin)
	print_map(room)
	sys.exit()
main()
