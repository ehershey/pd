#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Amun Gazebo");
    set("long", "%^BOLD%^%^WHITE%^This nook was placed here as the sleep quarters for this home's owner and pet. This room has no walls, just s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e %^RESET%^p%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^l%^RESET%^a%^BOLD%^%^WHITE%^r%^RESET%^s %^BOLD%^%^WHITE%^hold up the cathedral ceiling. A large king-size bed is placed in the middle of the room with a small bed hanging above it for Amun's pet %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^WHITE%^. The %^CYAN%^breeze %^WHITE%^in this room is very light and cool.%^RESET%^");
    set_items((["sky" : "%^BOLD%^%^WHITE%^The %^YELLOW%^moon %^WHITE%^and st%^YELLOW%^a%^WHITE%^rs are the only %^YELLOW%^light %^WHITE%^the %^BLACK%^da%^RESET%^%^BLUE%^rk%^BOLD%^%^BLACK%^ene%^RESET%^%^BLUE%^d s%^BOLD%^%^BLACK%^ky %^BOLD%^%^WHITE%^sees.  Even when it is %^YELLOW%^day%^WHITE%^li%^YELLOW%^ght %^WHITE%^in the mortal realm, it is always %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^here; as the owner�s of this house love the %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^life.%^RESET%^", "candles" : "%^BOLD%^%^WHITE%^White and lit, the candles are floating by magic every 10 steps you take.  No wax is falling, showing you these candles are everlasting.%^RESET%^", "bed" : "This bed is large and gorgeous and VERY comfortable." ]));
    set_exits( ([ "east" : "/wizards/amun/bedroom" ]) );
}
void reset() {
    ::reset();
    if (!present("phoenix", this_object()))
	new("/wizards/amun/phoenix_mob")->move(this_object());
}
