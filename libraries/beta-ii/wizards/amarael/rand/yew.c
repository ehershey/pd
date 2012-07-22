
#include <std.h>
inherit OBJECT;
void create() {
   ::create();
     set_id(({"bag"}));
     set_name("bag of tricks");
     set_long("Amarael's bag of tricks. Quite useful.");
     set_short("a Bag of Tricks");
     set_weight(0);
     set_value(0);
}

void init() {
   ::init();
     add_action("my_func", "filename");
     add_action("my_func", "find");
     add_action("my_func", "source");
     add_action("my_func", "mudtell");
     add_action("my_func", "deathtell");
     add_action("my_func", "lockme");
}

int query_auto_load() {
    if(this_player()->query_name() == "amarael") return 1;
}

int my_func(string str) {
    string func;
    func = query_verb();
    return call_other("/wizards/amarael/rand/tricks/"+func+".c", "trick", str);
}
