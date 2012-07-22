#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("an ogre berserker");
   set_id(({ "ogre", "berserker", "ogre berserker" }));
   set_name("ogre");
   set_level(27);
   set_long(@END
         ___
       _(((,|
      /  _-\\
     / C o\o \
   _/_    __\ \
  /   \ \___/  )
  |    |\_|\  /
  |    |#  #|/
  (   /     |
   |  |#  # |
   |  |    #|
   |  | #___n_,_
,-/   7-' .     `\
`-\...\-_   -  o /
   |#  # `---U--'
   `-v-^-'\/
     \  |_|_ Wny
     (___mnnm
END);
   set_body_type("ogre");
   set_race("ogre");
   set_gender("male");
   set_heart_beat(1);
   set_alignment(-250);
   make(ARM"ogloves");
   make(ARM"loin");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wear gloves");
     force_me("wear loincloth");
     oi = 1;
   }
}
