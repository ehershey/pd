#include <std.h>
#include <helgrath.h>
inherit ROOM;



void create() {
    ::create();
    set_properties(([
        "light" : 2,
        "indoors" : 1
      ]));
    set_short("Temple of Circles");
    set_long("This looks to be a scribe or school room.  Several large "
"tables and podiums are arranged in rows around the room. "
"Some of the table have books, quills, ink, and blotters "
"sitting on them, some are empty.  The chamber is circular and "
"has several exits.");
    set_exits( ([ "south" : ROOMS "temple02.c",
      ]));
    set_smell("default", "A hint of incense drifts through the room.");
    set_listen("default", "A faint chanting can be heard.");
    set_items( ([
        "tables" : "The are slightly inclined from one direction and have chairs in front of the lowest part of the tables.",
        "books" : "The books vary from ancient hand-written texts to newer copied texts.",
        "podeums" : "Large wooden podeums with books or notes sitting upon them.",
        "ink" : "This ink is strange.  It's color is gold.",
        "blotter" : "A stiff paper-like sheet used to soak up extra ink.",
        "quill" : "A writing utensil used make marks on paper."]) );
}
void reset(){
    ::reset();
    if(present("wish")) return;
    new(MOB"wisp")->move(this_object());
}
