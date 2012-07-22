#include <std.h>
inherit OBJECT;

int flipping;
 
void create() {
::create();
    set_property("no steal", 1);
    set_id(({"coin", "golden coin"}));
    set_name("lucky coin");
    set_short("%^YELLOW%^Golden coin%^RESET%^");
    set_long("A small circular coin made of gold. On one face is the symbol of a feather and on the other a flame. You get the urge to flip it.");
    set_mass(1);
    set_curr_value("gold", 0);
    flipping = 0;
}

void init() {
   ::init();
     add_action("flipin", "flip");
}

int flipin(string str) {
    object tp;
    tp = this_player();
    if(str != "coin") return notify_fail("Flip what?");
    if(flipping) return notify_fail("You are not holding it.\n");
");
    message("info", "\nYou flip the gold coin into the air.", tp, );
    message("info", tp->query_cap_name()+" flips a gold coin into the air.", environment(tp), tp);
     flipping = 1;
    if(this_player()->query_property("killersmark") == 1) {
      call_out("msg_evil", 3, tp);
      return 1;
      }
    call_out("msg_good", 3, tp);
    return 1;
}

void msg_evil(object tp) {
     string *limb;
     int rndm;
     limb = tp->query_wielding_limbs();
     rndm = random(sizeof(limb));
     message("info", "The coin tumbles over and over, landing in your "+limb[rndm]+".\n%^BOLD%^RED%^The coin bursts into flame!%^RESET%^\n\nYou feel power surging through your veins.", tp, );
     message("info", tp->query_name()+" catches the coin and it bursts into flame!", environment(tp), tp);
     tp->add_exp(3000000);

     this_object()->bonus(tp);
}

void msg_good(object tp) {
     string *limb;
     int rndm;
     limb = tp->query_wielding_limbs();
     rndm = random(sizeof(limb));
     message("info", "The coin tumbles over and over, landing in your "+limb[rndm]+".\n%^BOLD%^WHITE%^The coin suddenly turns into a feather and floats away.%^RESET%^", tp, );
     message("info", tp->query_name()+" catches the coin and it turns into a feather!", environment(tp), tp);
     tp->add_exp(6000000);
     this_object()->bonus(tp);
}

void bonus(object tp) {
     string *bonus;
     if(tp->query_class() == "rogue" || tp->query_class() == "fighter" || tp->query_class() == "wanderer" || tp->query_class() == "dragon")
       bonus = ({"strength", "dexterity", "constitution"});
     if(tp->query_class() == "mage" || tp->query_class() == "clergy")
       bonus = ({ "intelligence", "wisdom", "constitution" });
     tp->set_stats(bonus[0], tp->query_stats(bonus[0])+2);
     tp->set_stats(bonus[1], tp->query_stats(bonus[1])+2);
     tp->set_stats(bonus[2], tp->query_stats(bonus[2])+2);
     flipping = 0;
     this_object()->remove();
}

int query_auto_load() { return 1; }

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }

int bury() { return 1; }
