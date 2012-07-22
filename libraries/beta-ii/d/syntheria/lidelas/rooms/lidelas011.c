#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    object board;
    ::create();
        set_name("lidelas hall");
        set_short("Lidelas Hall");
        set_long("This is the main hall of Lidelas, all of the citizens of the town come here to share ideas and plan for events. The hall is very large, the main room takes up virtually the entire structure. Large banners take up the spaces between the windows, each banner has a family crest on it. Bellow each banner, there is a large torch that lights the banner. Every torch is made of pure gold, the light dances off of the torch. The floor is made from a very fine marble, the light from the torches reflects off of the floor making the room very bright. Every stain glassed window has a unique scene in it.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"banners"      :   "Each banner holds the crest of one of the families that founded Lidelas.",
    	"windows"      :   "The windows have very fine detail.",
    	"torches"      :   "Large golden torches that light the hall."
	    ]));
	    set_listen("default", "People chatting about current events can be heard bouncing off the walls");
	    set_smell("default", "The smell of burning oil fills the hall.");
	    set_exits(([
			"north"		: ROOMS "lidelas010.c",

        ]));
        
        
        board = new("std/bboard");
        board->set_name("lidelas_board");
        board->set_id( ({ "board", "lidelas board" }) );
        board->set_max_posts(99);
        board->set_edit_ok(({"stormbringer","nightshade","seeker","daos","whit", "daboura"}));
        board->set_location(ROOMS"lidelas011.c");
        board->set("short", "Lidelas Board");
        board->set("long", "This board is where people from the town of Lidelas come to share ideas.\n");
        board->set_board_id("lidelas_board");

}


