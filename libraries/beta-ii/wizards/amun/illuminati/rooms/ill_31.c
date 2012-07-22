#include <std.h>
#include <guild.h>
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
    set("short", "ILLUMINATI");
    set("long", "%^BOLD%^%^WHITE%^As you come into the room, you notice a basin lain in front of you, stairs all around you, %^BLACK%^c%^YELLOW%^a%^BLACK%^ndl%^YELLOW%^e%^BLACK%^s %^BOLD%^%^WHITE%^floating and a waterfall trickling down behind the basin.  Gazing through this waterfall, you see a %^RESET%^%^ORANGE%^w%^RED%^o%^RESET%^%^ORANGE%^oded b%^RED%^r%^RESET%^%^ORANGE%^idge %^BOLD%^%^WHITE%^curved over a river to the other side of %^GREEN%^l%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^nd%^WHITE%^.  You walk through the %^BLUE%^wat%^CYAN%^erf%^BLUE%^all %^WHITE%^and notice that even though water is running over you, you are not dampened.  Stopping in awe, your eyes fall upon a house laid within a tree.  Feeling that your eyes are cheated by some spell, you begin to climb marble stairs that glow white.  Climbing further and further, you notice the marble columns and the tree branches coming together to make this house beautiful.  You see a gazebo and a nook at your sides.%^RESET%^");
    set_items((["candles" : "%^BOLD%^%^WHITE%^White and lit, the candles are floating by magic every 10 steps you take.  No wax is falling, showing you these candles are everlasting.%^RESET%^", "waterfall" : "%^BOLD%^%^CYAN%^The waterfall is flowing from the top of a cliff just above the cove you are walking through.  The only way to get to the bridge is through this falling of water.%^RESET%^", "gazebo" : "%^BOLD%^%^WHITE%^This Gazebo, which has two separate bridges attached to it, is suspended in the air and has flowing lace coverings and pillows laid in the middle.  Candles are placed on each pillar and the top is domed to a large opening allowing the sky to peek through.%^RESET%^", "nook" : "%^BOLD%^%^WHITE%^This nook is a housing area for the animals of this homes owner^Rs: Furiae and Carina.  There is a small tree with a perch for the Phoenix, Fawkes; and a small grassy looking area for the tiger, Otis.  These two animals sleep peacefully with one another every night.%^RESET%^", "sky" : "%^BOLD%^%^WHITE%^The %^YELLOW%^moon %^WHITE%^and st%^YELLOW%^a%^WHITE%^rs are the only %^YELLOW%^light %^WHITE%^the %^BLACK%^da%^RESET%^%^BLUE%^rk%^BOLD%^%^BLACK%^ene%^RESET%^%^BLUE%^d s%^BOLD%^%^BLACK%^ky %^BOLD%^%^WHITE%^sees.  Even when it is %^YELLOW%^day%^WHITE%^li%^YELLOW%^ght %^WHITE%^in the mortal realm, it is always %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^here; as the owner^Rs of this house love the %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^life.%^RESET%^" ]));
    set_exits( ([  "east" : ILLROOM "ill_32", "west" : ILLROOM "ill_35", "north" : ILLROOM "ill_30" ]) );
}
void reset() {
    ::reset();
    if(!present("basin"))
	new(ILLOBJ "basin.c")->move(this_object());
}
void init() {
    ::init();
    add_action("view", "find");
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
