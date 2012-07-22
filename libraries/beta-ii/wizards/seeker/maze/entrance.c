// Seeker ��� iuis.org  Thursday July 27 2000 -- 04:44 -07:00

#include "maze.h"

inherit BASE_ROOM;

void create()
{
 ::create();
 set_short("..Lost in the maze..");
 set_long("You are at the entrance of the maze...");
 set_exits( ([ "maze" : NEW_MAZE ]) );
 set_xyz( ({0,0,0}) );
 MAZE_DAEMON->add_maze( ({0,0,0}), file_name(this_object()));
}
