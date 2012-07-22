#include <std.h>
#include <helgrath.h>
inherit ROOM;
void init() {
    ::init();
    add_action("tap_stone", "tap");
}
void create() {
    ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
                    "no steal"    : 1 ]) );
    set_short("Wilndur Square");
    set_long("This is the very center of this bustling community. The two main
roads of Helgrath "
      "intersect here heading off in the four cardinal directions for as far as
the eye can see. Running north "
      "to south is Yull Boulevard, and east to west is Market road. A large,
intricately crafted fountain stands "
      "proudly in the center of the square. " );
    set_exits( ([ "north" : ROOMS "wilndursquare_mt.c",
        "south" : ROOMS "wilndursquare_mb.c",
        "east" : ROOMS "wilndursquare_em.c",
        "west" : ROOMS "wilndursquare_wm.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}


int tap_stone(string str) {
    if(!str) {
        notify_fail("Do what?\n");
        return 0;

    }
    if(str != "stone") {
        notify_fail("You can't do that here!!\n");
        return 0;
    }
    

    message("info", "Something in the ground shifts aside, revealing an entrance.", this_player());
    add_exit("/d/guilds/acheron/helentrance", "down");
    call_out("go_hole", 15);
    return 1;
}

void go_hole() {
    message("info", "Something shifts in the ground....",
all_inventory(this_object()));
    remove_exit("down");
}
void reset(){
    ::reset();
    if(present("fountain")) return;
    new(ITM"fountain.c")->move(this_object());
}
