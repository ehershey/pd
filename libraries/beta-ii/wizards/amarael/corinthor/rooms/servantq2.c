//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("Here at the most westerly point of the palace is where many of the servants spend their nights. Several bunks beds line the walls, each with small chest at the base for personal belongings. Compared to the rest of the palace these rooms are very bland, as the servants go for functionality rather than overt beauty. The sun shines down bright from overhead.");
     set_night_long("Here at the most westerly point of the palace is where many of the servants spend their nights. Many bunk beds line the walls, and each has a small chest at the base of it for personal belongings. This part of the palace is extrememly bland as the servants do not require beauty to get their tasks done. In the sky above the stars do shine.");
     set_exits(([
                "southeast"     : ELFROOM"palaceww1.c"
                ]));
     set_items(([
	"chest"		: "Unlocked, but empty of anything of value. The servants are not rich."
        ]));
}

void reset() {
   ::reset();
     if(!present("servant"))
       new(ELFMOB"servant.c")->move(this_object());
     if(!present("servant 2"))
       new(ELFMOB"servant.c")->move(this_object());
}
