#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":2, "beach":1]));
     set_name("Illuminati Entrance");
     set_short("Illuminati Entrance");
     set_day_long("%^BOLD%^WHITE%^The tower of light stands before you, it's white walls reaching all the way to the clouds. Balconies hang off each floor providing an excellent view of the ocean. A large gate bars entry to the uninitiated.%^RESET%^");
     set_night_long("%^CYAN%^The tower of light stands before you, it's white walls reaching all the way to the clouds. Balconies hang off each floor providing an excellent view of the ocean. A large gate bars entry to the uninitiated.%^RESET%^");
     set_exits(([
//		"north"         : ILROOM"beach.c",
		"south"         : ILROOM"newhall.c"
		]));
     set_items(([
		"tower"         : "It's pure white walls reach all the way to the clouds, the from the top must be amazing.",
		"balconies"     : "Two balconies lead off each floor, one to the northwest of the tower, and another to the northeast.",
		"gate"          : "The gate will only open for those initiated into the ranks of the Illuminati."
		]));
}

void init() {
   ::init();
     add_action("enterin", "south");
}

int enterin() {
    object tp;
    tp = this_player();
    if(tp->query_guild() != "illuminati" && !wizardp(tp)) {
      message("info", "A shadow says: You are not welcome here!", environment(tp), );
      message("info", "A blinding light consumes "+tp->query_cap_name()+"!",
      environment(tp), tp);
      write("A blinding light consumes you!");
      tp->add_hp(-5);
      tp->add_sp(-5);
      tp->add_mp(-5);
      write("hp: "+tp->query_hp()+"   sp: "+tp->query_sp()+"   mp: "+tp->query_mp()+"");
      return 1;
      }
    write("The gates swing open, allowing you entry to the Tower of Light.");
    message("info", "The gates swing open, allowing "+tp->query_cap_name()+" entry to the Tower of Light.", environment(tp), tp);
    tp->move_player(ILROOM"newhall.c", "into the tower");
    return 1;
}
