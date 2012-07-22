#include <std.h>
#include <tirun.h>
#include <daemons.h>

inherit ROOM;
   object ob;
void create() {

   ::create();
   set_name("Portal Room South");
   set_short("Tirun Portal Room South");
   set_long("This end of the hall is well lit and has a board full of messages hanging on the wall. To the north glowing portal pulses with light.");
   set_exits((["north": ROOMS"portal_room",]));
   set_properties((["light":2, "night light":2, "indoors":1, "no attack":1, "no steal":1, "no magic":1]));
    ob = new(BBOARD);
    ob->set_name("discussion board");
    ob->set_location("/d/nopk/tirun/gbroom.c");
    ob->set_id( ({ "board", "discussion board" }) );
    ob->set_board_id("discussion_board");
    ob->set_max_posts(999);
    ob->set_short("Discussion Board");
    ob->set_long("The Discussion Board.");
}
