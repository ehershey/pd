// Seeker ��� iuis.org  Thursday July 27 2000 -- 04:44 -07:00

#include "maze.h"

mapping maze;

void create()
{
 maze = ([]);
}

string add_maze(int *x, string path)
{
 string st;
 
 st = sprintf("%d,%d,%d", x[0], x[1], x[2]);
 if (maze[st]) return maze[st];
 maze[st] = path;
 return "";
}
string query_maze(int *x)
{
 string st;
 
 st = sprintf("%d,%d,%d", x[0], x[1], x[2]);
 return maze[st];
}
object make_room(string prevdir, string prevpath)
{
 object ob;
 int i, a, b;
 mapping t;
 string addtl, *key,tmp;

 t = ([]);
 i = sizeof(EXITS);
 ob = new(BASE_ROOM);
 t[prevdir] = prevpath;
 while(i--)
  {
   if (EXITS[i]==prevdir) continue;
   a = !(random(11)<4);
   if (a && (random(2500) < 100)) 
     {
      if (!t["down"])
      t [ "down" ] = NEW_MAZE;
      
     }
   
   if (a)
     t[ EXITS[i] ] = NEW_MAZE;
  }
 ob->set_short("...Lost in the maze...");

 b = random( sizeof(MAZE_SET_LONG) );
 if (b) b--;

 key = keys(t);
 i = sizeof(key);
 a = i;
 if (i < 2)
   addtl = "\nThere is only "+cardinal(i)+" path you can go on: ";
 if (i >= 2) 
  addtl = "\nThere are "+cardinal(i)+" paths you can go on: ";
 while(i--)
 {
   if (i)
  addtl += key[i]+", ";
  if (!i && a >= 2)
    addtl += "and "+key[i]+".";
  if (!i && a < 2) addtl += key[i]+".";
 } 
 ob->set_long(MAZE_SET_LONG[ b ]+addtl);

 ob->set_maze_exits(t);    
 return ob;
}

mapping query_allmaze() { return maze; }
