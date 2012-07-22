#include <std.h>
#include <helgrath.h>
inherit MONSTER;

create() {
  ::create();
  set_name("mage");
  set_id( ({"mage","welcome mage"}) );
  set_short("Welcoming Mage");
  set_level(30);
  set_long("This mage sits by the door and greets visitors to the mage tower."
    "  He makes sure people hear the news and get to the right place.");
  set_gender("male");
  set("race", "elf");
  set_alignment(300);
  set_body_type("human");
   if(random(200) > 175) {
    new(WEP"fire_whip.c")->move(this_object());
    force_me("wield whip");
   }
}

void init() {
  ::init();
  remove_call_out("do_say");
  call_out("do_say", 2);
}

void do_say() { this_object()->force_me("say Are you here to help us with the golem?  Please say yes!"); }

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%syes%s", a, b) == 2) {
        this_object()->force_me("say Excellent!  We created an extremely powerful ice golem.  Too powerful.  It has wreaked havoc in town, and we're afraid it will return.");
        return;
    }
    if(sscanf(str, "%sgolem%s", a, b) == 2) {
        this_object()->force_me("say If you destroy the golem and bring back proof, we will reward you greatly.");
        return;
    }
    if(sscanf(str, "%sgives you%s", a, b) == 2) {
        if(present("golem tooth", this_object())) {
          this_object()->force_me("say Excellent!  We are eternally greatful.  Please accept this humble reward.");
          ob->add_money("gold", 1000);
          ob->force_me("give 1000 gold coins to "+this_player()->query_name());
          if(this_player()->set_mini_quest("icegolem", 10000, "You saved helgrath from the ice golem.\n"))
            message("info", "You feel more experienced from the deed.", this_player());
          present("golem tooth", this_object())->remove();
        }
        else
          ob->force_me("say Thank you, but I have no use for that.");
        return;
    }
}
