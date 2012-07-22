#include <std.h>
inherit OBJECT;

static int feathers = 0;

void create() {
 ::create();
   set_name("pillow");
   set_short("a fluffy pillow");
   set_long("The pillow is large and is full of feathers. Great for a pillow "
     "fight or to rest your weary buns...And maybe save some pains from the
hurt ones.");
   set_weight(1);
   set_id(({ "fluffy pillow", "pillow" }));
   set_value(0);
   feathers = 3;
}

void init() {
 ::init();
   add_action("relief", "sit");
   add_action("smackings", "hit");
}

int relief(string str) {
   object ob;
   if (!str) return notify_fail("Sits where and why?\n");
   write("You sit down and sigh with relief!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " sits down and almost cries in relief!",
     ({ this_player(), ob }));
   tell_room(environment(this_player()), "P I L L O W spells relief!", ({
}));
   feathers--;
if (feathers < 1) {
     write("The pillow is flat!");
     this_object()->remove();

     return 1;
   }
   return 1;
}

int smackings(string str) {
   string who;
   object ob;
   if (!str) return notify_fail("Hit who with what?\n");
   if (!sscanf(str, "%s with pillow", who))
     return notify_fail("Hit who with what?\n");
   if (!(ob = present(who, environment(this_player()))))
return notify_fail("They are not here.\n");
   write("You swing around and hit "+ob->query_cap_name()+" with the pillow!");
   tell_object(ob, this_player()->query_cap_name()+" hits you with a pillow!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " swings around and hits "+ob->query_cap_name()+" with a pillow!",
     ({ this_player(), ob }));
   tell_room(environment(this_player()), "Feathers go flying everywhere!", ({
}));
   feathers--;

 if (feathers < 1) {
     write("The pillow is out of feathers!");
     this_object()->remove();

     return 1;
   }
   return 1;
}
