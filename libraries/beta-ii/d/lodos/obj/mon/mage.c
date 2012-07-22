#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;
void create() {
 ::create();
   set_short("a tall magician");
   set_id( ({ "wizard", "magician" }) );
   set_name("magician");
   set_long("The tall magician owns the shop here. He still practices "
      "the arts of magic and is not only ready but willing to defend "
      "himself. He is a wizard of great power. A long, black beard "
      "flows down about to his waist. And deep, blue eyes meet your "
      "gaze.");
   set_subclass("wizard");
   set_spells(({ "pillar", "manamissile", "fog" }));
   set_spell_chance(60);
   set_class("mage");
   set_body_type("human");
   set_race("gnome");
   set_gender("male");
   if (children("/d/lodos/obj/misc/tome.c")==({})||
        sizeof(children("/d/lodos/obj/misc/tome.c"))==0)
            new(OBJ"tome")->move(this_object());
   set_level(39);
   set_skill("magic attack", 149);
   new(WEA"toadaxe")->move(this_object());
   command("wield toadaxe");
}
int list() {
   write(@ENDTEXT
%^CYAN%^----------------------------------------%^RESET%^
%^RED%^Amulet%^ORANGE%^.......................%^RESET%^500%^ORANGE%^..%^RESET%^Gold
%^CYAN%^----------------------------------------%^RESET%^
ENDTEXT);
   return 1;
}
int buy(string str) {
   if (!str || str != "amulet") return notify_fail("Buy what?\n");
   if (this_player()->query_money("gold") < 500) return notify_fail(
      "You do not have enough for that.\n");
   this_player()->add_money("gold", -500);
   force_me("say Thank you!");
   make(OBJ"amulet");
   force_me("give amulet to "+this_player()->query_name());
   return 1;
}
void init() {
 ::init();
   add_action("list", "list");
   add_action("buy", "buy");
}
