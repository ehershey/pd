#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Captain");
set_short("A Captain of Macbeth's army");
set_long("The captain of his brigade, he is one of the few men who still sides
with Macbeth wholeheartedly.");
set("aggressive",20);
set_class("fighter");
set_moving(1);
set_speed(10);
set_swarm("soldier");
set_level(57);
set_id(({"soldier","captain"}));
set_skill("double wielding", 200);
set_subclass("soldier");
set_skill("attack", 220);
set_skill("defense",220);
set_race("human");
set_body_type("human");
set_gender("male");
set_spell_chance(40);
set_spells(({"behead"}));
set_emotes(10, ({"%^CYAN%^The Captain screams:%^RESET%^ Die!!!!!!!!!!", "The Captain eyes you confidently."}),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/malshiel")->move(this_object());
new("/wizards/powerman/arm/ironplat")->move(this_object());
new("/wizards/powerman/arm/finecape")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/diasword")->move(this_object());
new("/wizards/powerman/arm/diasword")->move(this_object());
command("wield sword");
command("wield sword 2");
command("sharpen sword");
command("sharpen sword 2");
set_languages("farsi");
set_speech(35,"farsi",({"Attack Soldiers, Attack!", "My death will be an honorable one."}),1);

}
