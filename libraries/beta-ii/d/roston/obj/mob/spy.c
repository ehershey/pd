#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
    ::create();
    set_name("Bum");
    set_short("An old bum");
    set_long("The old bum really gives a false impression.  His robes are "
      "golden, and his hands and fingers are cleaned.  He has rings on his "
      "fingers.  This guy looks very strong and well trained.");
    set_id(({"bum", "old bum", "spy"}));
    set_level(55);

    new(ARM"robes")->move(this_object());
    new(WEP"s_dagger")->move(this_object());
    set_race("drow");
    set_body_type("human");
    set_gender("male");
    set_heart_beat(1);
if(random(200) > 190) {
   new("/wizards/daboura/arm/dull_brass_bracers.c")->move(this_object());
   command("wear bracers");
}
}                     

void init()
{
    ::init();
}

void heart_beat()
{
    ::heart_beat();
    if (!wielded_sword)
    {
	this_object()->force_me("wear robes");
	this_object()->force_me("wield dagger");
	wielded_sword = 1;
    }
}                            

