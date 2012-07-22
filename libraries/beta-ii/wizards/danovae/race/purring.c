#include <std.h>

inherit OBJECT;

static void create() {
   set_name("purr_object");
   set_id( ({ "the-bastet-purring-object-thingy-010203" }) );
   set_long("");
   set_property("no steal", 1);
   set_property("no sell", 1);
   set_property("no drop", 1);
   set_mass(0);
   set_value(0);
}
void init() {
   ::init();
   call_out("do_heal", 5, this_player());
     if(present("the-bastet-purring-object-thingy-010203", environment(this_player()))) {
     this_object()->remove();
     return 0;
     }
   message("info", "You begin to purr calmly.", this_player());
   message("info", (string)this_player()->query_cap_name()+" begins to purr.", environment(this_player()), this_player());

   add_action("check_act", "", 1);

   if(!this_player()->is_monster()) call_out("do_heal", 5, this_player());
}

int check_act(string str) {
   if(present("the-bastet-purring-object-thingy-010203", environment(this_player()))) {
     this_object()->remove();
     return 0;
     }
   if(query_verb() == "cease") {
     message("info", "You stop purring.", this_player());
     message("info", (string)this_player()->query_cap_name()+ " stops purring.", environment(this_player()), this_player());
     this_object()->remove();
     return 1;
     }
   if(query_verb() == "hp" || query_verb() == "status") return 0;
   message("info", "You are too content to do that.", this_player());
   return 1;
}

void do_heal(object ob) {
   if(ob->query_hp() < 1) this_object()->remove();
   if(!ob->is_monster()) return;
   ob->heal(random(13));
   call_out("do_heal", 5, this_player());
}





