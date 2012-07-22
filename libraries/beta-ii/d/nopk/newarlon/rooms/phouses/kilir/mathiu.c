#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Mathiu's room.");
    set_long("%^CYAN%^As you enter a very large room, two enormous eyes, each with a %^BLACK%^BOLD%^ra%^RED%^g%^BLUE%^in%^BLACK%^g %^BLUE%^blue %^WHITE%^storm%^RESET%^CYAN%^ inside of them peer down at you, watching your every move from the ceiling. The room becomes to feel unbearably heavy. The wall to your side is lined with an assortment of staves, each looking more %^RED%^BOLD%^d%^BLACK%^e%^RED%^a%^BLACK%^d%^RED%^l%^BLACK%^y%^RESET%^CYAN%^ and %^BOLD%^RED%^d%^BLUE%^e%^RED%^s%^BLUE%^t%^RED%^r%^BLUE%^u%^RED%^c%^BLUE%^t%^RED%^i%^BLUE%^v%^RED%^e%^RESET%^CYAN%^ than the one next to it. On the other "
    "side, a rather large bookshelf houses what seems like hundreds of %^WHITE%^BOLD%^spellbooks%^RESET%^CYAN%^ and %^BLACK%^BOLD%^tomes%^RESET%^CYAN%^. A huge round table sits in the very center of the room, covered in many different colored %^GREEN%^BOLD%^p%^WHITE%^o%^GREEN%^t%^WHITE%^i%^GREEN%^o%^WHITE%^n%^GREEN%^s%^RESET%^CYAN%^, a few broken staves, and quite a few %^RED%^b%^BOLD%^u%^ORANGE%^r%^RESET%^RED%^n%^CYAN%^ marks. A large bed fills one corner of the room, covered in open books and orbs. There is a fireplace taking up an opposite corner of the room, %^RED%^a%^BOLD%^b%^ORANGE%^l%^YELLOW%^a%^RESET%^%^ORANGE%^z%^RED%^e%^CYAN%^ with a magnificient %^BLUE%^BOLD%^b%^RESET%^BLUE%^l%^BOLD%^u%^RESET%^BLUE%^e%^CYAN%^ fire.%^RESET%^");
    set_exits( 
      (["out" : ROOMS + "phouses/kilir/2.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("indoors", 1);
    set_property("house", 1);
    set_listen("default", "The sound of a roaring fire fills the room.");
    set_smell("default", "The smell of potions and burnt wood emanates from the room.");

}
