#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_name("Abzigals Lair");
set_short("abzigals Lair");
set_long("                 %^BOLD%^%^WHITE%^-= Abzigal's lair =-\n%^BLUE%^You walk into Abzigal's "
"massive lair, how on in this world it fits here is unknown. The immense ceiling "
"is riddled with %^BOLD%^%^WHITE%^crystals%^BLUE%^ and sharp rocks protruding out of it. The thing that "
"catches your eye is the crystal clear lagoon in the middle of the lair. "
"Although it's crystal clear you cannot see the bottom, the depth of this liquid "
"chasm is frighting. The room is full of large %^BOLD%^%^WHITE%^white%^BLUE%^ rocks that glow with a warm "
"feeling of peace. This has got to be one of the most impressively large rooms "
"you have even had the privelage to be in."); 
set_items(([
"lagoon"        : "%^BOLD%^%^CYAN%^The water is crystal clear and is filled with tropical fish "
"%^BOLD%^%^CYAN%^and marine life, it is truely awesome to behold. you feel like you would really "
"%^BOLD%^%^CYAN%^enjoy a %^WHITE%^swim%^CYAN%^ in the crystal clear lagoon.",
"rocks"         : "The white rocks are swirling with a warm light. You feel at "
"peace here.",
"crystals"      : "%^BOLD%^%^WHITE%^The crystals are glistening, Sending %^BOLD%^%^MAGENTA%^r%^BLUE%^a%^GREEN%^i%^YELLOW%^n%^RESET%^%^ORANGE%^b%^BOLD%^%^RED%^o%^BLACK%^w%^WHITE%^ coloured light "
"all through the lair."
]));
set_properties(([
"no attack"     : 1,
"no steal"      : 1,
"no scry"       : 1,
"light"         : 2,
"indoors"       : 1,
]));
set_exits(([
"north" : ROOMS"illuminati/new/floor5.c"
]));
}

void init() {
   ::init();
     add_action("chesteramon", "open");
}

int chesteramon(string str) {
    object tp;
    tp = this_player();
    if (tp->query_name() != "abzigal") {
    write("As you are about to lift the giant lid of the chest, you hear a "
"booming voice echo though the lair %^BOLD%^%^BLUE%^'You dare to touch my chest?'%^RESET%^. You back away "
"wondering why you would want to go though Abzigal's chest anyway. You shake "
"your head and leave the chest.");
    message("info", ""+tp->query_cap_name()+" goes to open the chest, then "
"backs away shaking "+tp->query_possessive()+" head.", environment(tp), tp);
    return 1;
    }
    if (str == "chest") {
    write("You open the chest and marvel at your awesome collection of %^BOLD%^%^RED%^j%^BLUE%^e%^RED%^w%^BLUE%^e%^RED%^l%^BLUE%^s%^RESET%^ "
"and %^RESET%^%^ORANGE%^tre%^BOLD%^%^YELLOW%^asu%^RESET%^%^ORANGE%^res%^RESET%^ from across the lands.");
    message("info", "Abzigal opens his chest and looks inside, his eyes sparkle "
"as he marvels at his %^RESET%^%^ORANGE%^treasures. You notice a plaque above the chest saying - "
"%^BOLD%^%^WHITE%^Aziraphale%^RESET%^.", environment(tp), tp);
    return 1;
    }
    return 0;
}

void reset() {
   ::reset();
   if (!present("chest2"))
      new(ROOMS"illuminati/new/chest2")->move(this_object());
}
