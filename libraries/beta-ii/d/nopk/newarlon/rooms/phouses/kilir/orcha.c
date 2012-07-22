#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Orcha's room.");
    set_long("%^ORANGE%^As you go further down into the house, it becomes extremely %^RED%^h%^BOLD%^o%^RESET%^RED%^t%^ORANGE%^, and the air starts to feel very %^WHITE%^BOLD%^c%^RESET%^ha%^WHITE%^r%^CYAN%^BOLD%^g%^WHITE%^ed%^RESET%^ORANGE%^, causing your hair to stand on end. Looking around, this massive area seems to be more like a cave than a room. An endless %^BLACK%^BOLD%^pit%^RESET%^ORANGE%^ of %^RED%^m%^ORANGE%^o%^YELLOW%^l%^RESET%^ORANGE%^t%^RED%^BOLD%^e%^RESET%^RED%^n %^ORANGE%^l%^YELLOW%^a%^%^RESET%^ORANGE%^v%^RED%^a%^ORANGE%^ is all that greets you across this massive expanse of %^RED%^b%^BLACK%^BOLD%^u%^RESET%^RED%^r%^BOLD%^BLACK%^n%^RESET%^RED%^t %^BOLD%^BLACK%^rock%^RESET%^ORANGE%^. An "
    "enormous pile of %^YELLOW%^j%^BOLD%^WHITE%^e%^CYAN%^w%^YELLOW%^e%^WHITE%^l%^MAGENTA%^s%^RESET%^ORANGE%^ and %^YELLOW%^gold%^RESET%^ORANGE%^ to the left is the only thing that could be considered a bed. To the side of the cave are piles of %^RESET%^bones%^ORANGE%^ you can only assume are the remains of unwelcome %^GREEN%^elves%^ORANGE%^ and %^RED%^BOLD%^ogres%^RESET%^ORANGE%^. The %^RED%^m%^ORANGE%^a%^BOLD%^RED%^g%^YELLOW%^m%^RESET%^RED%^a%^ORANGE%^ seems to be magically funneled into four different sections through the roof to the other rooms of the house.");
    set_exits( 
      (["out" : ROOMS + "phouses/kilir/2.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("indoors", 1);
    set_property("house", 1);
    set_listen("default", "The sound of bubbling molten lava echoes throughout the cavern.");
    set_smell("default", "The smell of decay mixed with sulphur and brimstone assaults your senses.");
}
