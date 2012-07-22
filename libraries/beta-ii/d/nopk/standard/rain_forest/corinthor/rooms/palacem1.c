//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The Corinthian palace is absolutely spectacular! The entire place has been made of trees the have been carefully shaped entire lives to form solid walls. There is no roof, just the leaves of the trees creating a partial cover from the sun.");
     set_night_long("The Corinthian palace is absolutely spectacular! The entire place has been made of trees the have been carefully shaped entire lives to form solid walls. There is no roof, just the leaves of the trees creating a partial cover, through which the night sky can be seen.");
     set_exits(([
                "north"         : ELFROOM"palacem2.c",
                "south"         : ELFROOM"bridge1-1.c",
                "west"      	: ELFROOM"palacew1.c",
                "east"          : ELFROOM"palacee1.c"
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("knight"))
       new(ELFMOB"knight.c")->move(this_object());
     if(!present("knight 2"))
       new(ELFMOB"knight.c")->move(this_object());
}
