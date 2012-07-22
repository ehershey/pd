#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("Sabai Fortress");
    set_long(
      "This island is quite small, it is just big enough to hold a "
      "hut and a statue.  There are four bridges that leads away from "
      "the island."
    );
  
    set_items(([
        "island" : "Big enough for a hut and a statue.",
        "bridge" : "There are four of them that leads away from the island.",
        "hut" : "It is to the west of here.",
        "mirage" : "This one is the real thing.",
    ]));
    set_listen("default", "Sounds of Peace and Tranquility.");
    set_exits( ([
"northwest" : FORT "fort16",
"southeast" : FORT "fort8",
"northeast" : FORT "fort17",
"southwest" : FORT "fort7",
"west" : FORT "fort11",
    ]) );
}
void reset() {
 ::reset();
   if (!present("statue", this_object()))
     new( ITEMS "isha.c" )->move(this_object());
   if (!present("tonberry", this_object()))
     new( MOB "tonberry" )->move(this_object());
     new( MOB "tonberry" )->move(this_object());
     new( MOB "tonberry" )->move(this_object());
     new( MOB "tonberry" )->move(this_object());
}
void init()
{
 ::init();
 add_action("pray", "pray");
}
int pray(string str)
{
 if (str!="to Isha") return notify_fail("You give praise to Isha!\n");
 if (this_player()->query_class()!="monk")
   {
    write("You give praise to Isha!");
    return 1;
    }
   write("%^CYAN%^The statue opens up and swallows you whole!");
 this_player()->move_player(FORT "mohall", "gets swallowed whole by the
statue.");
return 1;
}
