#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "light" : 2, "no teleport":1, "indoors":1]) );
    set_short("storage room");
    set_long("This is the forsaken's storage room. Get the hell "
      "out of here.");
    set_exits(([ "south" : ROOMS"forsaken/itemshop", ]));
    set("skill level", 0);
}
void reset() {
    int i = 0;
    int v = 0;
    int fucku = 0;
    int damn = 0;
    int a,b,c;
    ::reset();
    if(!present("websack"))
        while(++damn < 4) 
            new("/d/guilds/forsaken/obj/sack")->move(this_object());
    if(!present("sash"))
        while(++fucku < 4) 
            new("/d/guilds/forsaken/obj/sash")->move(this_object());
    while(++i < 4) {
        if(!present("blade "+i))
            new("/d/guilds/forsaken/obj/dagger")->move(this_object());
    }
    i = 0;
    while (++i < 2){
        if(!present("pike "+i))
            new("/d/guilds/forsaken/obj/spike")->move(this_object());
    }
    if(!present("book"))
        new("/d/guilds/forsaken/obj/book")->move(this_object());
    if(!present("wings"))
        new("/d/guilds/forsaken/obj/dwings")->move(this_object());
    if(!present("cladding"))
        new("/d/guilds/forsaken/obj/ccladding.c")->move(this_object());
    if(!present("demon helm"))
        new("/d/guilds/forsaken/helm.c")->move(this_object());
    if(!present("forsakenhealingring"))
        new("/d/guilds/forsaken/obj/forsakenhealingring.c")->move(this_object());
    if(!present("platemail"))
        new("/d/guilds/forsaken/obj/rmail.c")->move(this_object());
    i = 0;
    while (++i < 2){
        if (!present("tetsubo "+i))
             new("/d/guilds/forsaken/tetsubo.c")->move(this_object());
    }
    i = 0;
    while (++i < 2){
        if (!present("sword "+i))
            new("/d/guilds/forsaken/obj/sword")->move(this_object());
    }
}
