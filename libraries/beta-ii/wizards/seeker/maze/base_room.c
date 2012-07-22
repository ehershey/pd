// Seeker ��� iuis.org  Thursday July 27 2000 -- 04:44 -07:00

#include "maze.h"

inherit ROOM;

int X, // west - east
    Y, // north - south
    Z; // up - down
void create()
{
 room::create();
}

int set_xyz(int *i)
{
 if (sizeof(i) < 3) return -1;
 X = i[0];
 Y = i[1];
 Z = i[2];
 return 1;
}
int *query_xyz()
{ 
 return ({X,Y,Z});
}
int set_maze_exits(mapping t)
{
 set_exits(t);
}

int use_exit()
{
 int *x;
 string exit;
 object ob;

 exit = query_verb();
 if (query_exit(exit)==NEW_MAZE)
   {

    switch(exit)
     {
      case "north":
       if (MAZE_DAEMON->query_maze(({X,Y+1,Z}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X,Y+1,Z})),exit);
      return ::use_exit(); }
         break;
     case "south":
       if (MAZE_DAEMON->query_maze(({X,Y-1,Z}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X,Y-1,Z})),exit);
       return ::use_exit(); }
         break;
     case "east":
       if (MAZE_DAEMON->query_maze(({X+1,Y,Z}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X+1,Y,Z})),exit);
       return ::use_exit(); }
         break;
     case "west":
       if (MAZE_DAEMON->query_maze(({X-1,Y,Z}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X-1,Y,Z})),exit);
       return ::use_exit(); }
         break;
     case "up": case "out":
       if (MAZE_DAEMON->query_maze(({X,Y,Z+1}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X,Y,Z+1})),exit);
       return ::use_exit(); }
         break;
     case "down": case "maze":
       if (MAZE_DAEMON->query_maze(({X,Y,Z-1}))) {
     this_object()->add_exit( MAZE_DAEMON->query_maze(({X,Y,Z-1})),exit);
       return ::use_exit(); }
         break;
     }
    ob = MAZE_DAEMON->make_room(OPPOSITES[exit],file_name(this_object()));
    switch(exit)
     {
      case "north": x= ({ X, Y+1, Z }); break;
      case "south": x= ({ X, Y-1, Z }); break;
      case "west":  x= ({ X-1, Y, Z }); break;
      case "east":  x= ({ X+1, Y, Z }); break;
      case "up":   case "out":   x=({ X, Y, Z+1 }); break;
      case "down": case "maze":  x=({ X, Y, Z-1 }); break;
     }
    ob->set_xyz(x);
    MAZE_DAEMON->add_maze(x, file_name(ob));
    this_object()->add_exit(file_name(ob), exit);
   }
 
 return ::use_exit();
}
