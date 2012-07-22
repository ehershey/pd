#include <std.h>
#include <lidelas.h>

inherit ROOM;

int cmd_start(string str);

void create()
{
    ::create();
        set_name("general store");
        set_short("General Store");
        set_long("This is the general store of Lidelas. This is the only store in the entire town, however, Eanfrid keeps his prices fair. The store is very large, it looks like Sabert likes to display his merchandise on all of the walls. Many different weapons and armors have been fastened to the walls, some of the weapons look rather old and dull. A large counter rests at the back end of the store, and behind it stand Sabert, ready to aid you. On the back wall, behind the counter, is a large fireplace. The fireplace contains a roaring fire, it heats the entire building. Large furs have been laid down on the floor, the furs look to come from many exotic beasts.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "indoors"     : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1 ]) );
        set_items(([
        "weapons"   : "Many different types of weapons, some look more dangerous then others.",
        "armors"    : "A large assortment of armours, most look to be rather plain.",
        "furs"      : "An odd collection of furs, they seem to be from beasts across the world.",
        "counter"   : "A large wooden counter, with gargoyles carved into the sides."
            ]));
            set_listen("default", "People discussing prices echo off the walls");
            set_smell("default", "The smell of burning wood fills the air.");
            set_exits(([
			"west"		: ROOMS "lidelas003.c",
        ]));
}

void reset() {
   ::reset();
if (!present("sabert", this_object()))
     new(MOB"sabert.c")->move(this_object());
}

