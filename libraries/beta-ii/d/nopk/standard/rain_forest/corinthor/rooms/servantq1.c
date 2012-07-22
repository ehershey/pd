//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("Here at the most westerly point of the palace is where many of the servants spend their nights. Several bunks beds line the walls, each with small chest at the base for personal belongings. Compared to the rest of the palace these rooms are very bland, as the servants go for functionality rather than overt beauty. The sun shines down bright from overhead.");
     set_night_long("Here at the most westerly point of the palace is where many of the servants spend their nights. Several bunks beds line the walls, each with small chest at the base for personal belongings. Compared to the rest of the palace these rooms are very bland, as the servants go for functionality rather than overt beauty. The nighttime stars shine in the sky.");
     set_exits(([
                "southeast"     : ELFROOM"palaceww2.c"
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
