#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
object board;
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("plain",1);
    set_short("Fenton Square");
    set_long(
      "This appears to be the busiest part of the whole city thus far.  "
      "Off to the north you see a large tower rising into the sky.  Southwest "
      "you see a rundown house.  Southeast is nothingness.  There is a board here "
      "and next to the board you see a pile of bones."
    );
    set_items(([
 
        "nothingness" : "A whole bunch of nothing.",
        "house" : "Rundown with shingles falling off of what little roof is remaining.",
        "tower" : "Perhaps a wise old mage lives there.",
    ]));

   set_listen("default", "Insane cackling can be heard coming from the north.");
set_exits ( ([ "south" : ROOMS"room6.c", "north" :ROOMS"room11.c"]) );
board = new("std/bboard");
 board->set_name("board");
 board->set_id( ({ "board", "Fenton_board" }) );
 board->set_max_posts(80);
 board->set_location("/wizards/kabaal/fenton/rooms/square.c");
 board->set("short", "The Board of the Undead");
 board->set("long", "This board appears to be in pretty rough shape.\n");
 board->set_board_id("Fenton");
}
