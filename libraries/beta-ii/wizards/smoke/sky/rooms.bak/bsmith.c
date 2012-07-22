#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("Grogg Stonebeard's Blacksmith Shop");
   set_long("%^BOLD%^%^CYAN%^Grogg Stonebeard's Blacksmith Shop%^RESET%^\n"
            "The blacksmith's shop is always in a clutter. The heat "
            "is stifling, which is coming from a stone fireplace "
            "towards the back of the shop. A long counter divides "
            "the shop. On the counter is a sign describing the "
	    "services offered by the blacksmith. An open doorway "
	    "leads back out to Gem Street.");
   set_items(([
            "sign" : "%^BOLD%^%^CYAN%^Purchasing a weapon-\n"
                  "%^RED%^You may only buy one weapon, so choose "
                  "wisely.\n\n%^BOLD%^%^CYAN%^Infusing runes-\n"
		  "%^RED%^You may have runes infused into your "
		  "weapon for 50,000 gold coins. Once a rune has "
		  "been infused it is impossible to remove it.\n\n"
		  "%^BOLD%^%^CYAN%^Upgrading your weapon-\n"
		  "%^RED%^You may upgrade your weapon, making it "
		  "sharper, special more frequently and open up "
		  "available rune slots.%^RESET%^\n\n"
		  "                   %^BOLD%^%^BLACK%^-Grogg Stonebeard",
            "counter" : "A long counter divides the shop. It's carved "
		 "of stone and looks worn from use.",
	    "fireplace" : "A stone fireplace is in the back of "
		 "the shop. A %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^ "
		 "crackles in the fireplace and is so hot it has a hint of %^BOLD%^%^CYAN%^"
		 "blue%^RESET%^ to it's flame.",
            "doorway" : "An open doorway leads back out to Gem Street."
   ]));
   set_listen("default", "A very loud, repetitive clanging comes from the back of the shop.");
   set_exits( ([ 
	"out" : ROOMS "s_gem1"]));
}
void reset() {
::reset();
    if(!present("blacksmith")) new(MOB"smith.c")->move(this_object());
}
