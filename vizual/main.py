#!/Users/vifonne/.brew/bin/python3
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
win_w = 1920
win_h = 1080
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
def gen_coord(room):
	i = 0
	while i < len(room[1]):
		room[1][i] = randint(0, win_w - room_w)
		# int((room[1][i]*(win_w-room_w))/max(room[1]))
		room[2][i] = randint(0, win_h - room_h)
		# int((room[2][i]*(win_h-room_h))/max(room[2]))
		i += 1
	return room;
def	print_map(room):
	done = False
	i = 0
	pg.init()
	tmp_x = 0
	tmp_y = 0
	screen = pg.display.set_mode([win_w, win_h])
	bg = pg.image.load("dirt800x535.jpg")
	bg = pg.transform.scale(bg, (win_w, win_h))
	screen.blit(bg, [0, 0])
	while not done:
		for event in pg.event.get():
			if event.type == pg.QUIT:
				done = True
		while i < len(room[3]):
			pg.draw.line(screen, white, (room[1][room[3][i]]+room_w/2, room[2][room[3][i]]+room_h/2), (room[1][room[4][i]]+room_w/2, room[2][room[4][i]]+room_h/2 ), 2)
			i += 1
		i = 0
		while (i < len(room[1])):
			pg.draw.rect(
				screen,
				brown,
				pg.Rect(room[1][i], room[2][i], room_w, room_h))
			pg.draw.rect(
				screen,
				white,
				pg.Rect(room[1][i], room[2][i], room_w, room_h),
				2)
			i += 1
		pg.display.flip()
	pg.quit()

def	main():
	l_stdin = read_stdin()
	room = parse_stdin(l_stdin)
	room = gen_coord(room)
	print_map(room)
	sys.exit()
main()
