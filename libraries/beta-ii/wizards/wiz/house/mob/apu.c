#include <wiz.h>
inherit MONSTER;
object ob;
string wizitem, *items;
int i, cost, squish_level;

void create(){
 ::create();
 items=({ "1", "2", "3" });
 set_name("Apu");
 set_id(({"apu", "apu", "clerk" }));
 set_short("Apu the hindu clerk");
 set_long("h0h0");
 set_level(15);
 set_race("hindu");
 set_gender("male");
 set_body_type("human");
}

void init() {
    ::init();
    add_action("buy", "buy");
}

int price(object tp, string thing) {
    if(thing=="1")cost=71;
    if(thing=="2")cost=37;
    if(thing=="3")cost=50;
    if((int)tp->query_money("gold") < cost) return 0;
    tp->add_money("gold", -cost);
    return cost;
}

int buy(string itemm) {
    if(!itemm) {
        force_me("say What is it you would like?");
        return 0;
    }
    if(member_array(itemm, items) == -1){
        force_me("say We do not sell "+itemm+".");
        return 0;
    }
    if(!(cost = price(this_player(), itemm))) {
        force_me("say You do not have enough gold for that!");
        return 1;
    }
    if(itemm=="1"){
      ob = new(HOUSEITEM"nachos.c");
      ob->set_value(1);
      ob->set_weight(1);
      ob->set_short("A package of Nachos");
      ob->set_long("Kwik-E Mart Nachos with chilli and cheese.");
      ob->set_name("Nachos");
      ob->set_id(({"nachos", "package of nachos"}));
      wizitem="Package of Nachos";
      }
    if(itemm=="2"){
      ob = new(HOUSEITEM"squishie.c");
      ob->set_squish_level(2);
      ob->set_value(15);
      ob->set_weight(5);
      ob->set_short("A Super Squishie");
     ob->set_long("This is a Super (32oz) Squishie obtained from the Kwik-E "
                   "Mart in wiz's house.");
      ob->set_name("Super Squishie");
      ob->set_id(({"Super Squishie", "squishie", "slurpee", "large squishie"}));
      wizitem="Large Squishie";
      }
    if(itemm=="3"){
      ob = new(HOUSEITEM"squishie.c");
      ob->set_squish_level(3);
      ob->set_value(37);
      ob->set_weight(7);
      ob->set_short("A h0h0 Squishie");
      ob->set_long("This is a h0h0 (52oz) Squishie obtaned from the Kwik-E "
                   "Mart in wiz's house.");
      ob->set_name("h0h0 Squishie");
      ob->set_id(({"h0h0 Squishie", "squishie", "slurpee"}));
      wizitem="h0h0 Squishie";
      }
    write("You pay "+cost+" gold coins for a "+wizitem+".");
    say(this_player()->query_cap_name()+" buys a "+wizitem+".", this_player());
    ob->move(this_player());
    return 1;
}
