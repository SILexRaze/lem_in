#!/Users/vifonne/.brew/bin/python3
import  sys
import	pygame as pg
from	random import *
from	math import *
import	time
import	d_v_p as ft_math
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
room_w = 90
room_h = 70
ant_size = 95
speed = 30
ant_m = []
x_m = []
y_m = []
room_m = [x_m, y_m]
move = [ant_m, room_m]
start_img = pg.transform.scale(pg.image.load("start.png"), (room_w, room_h))
end_img = pg.transform.scale(pg.image.load("end.png"), (room_w, room_h))
ant_p1 = pg.transform.scale(pg.image.load("pos1_ant_bl.png"), (ant_size, ant_size))
ant_p2 = pg.transform.scale(pg.image.load("pos2_ant_bl.png"), (ant_size, ant_size))
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
			x.append(randint(0, win_w - room_w))
			y.append(randint(0, win_h - room_h))
		elif len(line.split("-")) == 2 and line.split("-")[0][0] != 'L':
			ret = line.split("-")
			pipe_l.append(name.index(ret[0].rstrip()))
			pipe_r.append(name.index(ret[1].rstrip()))
		elif line.split("-")[0][0] == 'L':
			ret = line.split("-")
			move[0].append(ret[0].rstrip())
			move[1][0].append(x[name.index(ret[1].rstrip())]+room_w/2)
			move[1][1].append(y[name.index(ret[1].rstrip())]+room_h/2)
	print("\n", x,"\n",move[1][0],"\n", y,"\n",move[1][1])
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
	pg.font.init()
	dst_x = []
	dst_y = []
	dst = [dst_x, dst_y]
	src_x = []
	src_y = []
	src = [src_x, src_y]
	screen = pg.display.set_mode([win_w, win_h])
	bg = pg.image.load("dirt800x535.jpg")
	
	bg = pg.transform.scale(bg, (win_w, win_h))
	room_name = pg.font.SysFont('Arial', 25)
	screen.blit(bg, [0, 0])
	while i < len(room[3]):
		src[0].append(room[1][room[3][i]]+room_w/2)
		src[1].append(room[2][room[3][i]]+room_h/2)
		dst[0].append(room[1][room[4][i]]+room_w/2)
		dst[1].append(room[2][room[4][i]]+room_h/2)
		pg.draw.line(screen, white, (dst[0][i], dst[1][i]), (src[0][i], src[1][i]), 2)
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
		if room[0][i] == "start":
			screen.blit(start_img, (room[1][i], room[2][i]))
			ant_p = [room[1][i], room[2][i]]
		elif room[0][i] == "end":
			screen.blit(end_img, (room[1][i], room[2][i]))
		s_room_name = room_name.render(room[0][i], False, (255, 255, 255))
		screen.blit(s_room_name, (room[1][i], room[2][i]- 20))
		i += 1
	solid_bg = pg.Surface.copy(screen)
	flag = True
	anim = True
	i = 0
	while not done:
		a = ft_math.Point(ant_p[0]+room_w/2, ant_p[1]+room_h/2)
		b = ft_math.Point(move[1][0][0], move[1][1][0])
		for event in pg.event.get():
			if event.type == pg.QUIT:
				done = True
		while i < (len(move[1][0])) and anim and not done:
			d1 = ft_math.Droite(a, b)
			if (ant_p[0] > move[1][0][i]):
				while ant_p[0] > move[1][0][i] and ant_p[1] != move[1][1][i] and not done:	
					flag = not flag
					for event in pg.event.get():
						if event.type == pg.QUIT:
							done = True
					screen.blit(solid_bg, [0, 0])
					if flag:
						rot_p1 = pg.transform.rotate(ant_p1, 90)
						screen.blit(rot_p1, [ant_p[0]-ant_size/2, ant_p[1]-ant_size/2])
					else:
						rot_p2 = pg.transform.rotate(ant_p2, 90)
						screen.blit(rot_p2, [ant_p[0]-ant_size/2, ant_p[1]-ant_size/2])
					ant_p[0] -= speed
					ant_p[1] = d1.reduite(ant_p[0])
					time.sleep(0.10)
					pg.display.flip()
			else:
				while ant_p[0] < move[1][0][i] and ant_p[1] != move[1][1][i] and not done:
					flag = not flag
					for event in pg.event.get():
						if event.type == pg.QUIT:
							done = True
					screen.blit(solid_bg, [0, 0])
					if flag:
						rot_p1 = pg.transform.rotate(ant_p1, 90)
						screen.blit(rot_p1, [ant_p[0]-ant_size/2, ant_p[1]-ant_size/2])
					else:
						rot_p2 = pg.transform.rotate(ant_p2, 90)
						screen.blit(rot_p2, [ant_p[0]-ant_size/2, ant_p[1]-ant_size/2])
					ant_p[0] += speed
					ant_p[1] = d1.reduite(ant_p[0])
					time.sleep(0.10)
					pg.display.flip()
			if i+1 == len(move[1][0]):
				anim=False
				break
			a = ft_math.Point(move[1][0][i], move[1][1][i])
			b = ft_math.Point(move[1][0][i+1], move[1][1][i+1])
			i += 1
	pg.quit()

def	main():
	l_stdin = read_stdin()
	room = parse_stdin(l_stdin)
	if (room):
		print_map(room)
	sys.exit()
main()
