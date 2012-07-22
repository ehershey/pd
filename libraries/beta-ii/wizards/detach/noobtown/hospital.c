#include <std.h>
#include <daemons.h>
#include <radyne.h>

inherit ROOM;

#define COST    money/bonus

void init() {
    ::init();
    add_action("new_body", "renew");
    add_action("clean_poison", "clean");
    add_action("regenerate", "regenerate");
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
   set_short("%^MAGENTA%^%^BOLD%^Hospital of Radyne Nova%^RESET%^");
    set("long",
     "%^BOLD%^%^BLUE%^The Radyne Nova Hospital%^RESET%^\n"
     "A dull white interior, typical of clerics performing services to the public screams through the surfaces of this otherwise, cozy building. "
        "A list of all services that can be performed is posted on the wall.");
    set_items(([
        "list" : "You can read all the services by typing <read list>.",
          "hospital" : "The clerics here specialize in regenerating "
            "lost limbs.",
          "clerics" : "They are mending the wounds of patients."]));
   set_exits( ([
     "stairs" : ROOMS "clergy/cleric/cleric_join",
     "north" : ROOMS "m001e",
   ]) );
    set_property("no teleport", 1);
}

int new_body(string str) {
    object *inv;
    int i;

    if( (int)this_player()->query_level() > 5) {
        notify_fail("The clerics only perform this service for the inexperienced.\n");
        return 0;
    }
    inv = all_inventory(this_player());
    for(i=0; i<sizeof(inv); i++) {
        inv[i]->unequip();
    }
    write("A cleric comes over to you and mutters a small prayer.");
    write("You again have all the limbs you were born with!");
    say("A cleric mutters a small prayer for the novice "+this_player()->query_cap_name()+".", this_player());
    this_player()->new_body();
    return 1;
}

int read(string str) {
    if(!str) {
        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "list") {
        notify_fail("That is not here for reading.\n");
        return 0;
    }
    message("info", "Welcome to the Hospital of Radyne Nova!",this_player());
    message("Ninfo",
        "The clerics perform the following services:\n"
        "%^BOLD%^%^MAGENTA%^------------------------------------------------------------------%^RESET%^\n"
        "%^BOLD%^%^BLUE%^<%^CYAN%^renew body%^BLUE%^>%^RESET%^: This is a charity service the clerics perform for\n"
        "       novice adventurers who have lost limbs while adventuring.\n"
        "       All limbs are replaced.\n"
        "%^BOLD%^%^BLUE%^<%^CYAN%^regenerate%^BLUE%^ [%^CYAN%^limb%^BLUE%^]>%^RESET%^: This service is for the experienced adventurer\n"
        "       who has lost limbs.  The limb is replaced and acts like new.\n"
        "       Tithe schedule for regeneration:\n"
        "            from 320 gold for minor limbs (non-clerics)\n"
        "            to 800 gold for major limbs (non-clerics)\n"
        "            240 to 600 gold for clerics\n"
        "%^BOLD%^%^BLUE%^<%^CYAN%^clean poison%^BLUE%^>%^RESET%^: Helps remove some of the poison from your body.\n"
        "\ttithe: 50 gold\n"
        "%^BOLD%^%^MAGENTA%^------------------------------------------------------------------%^RESET%^\n"
        "Half off all regenerations with the severed limb!\n"
        "Your tithe is used only toward good causes.\n", this_player());
    return 1;
}

int clean_poison(string str) {
    object tp;

    if(!str) return 0;
    if(str != "poison") return 0;
    tp = this_player();
    if((int)tp->query_poisoning()<1) {
        notify_fail("%^BOLD%^%^CYAN%^A cleric whispers to you: %^RESET%^But you are not poisoned!\n");
        return 0;
    }
    if((int)tp->query_money("gold") < 50) {
        notify_fail("You do not have enough gold for the tithe.\n");
        return 0;
    }
    tp->add_money("gold", -50);
    tp->add_poisoning(-10);
    write("A cleric casts a spell of healing upon you.");
    say("A cleric casts a spell of healing on "+tp->query_cap_name()+".", tp);
    return 1;
}

int regenerate(string limb) {
    int money, bonus;
    mapping limb_info;
    object tp;
    string *there, *missing;

    tp = this_player();
    if(present(limb, this_player())) bonus = 2;
    else bonus = 1;
    there = (string *)tp->query_limbs();
    missing = (string *)this_player()->query_severed_limbs() +
      (string *)RACE_D->query_limbs((string)this_player()->query("race"));
/*
   checking with the race_d is allowing compatibility with old
   versions of the mudlib
*/
    if(!missing) {
        notify_fail("You aren't missing any limbs!\n");
        return 0;
    }
    if(member_array(limb, missing) == -1) {
        notify_fail("You are not missing that limb!\n");
        return 0;
    }
    if(member_array(limb, there) != -1) {
        notify_fail("You already have that one back!\n");
        return 0;
    }
    limb_info= (mapping)RACE_D->query_limb_info(limb,(string)tp->query("race"));
    if(!limb_info) {
        notify_fail("That limb cannot be replaced!\n");
        return 0;
    }
    if(limb_info["attach"] != "0") {
        if(member_array(limb_info["attach"], there) == -1) {
            notify_fail("You would need a "+limb_info["attach"]+" for that!\n");
            return 0;
        }
    }
    if((string)this_player()->query_class() == "cleric") money = 1200;
    else money = 1600;
    money = money / limb_info["max"];
    if((int)tp->query_money("gold") < COST) {
        notify_fail("The cleric tells you:  You do not have enough gold.\n");
        return 0;
    }
    tp->add_limb(limb, limb_info["ref"], (int)tp->query_max_hp()/limb_info["max"], 0, 0);
    if(member_array(limb, (string *)RACE_D->query_wielding_limbs((string)tp->query("race"))) != -1) 
        tp->add_wielding_limb(limb);
    this_player()->add_money("gold", -COST);
    say(sprintf("%s asks the clerics for some help with %s missing %s.",
      this_player()->query_cap_name(), possessive(this_player()), limb));
    write("The clerics restore your "+limb+"!");
    return 1;
}
