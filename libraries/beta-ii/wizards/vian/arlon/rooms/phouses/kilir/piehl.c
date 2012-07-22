#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Piehl's room.");
    set_long("%^BLACK%^BOLD%^The light becomes very %^RESET%^d%^BLACK%^BOLD%^i%^RESET%^m%^BLACK%^BOLD%^ as you enter this room. As you step further in, a few shadows seem to dart to separate sides of the room. Squinting your eyes, you can make out a wide array of daggers, most of them covered in %^RED%^b%^RESET%^RED%^l%^BOLD%^o%^RESET%^RED%^o%^BOLD%^d%^RESET%^BLACK%^BOLD%^, on "
    "the closest side of the room. There seems to be the crackle of %^RED%^f%^RESET%^ORANGE%^i%^RED%^BOLD%^r%^%^RESET%^RED%^e%^BLACK%^BOLD%^ on the far side of the room, but nothing can be easily seen. If you strain your eyes enough, you can make out what seems to be dancing black fire in the fireplace, almost as if it's sucking the light out of the room.");
    set_exits( 
      (["out" : ROOMS + "phouses/kilir/2.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("house", 3);
    set_listen("default", "A faint crackle of fire interrupts the otherwise dead silence.");
    set_smell("default", "The smell of blood permeates the air.");
}
