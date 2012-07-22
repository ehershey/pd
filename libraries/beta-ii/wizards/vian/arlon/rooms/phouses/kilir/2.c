#include <std.h>
#include <arlon2.h>
inherit VAULT;
void create() {
    ::create();
    set_short("A huge room.");
    set_long(
      "After walking down for what seems like hours, you end in a huge room. The most noticable feature in the room is the massive staircase leading down. On each side of the room is a door leading to one of the house's Masters. The massive chandelier in the center of the towering ceiling is adorned with massive jewels even a dragon would be proud to have. Across the room is a bar with every kind of drink imagineable."
    );
    set_exits( 
      (["up" : ROOMS + "phouses/kilir/1.c",
    "mathiu" : ROOMS + "phouses/kilir/mathiu.c",
    "yang" : ROOMS + "phouses/kilir/yang.c",
    "bragi" : ROOMS + "phouses/kilir/bragi.c",
    "orcha" : ROOMS + "phouses/kilir/orcha.c",
    "piehl" : ROOMS + "phouses/kilir/piehl.c",]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("house", 3);
    set_items(
      (["doors" : "The large wooden doors are big enough for a dragon to fit through!",
        "indentions" : "It seems as if something very large was walking around outside.",
        "grass" : "The grass is fresh and green, all alive except for where it has been clawed apart.",
        "tunnel" : "A dark tunnel leads to some underground area.",
        "window" : "The doors take up so much of the front wall that the window is actually on one of the doors."
      ]) );
    set_door("mathiu", ROOMS"phouses/mathiu", "mathiu", "burning key mathiu house key");
    set_open("mathiu", 0);
    set_locked("mathiu", 1);
    set_door("yang", ROOMS"phouses/yang", "yang", "burning key mathiu house key");
    set_open("yang", 0);
    set_locked("yang", 1);
    set_door("bragi", ROOMS"phouses/bragi", "bragi", "burning key mathiu house key");
    set_open("bragi", 0);
    set_locked("bragi", 1);
    set_door("orcha", ROOMS"phouses/orcha", "orcha", "burning key mathiu house key");
    set_open("orcha", 0);
    set_locked("orcha", 1);
    set_door("piehl", ROOMS"phouses/piehl", "piehl", "burning key mathiu house key");
    set_open("piehl", 0);
    set_locked("piehl", 1);
}
