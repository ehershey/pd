#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("cave", 1);
    set("short", "Shadow's Inn");
    set("long",
        "Welcome to Shadow's Inn!\n"
        "The Shadow's Inn was established many many moons ago, "
        "in the time before light invaded.  These days it is serving "
        "those who are worthy and is a great place to grab a drink "
                ]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
    if(!present("milu"))
      new(MOB"milu")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("milu");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    message("info", "The following classic drinks are served at the Shadow's Inn!",
this_player());
    message("info", "-----------------------------------------------------------
", this_player());
    message("info", "A shadowfire\t\t\t"+ (int)ob->get_price("shadowfire")+"
 gold", this_player());
    message("info", "A bloodied marry\t\t\t"+(int)ob->get_price("marry")+"
 gold", this_player());
    message("info", "A pale version\t\t\t"+(int)ob->get_price("shadowlite")+" gold", 
this_player());
    message("info", "-----------------------------------------------------------
", this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}
