#include <std.h>
#include <lodos.h>
inherit MONSTER;

static int oi=0, quest_in=0;

void create() {
    object ob;
    ::create();
    set_short("Soriy, alchemist");
    set_id(({ "alchemist", "soriy" }));
    set_name("soriy");
    set_level(29);
    set_long("Soriy has trained herself her entire life in the arts of alchemy.
"
      "She trains by herself in the Lodos towers.");
   set_body_type("human");
   set_race("human");
   set_gender("female");
   ob = new(OBJECT);
   ob->set_name("book");
   ob->set_short("a book");
   ob->set_long("On the only legable page, a short list has been scrawled "
      "out: potion of change, elixer of alcanst, potion of purification. "
      );
   ob->set_weight(3);
   ob->set_id(({ "book" }));
   ob->move(this_object());
}

int buy(string what) {
   if (!what) return notify_fail("Buy what?\n");
   switch (what) {
      case "potion of change":
        if (this_player()->query_money("gold") < 200) {
           this_object()->force_me("say The cost for that is 200 gold
pieces.");
           return 1;
        }
        this_player()->add_money("gold", -220);
        new(OBJ"sex_fix")->move(this_player());
        this_object()->force_me("say Here is your potion of change");

        return 1;
      case "elixer of alcanst":
        if (this_player()->query_money("gold") < 3500) {
           this_object()->force_me("say That elixer costs 3500 gold coins.");
           return 1;
        }
        this_player()->add_money("gold", -3500);
        new(OBJ"alcohol_fix")->move(this_player());
        this_object()->force_me("say Here is your elixer.");
        return 1;
      case "potion of purification":
        if (this_player()->query_money("silver") < 2000) {
           this_object()->force_me("say That will cost you 2000 silver coins,
which you do not have..");
           return 1;
        }
        this_player()->add_money("silver", -2000);
        new(OBJ"poison_fix")->move(this_player());
        this_object()->force_me("say Here is your potion.");
        return 1;
      default: return notify_fail("Buy what?\n");
   }
}

void finish_quest(object tp) {
   if (tp->set_mini_quest("alchemist", 4000, "You helped to catch a thief at large.\n")) {
      write("You feel more experienced.");
   }
   force_me("thank "+tp->query_name());
   tell_room(environment(tp), tp->query_cap_name()+" looks more experienced.", ({ tp }));
   if(present("customer", environment(this_player()))) present("customer", environment(this_player()))->die();
}

void catch_tell(string what) {
   string junk;
   if (quest_in) return;
   if (!sscanf(lower_case(what), "%sthief%s", junk, junk)) return;
   if (!present("customer", environment(this_object())))
     force_me("say What?? Where?!");
   else {
     force_me("emote looks around.");
     quest_in = 1;
     call_out("quest_time", 1, this_player());
   }
   return;
}

void quest_time(object ob) {
   int xor = 1;
   force_me("say Stop!! Thief!");
  if (xor) {
   tell_room(environment(this_object()), "The alchemists "
      "teaches the thief the lesson of her life..");
   call_out("finish_quest", 1, ob);
   xor = 0;
  }
}

void init() {
 ::init();
   add_action("buy", "buy");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
if (environment()) {
     this_object()->force_me("emote fumbles and drops a book.");
     this_object()->force_me("drop book");
     oi = 1;
}
   }
}









