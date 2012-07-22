//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This is one of the seconday hallways leading out of the throne room, leading to and from the guest quarters on the eastern side of the palace. The area is fairly busy, with nobles hurrying back and forth on official business. The sun shines down from overhead.");
     set_night_long("This is one of the secondary hallways leading out of the throne room, leading to and from the guest quarters on the eastern side of the palace. The area is not particularly busy, with most of the visiting nobles already asleep for the night.");
     set_exits(([
                "northwest"     : ELFROOM"throne.c",
                "south"         : ELFROOM"palacee3.c" 
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
     if(!present("knight 3"))
       new(ELFMOB"knight.c")->move(this_object());
}
