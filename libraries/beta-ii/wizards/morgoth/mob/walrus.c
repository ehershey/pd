#include <std.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("walrus");
   set_short("The Walrus is here, digesting clams");
   set_long("It's The Walrus!!!!");
   set_race("human");
   set_body_type("walrus");
   set_level(5);
   set_gender("male");
   set_class("fighter");
   set_id(({"walrus"}));
   new("/wizards/morgoth/arm/walrusskin.c")->move(this_object());
   new("/wizards/morgoth/wep/tusk.c")->move(this_object());
   this_object()->force_me("wear skin");
   this_object()->force_me("wield tusk");
   }
