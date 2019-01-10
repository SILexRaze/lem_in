# lem_in
Lem_in is a project of 42 (Paris).
It's about management of ant in a ciruit.

## Signaux pour la gestion d'erreur :
###int	ft_isroom(char *line, t_data *data)
```C
 0	Not enough arguments.
-1	Room is already defined.
-2	Coordinates must be an integer.
-3	Coordinates can't be negative.
-4	Room name can't start with 'L'.
-5	Room name can't start with '#'.
-12	Room cannot overlap with another.
```
###int	ft_ispipe(char *line, t_data *data)
```C
-6	Only one connection can be declared per line.
-7	No connection declared.
-8	You can't connect a room to itself.
-9	Destination of connection missings.
-10	Too few/much connection arguments.
-11	Connection already declared.
```
###int	ft_isvalid_map(t_data *data)
```C
-13	You can only configure 1 "start room" and 1 "end room".
-14	There is no path between start room and end room.
-15	No connection declared.
```
"Toute commande inconnue sera ignoree"
"La premiere ligne non conforme OU VIDE entraine la fin de l'acquisitio"
