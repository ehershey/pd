#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A staircase leading deeper into the nest, is situated "
      "at the end of this tunnel.  The steps are very uneven, "
      "and there is no hand-rail."
         
    );
    set_items(([
        "staircase" : "It is located at the end of the tunnel.",
        "nest" : "It is built by the Raknids.",
        "end" : "The tunnel digging went down another level.",
        "tunnel" : "Made of sand and sticky stubstance.",
        "steps" : "Very uneven, like it was made in haste.",
        "sticky substance" : "Regurgitated sand.",
        "substance" : "Regurgitated sand.",
        "sand" : "Normally not used for construction, but "
                 "regurgitated sand is better than dried mud.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : NEST "est78",
"down" : HIVE "hve37",
    ])  );
}
void init()
{
 ::init();
 add_action("Fdown", "down");
}
int Fdown()
{
 write("%^BOLD%^YELLOW%^You lose your footing, and tumble down the stairs%^RESET%^");
this_player()->add_hp(-25);
 return 0;
}
void reset() {
 ::reset();
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
