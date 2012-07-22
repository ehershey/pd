
#include <std.h>

inherit MONSTER;

object cust;
object cl;

string *types=({"ring","bracelet","gloves","bracers",
  "boots","leggings","tunic","cloak","cape","robe","body armour",
  "armour","shield","helmet","necklace","wing armour","tail armour",
  "horse shoes","blanket","saddle"});

void create() {
  ::create();
  set_name("tailor");
  set_id( ({ "tailor" }) );
  set_short("A tailor");
  set_long("A tailor girl who makes clothing. You can <buy clothes> or ask her to <explain>.");
  set_body_type("human");
  set_race("human");
  set_gender("female");
  set_level(15);
  set_alignment(250);
  set("aggressive",0);
  cust=0;
}

void heart_beat() {
  ::heart_beat();
  if (cust != 0 && !present(cust, environment())) {
    cust=0;
    if (cl) cl->remove();
  }
}

void init() {
  ::init();
  add_action("do_buy", "buy");
  add_action("do_explain", "explain");
}

int do_buy(string str) {
  if (cust != 0) {
    force_me("tell "+this_player()->query_name()+" I'll be with you in just a moment.");
    return 1;
  }
  if (!str) {
    force_me("say What would you like to buy?");
    return 1;
  }
  if (str != "clothes" && str != "clothing") {
    force_me("say I only sell clothing.");
    return 1;
  }
  if (this_player()->query_money("gold") < 200000) {
    force_me("say Sorry, but you need at least 200000 gold coins.");
    return 1;
  }
  if (this_player()->query_race() == "dragon") {
    force_me("say I cannot make clothes for you.");
    return 1;
  }
  cust=this_player();
  cl=new("/wizards/rull/cloth.c");
  cl->move(this_object());
  force_me("say What kind of clothing do you want?");
  input_to("buy2");
  return 1;
}

void buy2(string str) {
  if (!str || str == "" || member_array(str,types) == -1) {
    force_me("say I don't know how to make that.");
    cust=0;
    cl->remove();
    return;
  }
  cl->set_name(str);
  cl->set_type(str);
  force_me("say Give me a short name for this equipment.");
  input_to("buy3");
  return;

}

void buy3(string str) {
  if (!str || str == "") {
    force_me("say You must give me a description!");
    cust=0;
    cl->remove();
    return;
  }
  cl->set_short(replace_string(str, "%^BLACK%^", "%^BOLD%^%^BLACK%^"));
  force_me("say Ok, now describe your "+cl->query_name()+" in more detail.");
  input_to("buy4");
  return;
}

