#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Rain patters on soft, calm ground",
     "Flower, plant, leaf of tree",
     "Growing here on hallowed mound;",
     "Nature, set my spirit free"
   }));
   set_type("good");
   // Changed because 'to' was causing errors in _sing.c
   //set_song_name("ode to nature");
   set_song_name("ode towards nature");
}

int check_sing(object o) {
   if (o->query_class() == "wanderer" && o->query_subclass() == "bard"
	&& o->query_skill("euphony") >= 40) return 1;
}

void finish_song() {
   object ob, tp;
   int i;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
     message("info", "Nothing happens.", tp);
     return;
   }
   i = tp->query_skill("euphony");
   message("info", ob->query_cap_name()+"'s skin hardens.",
	environment(ob));
   if (this_player()->query_magic_protection() < tp->query_level()/5)
     this_player()->add_magic_protection(({0,
	random(4)+(tp->query_level()/10), i}));
}
