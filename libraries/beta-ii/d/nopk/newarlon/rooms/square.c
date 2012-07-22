#include <std.h>
#include <arlon2.h>
inherit ROOM;
object board;
int cmd_start(string str);

void init()
{
    ::init();
    add_action("cmd_start", "start");
}

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1, "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is present here.");
set_listen("default", "There is a peaceful silence here, with the faint sound of crashing waves.");
set_short("Arlon city square");
set_long("The square of Arlon is situated in the middle of the beach town's Diamond District.  Although the rest of Arlon appears to be busy with all sorts of training and commotion, the square is the one place available for peace and quiet.  There is a large statue of a man in the middle of the square.");
set_exits(([ "north" : ROOMS "roads/17.c",
"south" : ROOMS "roads/15.c",
"east" : ROOMS "23.c",
"west" : ROOMS "21.c"]));
set_items(([
({"plaque"}) : "%^BOLD%^%^YELLOW%^The golden plaque reads:  For Tibinus, the teacher of our land.  Without he, we would not have the knowledge that we have, and our adventures in the lands of Primal Darkness would not be possible.  It is through his guidance and teaching that we become the adventurers that we are today.",
({"commotion", "training"}) : "If you'd like to see the training and commotion, perhaps you should leave the peaceful square!",
]));
    board = new("std/bboard");
    board->set_name("arlon2square");
    board->set_id( ({ "board", "arlon board" }) );
    board->set_max_posts(500);
board->set_edit_ok(({"stormbringer","nulvect","luna","whit","amun","daos","ironman","pyro","randalar","leondal","vian"}));
    board->set_location(ROOMS "square");
    board->set("short", "Arlon board");
    board->set("long", "A very well crafted board has been placed here by the Gods, for the newbie town to have peaceful and orderly discourse.\n");
    board->set_board_id("arlon2square");
}
void reset() {
    ::reset();
        if(!present("statue"))
          new(OBJ "statue")->move(this_object());
                  if(!present("mapstand"))
          new(OBJ "mapstand")->move(this_object());
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
}
int cmd_start(string str)
{
    if (!str || str=="") 
    {
        notify_fail("Start where?\n");
        return 0;
    }

    if (str!="here")
    {
        notify_fail("You cannot start there.\n");
        return 0;
    }

    this_player()->set_primary_start("/d/nopk/newarlon/rooms/square");
    write("You are now set to start here.");
    return 1;
    }
