#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1 ]));
    set_short("The church attic.");
    set_long(
      "A large empty room.  The room is lit by glowing baskets.  In the center of "
      "the room, there is an altar.  The altar has an inscription on it."
    );
    set_items(([
	"altar" : "The altar is a simple pillar with hands held in prayer carved upon it.", 
	"inscription" : "We leave this altar as thanks for allowing us the use of the attic.",
      ]));
    set_exits(([
	"down" : ROOMS"church"
      ]));
}

/*void init() {	*/
/* ::init();	*/
/* add_action("go_illuminati", "twist");	*/
/*}	*/

/*int go_illuminati(string str) {	*/
/*  if(str != "band")	*/
/*    return 0;	*/
/*    if(this_player()->query_guild() != "illuminati")	*/
/*      return 0;	*/
/*this_player()->move_player(load_object("/d/guilds/illuminati/rooms/tirunhall.c"), "down");	*/
/*    return 1; 	*/
/*}	*/
