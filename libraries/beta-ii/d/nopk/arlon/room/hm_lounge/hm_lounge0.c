#include <std.h>
#include <arlon.h>

inherit ROOM;
object board;

void create() {
::create();
   set_short("The Prestigous High Mortal Lounge");
   set_long("A nice room with a fireplace in the corner. "
	    "You feel as if you could stay here all day.");	
            
        set_items(([
                "fireplace" : "Made of fine granite, it has a low burning fire,"
                              "crackling and popping.",]));
        set_properties(([
                         "light" : 1,
                         "night light" : 1,
                         "indoors" : 1,

	]));
    board = new("/std/bboard.c");
    board->set_name("board");
    board->set_id( ({ "board", "High Mortal board" }) );
    board->set_max_posts(80);
    board->set_location("/d/arlon/room/hm_lounge/hm_lounge0.c");
    board->set("short", "High Mortal Board");
    board->set("long", "This board is for the HM's.\n");
    board->set_board_id("High_Mortal");


        
        set_exits(([
        "west" : ROOMS "hm_lounge/hm_lounge1.c",
        "east" : ROOMS "hm_lounge/hm_lounge2.c",
        "south" : ROOMS "esquare1",
        "north" : ROOMS "hm_lounge/hm_lounge5.c",
    ]));
}

int init()
{
 ::init();
 if (this_player()->query_level() < 19)
   {
    write("Only high mortals may enter.");
    this_player()->move("/d/arlon/room/esquare1");
   }
}
