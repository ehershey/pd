#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "indoors":1, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("The huge church is a building made of very polished stones with large stained glass windows.  Candles float throughout the air, lighting the church fully.  There are no benches, just a huge open space.  There appears to be a tall circular stone in the center of the church.  Old leather books are scattered on the floor.");
set_exits(([
"out" : ROOMS"mountaindwarf/86",
"north" : ROOMS"mountaindwarf/95",
"west" : ROOMS"mountaindwarf/101",
]));
    set_items( ([
"stones":"The stones that make up the church are white and polished.",
"windows":"The windows surrounding the church are of stained glass, creating a prism of color in the church.",
"stained glass windows":"The windows surrounding the church are of stained glass, creating a prism of color in the church.",
"candles":"The candles are floating in midair, by some sort of magic.",
"stone":"The stone in the center of the church seems to be a focal point.",
"books":"They seem to be prayerbooks, written in a language you do not understand.",
]) );
    set_smell("default",  "The church has a flowery fragrance to it.");
    set_listen("default", "The sound of arguing seems to come from the center of the church.");

        if(!present("mdcleric")){
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdcleric")->move(this_object()); }
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdcleric")->move(this_object()); }
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdcleric")->move(this_object()); }
}
        if(!present("mdpriest")){
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdpriest")->move(this_object()); }
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdpriest")->move(this_object()); }
              if( random(100) < DIRAN_MOB_CHANCE){ new(MOB "mdpriest")->move(this_object()); }
}
}