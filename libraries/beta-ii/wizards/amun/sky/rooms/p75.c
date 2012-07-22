#include <std.h>
#include <amun.h>
inherit AMUNLIGHTNINGROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes through the clouds, causing them break. A large tree stands just off the path, somehow magically growing taller by the minute. As the wind picks up, the big %^WHITE%^fluffy clouds %^BLACK%^begin to shift, causing the path to be covered. A horse trots along the side of the path.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^BLACK%^Black clouds encompass the area, l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes from within them.%^RESET%^", "horse" : "%^BOLD%^%^RED%^The %^WHITE%^beautiful %^MAGENTA%^horse %^GREEN%^of %^BLACK%^many %^YELLOW%^colors %^BLUE%^trots %^RESET%^%^MAGENTA%^along %^GREEN%^the %^RED%^side %^BLUE%^of %^ORANGE%^the %^BOLD%^%^CYAN%^path.%^RESET%^", "lightning" : "%^BOLD%^%^BLACK%^The l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g flashes brightly in the clouds all around.%^RESET%^", "tree" : "%^RESET%^ORANGE%^A large tree magically stands just off the path.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "west" : SKYROOM "p74", "east" : SKYROOM "p76" ]) );
}
void reset() {
    ::reset();
    if (!present("tiger", this_object()))
	new(SKYMOB "tiger")->move(this_object());
    if (!present("boar", this_object()))
	new(SKYMOB "boar")->move(this_object());
    if (!present("dog", this_object()))
	new(SKYMOB "dog")->move(this_object());
    if (!present("wasp", this_object()))
	new(SKYMOB "wasp")->move(this_object());
}