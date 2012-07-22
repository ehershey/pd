// by Halo for Illuminati
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
::create();
    set_short("Sanctum");
    set_long("This is the Inner Sanctum of the Tower of Light. Only the "
"Solar may enter here, it is from here that one can feel the "
"touch of the Creator. It is a sacred place where the divine "
"brushes against this world of sin, Halo comes here to seek "
"guidance and enlightenment. There is a small %^BOLD%^%^YELLOW%^altar%^RESET%^ in the "
"centre of the room. There is a small section of carpet but, beyond that, the "
"room stretches endlessly.");
    set_items(([
        "Altar" : "It seems to hum and sing in tune with the universe....",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 2,
    ]));
    set_exits(([
        "out" : ROOMS"illuminati/new/halo2.c",
    ]));
}
