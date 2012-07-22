#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Yang's room.");
    set_long("%^GREEN%^You step in through a large doorway. Hundreds of %^RESET%^w%^BOLD%^ea%^RESET%^p%^BOLD%^o%^RESET%^n%^BOLD%^s%^RESET%^GREEN%^ line every wall. %^RESET%^S%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d%^BOLD%^s%^RESET%^GREEN%^, %^RED%^BOLD%^h%^RESET%^RED%^a%^BOLD%^m%^RESET%^RED%^m%^BOLD%^e%^RESET%^RED%^r%^BOLD%^s%^RESET%^GREEN%^, and weapons few people have ever seen. The sheer magnitude of weapons here could equip an entire army. There doesn't seem to be any kind of bed, other than a %^BLUE%^c%^BOLD%^o%^RESET%^BLUE%^m%^BLUE%^BOLD%^p%^RESET%^BLUE%^l%^BLUE%^BOLD%^ex%^RESET%^GREEN%^ array "
    "of what seems like %^WHITE%^BOLD%^sharp %^RESET%^steel%^GREEN%^ webs on the ceiling. The webs spread throughout the entire room, arching from one side to another. If you didn't know your way around, one could be %^WHITE%^BOLD%^c%^RESET%^u%^BOLD%^t%^RESET%^GREEN%^ into pieces trying to navigate around the webs. The enormous fireplace in the corner of the room lights up the entire room easily, reflecting a %^RED%^deep red %^GREEN%^light off of the myriad of weapons and webs, making the room seem rather menacing.");
    set_exits( 
      (["out" : ROOMS + "phouses/kilir/2.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("indoors", 1);
    set_property("house", 1);
    set_listen("default", "You hear the sound of weapons scraping against one another.");
    set_smell("default", "The smell of metal is strong.");
}
