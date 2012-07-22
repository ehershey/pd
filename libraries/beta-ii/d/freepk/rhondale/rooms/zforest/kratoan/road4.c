#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
     object oi;
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The central market of Kra'Toa'Kathor is quite busy in the day. All the stores have been set up in one large ring with all the shopkeepers on the inside. Many villagers are crowded trading in their crafts for food and spices. Several people are also congregrated around the local notices board.");
     set_night_long("The central market of Kra'Toa'Kathor is quiet at night. Though there are very few people who do their shopping at night, the stalls are still open for trade ready to trade goods with the hunters who have been out all day. Sometimes a hunter will return and check what seems to be the local noticeboard.");
     set_exits(([
		"west"			: KEEPROOM"zforest/kratoan/road3.c",
		"east"			: KEEPROOM"zforest/kratoan/road5.c",

                ]));
     set_items(([
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/dx'zal.c")->move(this_object());
	}

oi = new("/std/bboard");
oi->set_name("Kra'Toa'Kathor Noticeboard");
oi->set_id( ({ "board" }) );

oi->set_board_id("Kratoan_Board");
oi->set_max_posts(99);
oi->set_edit_ok(({ "amarael" }));
oi->set_location(KEEPROOM"zforest/kratoan/road4.c");
oi->set("short", "Kra'Toa'Kathor Noticeboard");
oi->set("long", "The notice board is here for villagers to exchange important information when they cannot meet. \n");
}
