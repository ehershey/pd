#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  int hp;
  ::create();
  set_name("water nymph");
  set_id(({ "nymph", "water nymph", "wnymph" }));
  set_short("A water nymph");
  set_long("A very lovely water nymph. This nymph looks like a stunningly beautiful human girl. Her skin is mostly white with a slight blue tinge, and she has long, thick blue hair that goes down to her waist.");
  set_gender("female");
  set_race("water nymph");
  set_body_type("nymph");

  new(ARM"wcrown.c")->move(this_object());
  this_object()->force_me("wear crown");

  set_class("clergy");
  set_subclass("druid");
  set_level(39);
  hp = query_max_hp();
  set_skill("nature", 175);
  set_skill("magic defense", 140);
  set_skill("magic attack", 165);
  set_skill("melee", 20);
  set_skill("attack", 10);
  set_stats("strength", 17);
  set_stats("intelligence", 48);
  set_stats("wisdom", 48);
  set_stats("constitution", 42);
  set_stats("dexterity", 30);
  set_stats("charisma", 50);
  set_max_hp(hp);
  set_hp(hp);
  set_spells( ({ "freeze", "whirlwind", "vinearmour", "thorns" }) );
  set_spell_chance(200);
}

void catch_tell(string str) {
  object ob;
  string a, b;

  if(this_player() == (ob = this_object())) return;
  if(sscanf(str, "%srides in on a mount%s", a, b) == 2) {
    call_out("check_quest", 2);
    return;
  }
  if(sscanf(str, "%squest%s", a, b) == 2) {
    ob->force_me("say Mmmm.... Yes, I suppose I do suppose I have a quest for you. Please find my companion and bring her back here to me.");
    return;
  }
  if(sscanf(str, "%scompanion%s", a, b) == 2) {
    ob->force_me("say You want to know what my companion looks like?");
    ob->force_me("wink");
    ob->force_me("say Oh, i'm sure you'll know her when you see her.");
    return;
  }
}

void check_quest() {
  object reward;
  object horse = present("questbluehorse", environment(this_object()));
  if(!horse) return;

  if(this_player()->set_mini_quest("water horse", 100, "You reunited the water nymph with her companion.\n")) {
    this_player()->add_exp(500);
    reward = new(ARM "ibrac");
    reward->move(this_object());
    this_object()->force_me("give bracelet to "+this_player()->query_name());
    this_object()->force_me("say Thank you, this is for you... take it as my thanks.");
  }
  else {
    this_object()->force_me("eye "+this_player()->query_name()+" strangely");
    this_object()->force_me("say hey, thanks...");
  }
  horse->force_me("buck "+this_player()->query_name());
  this_object()->force_me("ride questbluehorse");
  message("info", "The nymph and her companion suddenly turn into a giant puddle of water, splash against the ground and flow through the cracks in the room.", environment(this_player()), this_object());
  horse->remove_living();
 this_object()->remove_living();
}
