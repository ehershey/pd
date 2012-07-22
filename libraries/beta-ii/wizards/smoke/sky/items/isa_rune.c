/// This is the Isa Rune--Can give weapon anywhere from 1 to 3 ICE damage specials, depending on which order rune is infused
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "isa rune"}) );
        set_short("small runestone");
     set_long("%^BOLD%^%^BLACK%^     ___\n"
"   _/   \\_\n"
"  /   %^RED%^|%^BLACK%^   \\\n"
" |    %^RED%^|%^BLACK%^    |\n"
" |    %^RED%^|%^BLACK%^    |\n"
"  \\_  %^RED%^|%^BLACK%^  _/\n"
"    \\___/\n");
        set_weight(2);
        set_value(0);
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
