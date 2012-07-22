//Mistoffelees

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();

    set_short("Regulators Badge");
    set_name("badge");
    set_id( ({ "Regulators Badge" }) );
    set_long("A badge reading: To serve and protect;The way of the
Regulators.");
    set_type("badge");
    set_limbs( ({ "torso" }) );
    set_weight(1);
    set_value(15000);
    set_ac(10);

}

void init() {
    ::init();
add_action("hunt", "hunt");

}

int give() {
   if (this_player()->query_name() == "mistoffelees") return 0;
   return 1;
}
int query_auto_load() { return 1; }
int put() { return 1; }
int drop() {
if (this_player()->query_name() == "mistoffelees") return 0;
return 1;
}
int bury() {
if (this_player()->query_name() == "mistoffelees") return 0;
if (this_player()->query_name() == "wiz") return 0;
return 1;
}
int dest() {
if (this_player()->query_name() == "mistoffelees") return 0;
return 1;
}

int hunt(string str) {
    if (!str) return 0;
    if (str!="outlaw")return 0;
    message("myaction", "You don your Regulator gear and go hunting for.\n",
this_player());
    message("youraction", this_player()->query_cap_name()+" Dons their "
    "Regulator gear and goes hunting for outlaws.\n",
environment(this_player()), this_player());
    new("/wizards/mistoffelees/test/sword.c")->move(this_player());
      this_player()->force_me("drop all");
      this_player()->force_me("get all");
return 1;
}