void buy4(string str) {
  string type=cl->query_name();
  string race=this_player()->query_race();
  if (!str || str == "") {
    force_me("say You must give me a description!");
    cust=0;
    cl->remove();
    return;
  }
  cl->set_long(replace_string(str, "%^BLACK%^", "%^BOLD%^%^BLACK%^"));
  switch (type) {
    case "ring": case "bracelet":
      cl->set_limbs( ({"left hand","right hand","first hand",
       "second hand","third hand", "fourth hand"}) );
      break;
    case "gloves":
      cl->set_fingers(this_player()->query_fingers());
      if (race == "raknid")
        cl->set_limbs( ({"first hand","second hand",
         "third hand","fourth hand"}) );
      else if (race == "bastet") cl->set_limbs( ({"left paw", "right paw"}) );
      else cl->set_limbs( ({"left hand","right hand"}) );
      break;
    case "bracers":
      if (race == "raknid")
        cl->set_limbs( ({"first arm","second arm",
         "third arm","fourth arm"}) );
      else cl->set_limbs( ({"left arm","right arm"}) );
      break;
    case "boots":
      if (race == "bastet")
        cl->set_limbs( ({ "right rear paw", "left rear paw" }) );
      else cl->set_limbs( ({ "left foot","right foot" }) );
      break;
    case "leggings":
      if (race == "centaur" || race == "raknid" || race == "weimic")
        cl->set_limbs( ({ "right foreleg","left foreleg",
         "right rear leg","left rear leg" }) );
      else cl->set_limbs( ({"left leg","right leg"}) );
      break;
    case "tunic": case "armour":
      cl->set_limbs( ({"torso"}) );
      break;
    case "cloak": case "cape":
      cl->set_limbs( ({"torso","head"}) );
      break;
    case "robe":
      cl->set_limbs( ({"torso","left arm","right arm",
       "left leg","right leg","head"}) );
      break;
    case "body armour":
      cl->set_limbs( ({"torso","left arm","right arm",
       "left leg","right leg"}) );
      break;
    case "shield":
      cl->set_limbs( ({"right arm","left arm"}) );
      if (race == "raknid")
        cl->set_limbs( ({"first arm","second arm","third arm","fourth arm"}) );
      break;
    case "helmet": case "necklace":
      cl->set_limbs( ({"head"}) );
      break;
    case "horse shoes":
      if (race == "minotaur")
        cl->set_limbs( ({"right hoof", "left hoof"}) );
      else
        cl->set_limbs( ({"right fore hoof","left fore hoof",
         "right rear hoof","left rear hoof"}) );
      break;
    case "blanket": case "saddle":
      if (race == "weimic") cl->set_limbs( ({"feline torso"}) );
      else cl->set_limbs( ({"horse torso"}) );
      break;
    case "tail armour":
      cl->set_limbs( ({"tail"}) );
      break;
    case "wing armour":
      cl->set_limbs( ({"left wing", "right wing"}) );
      break;
    case "default":
  }

  write_file("/wizards/rull/clothinglog", this_player()->query_name()+" bought "
    +cl->query_short()+", Long desc: "+cl->query_long()+"\n");

  this_player()->add_money("gold",-200000);
  force_me("say Thank you, I hope you enjoy your "+type+"!");
  force_me("give "+type+" to "+this_player()->query_name());
  cust=0;
  cl=0;
  return;
}

int do_explain(string str) {
  if (!str || member_array(str,types) == -1) {
/*
    force_me("say The things I can make are: ring, bracelet, gloves, bracers, boots, leggings, "
             "tunic, cloak, cape, robe, body armour, armour, shield, helmet, necklace, "
             "wing armour, tail armour, horse shoes, blanket, and saddle.");
*/
    force_me("say I can make the following: "+implode(types,", ")+".");
    force_me("say Ask me to <explain type> if you don't know what limbs it covers.");
    return 1;
  }
  switch (str) {
    case "gloves":
    case "bracelet":
    case "ring":
      force_me("say Rings, bracelets, and gloves go on your hands.");
      break;
    case "bracers":
      force_me("say Bracers go on your arms.");
      break;
    case "boots":
      force_me("say Boots go on your feet or paws.");
      break;
    case "leggings":
      force_me("say Leggings go on your legs.");
      break;
    case "armour":
    case "tunic":
      force_me("say Tunics and armour cover only your torso. ");
      break;
    case "cape":
    case "cloak":
      force_me("say Cloaks and capes cover your head and torso.");
      break;
    case "robe":
      force_me("say Robes cover two arms, two legs, head, and torso.");
      break;
    case "body armour":
      force_me("say Body armour covers two arms, two legs, and torso.");
      break;
    case "shield":
      force_me("say Shields go on your arms.");
      break;
    case "necklace":
    case "helmet":
      force_me("say Helmets and necklaces go on your head.");
      break;
    case "wing armour":
      force_me("say Wing armour covers your wings.");
      break;
    case "tail armour":
      force_me("say Tail armour covers your tail.");
      break;
    case "horse shoes":
      force_me("say Horse shoes go on your hooves.");
      break;
    case "saddle":
    case "blanket":
      force_me("say Blankets and saddles cover horse and feline torsos.");
      break;
    case "default":
  }      
  return 1;
}

