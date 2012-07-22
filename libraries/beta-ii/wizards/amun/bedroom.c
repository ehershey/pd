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
    set("short", "Amun Bedroom");
    set("long", "%^BOLD%^%^WHITE%^As you come into the room, you notice a basin lain in front of you, stairs all around you, %^BLACK%^c%^YELLOW%^a%^BLACK%^ndl%^YELLOW%^e%^BLACK%^s %^BOLD%^%^WHITE%^floating and a waterfall trickling down behind the basin.  Gazing through this waterfall, you see a %^RESET%^%^ORANGE%^w%^RED%^o%^RESET%^%^ORANGE%^oded b%^RED%^r%^RESET%^%^ORANGE%^idge %^BOLD%^%^WHITE%^curved over a river to the other side of %^GREEN%^l%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^nd%^WHITE%^.  You walk through the %^BLUE%^wat%^CYAN%^erf%^BLUE%^all %^WHITE%^and notice that even though water is running over you, yet you are not dampened.  Stopping in awe, your eyes fall upon a house laid within a tree.  Feeling that your eyes are cheated by some spell, you begin to climb marble stairs that glow white.  Climbing further and further, you notice the marble columns and the tree branches coming together to make this house beautiful.  A gazebo and a nook can be seen to the east and west of here.%^RESET%^");
    set_items((["candles" : "%^BOLD%^%^WHITE%^White and lit, the candles are floating by magic every 10 steps you take.  No wax is falling, showing you these candles are everlasting.%^RESET%^", "waterfall" : "%^BOLD%^%^CYAN%^The waterfall is flowing from the top of a cliff just above the cove you are walking through.  The only way to get to the bridge is through this falling of water.%^RESET%^", "gazebo" : "%^BOLD%^%^WHITE%^This Gazebo, which has two separate bridges attached to it, is suspended in the air and has flowing lace coverings and pillows laid in the middle.  Candles are placed on each pillar and the top is domed to a large opening allowing the sky to peek through.%^RESET%^", "sky" : "%^BOLD%^%^WHITE%^The %^YELLOW%^moon %^WHITE%^and st%^YELLOW%^a%^WHITE%^rs are the only %^YELLOW%^light %^WHITE%^the %^BLACK%^da%^RESET%^%^BLUE%^rk%^BOLD%^%^BLACK%^ene%^RESET%^%^BLUE%^d s%^BOLD%^%^BLACK%^ky %^BOLD%^%^WHITE%^sees.  Even when it is %^YELLOW%^day%^WHITE%^li%^YELLOW%^ght %^WHITE%^in the mortal realm, it is always %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^here; as the owner�s of this house love the %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^life.%^RESET%^" ]));
    set_exits( ([ "south" : "/wizards/amun/workroom", "east" : "/wizards/amun/gazebo", "west" : "/wizards/amun/nook" ]) );
}
void reset() {
    ::reset();
    if(!present("basin"))
	new("/wizards/amun/basin.c")->move(this_object());
}
void init() {
    ::init();
    add_action("view", "find");
    add_action("move_basin", "move");
}
int view(string str) {
    mixed strr;
    object env;
    if(!str || str == "")
	return notify_fail("Find who?");
    strr = find_player(str);
    env = environment(strr);
    if(!find_player(str))
	return notify_fail("Cannot find "+capitalize(str)+".\n");
    if(env->query_property("no scry") || wizardp(strr))
	return notify_fail("The basin reveals nothing.\n");
    write("\nThe basin reveals "+capitalize(str)+" is in "+env->query_short()+".\n");
    return 1;
}
int move_basin(string str) {
    if (!str || str != "basin") return notify_fail("move what?\n");
    write("%^BOLD%^%^RED%^You move the basin out of the way and are thrown into a room of revolving doors.%^RESET%^");
    this_player()->move_player("/wizards/amun/spare_room.c");
    return 1;
}
