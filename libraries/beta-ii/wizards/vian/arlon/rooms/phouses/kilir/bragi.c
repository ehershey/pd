#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Bragi's room.");
    set_long("%^MAGENTA%^A faint sound of %^BOLD%^m%^YELLOW%^u%^RED%^s%^BLUE%^i%^MAGENTA%^c%^RESET%^MAGENTA%^ enters your ears as you walk into the room. It's difficult to tell where it's coming from, as there are many instruments laying around the room. Most of them custom made, and never before seen. Across from the instruments, an impressive array of %^RESET%^b%^BOLD%^l%^RESET%^a%^BOLD%^d%^RESET%^e%^BOLD%^s%^RESET%^MAGENTA%^ are displayed, all looking whimsical, while at the same time %^RED%^d%^BOLD%^e%^BLACK%^a%^RESET%^d%^%^RED%^l%^BOLD%^y%^RESET%^MAGENTA%^. The "
    "music gets louder the further into the room you go, until it seems to take over your body, strengthening you. The %^WHITE%^a%^YELLOW%^m%^ORANGE%^b%^CYAN%^i%^BOLD%^a%^RESET%^n%^WHITE%^ce%^MAGENTA%^ of the music is only disrupted slightly by the crackle of %^RED%^f%^ORANGE%^i%^YELLOW%^r%^RESET%^RED%^e%^MAGENTA%^ in the furthest corner, where a fireplace houses a %^CYAN%^BOLD%^b%^WHITE%^l%^YELLOW%^i%^CYAN%^n%^WHITE%^d%^CYAN%^i%^YELLOW%^n%^CYAN%^g %^WHITE%^white %^RESET%^MAGENTA%^fire.");
    set_exits( 
      (["out" : ROOMS + "phouses/kilir/2.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("house", 3);
    set_listen("default", "Powerful music fills your ears.");
    set_smell("default", "The smell of wood polish emenates from all the instruments.");
}
