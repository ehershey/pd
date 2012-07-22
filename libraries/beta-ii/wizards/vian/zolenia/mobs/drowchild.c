#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow child");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ child");
    set_long("This young drow boy is fairly strong looking for his age, although he still has some growing up to do to be a formidable opponent.");
    set_id(({"drow", "child", "drowchild", "drow child"}));
    set_level(30+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment("-500");
    set_gender("male");
    set_class("fighter");
    set_subclass("warrior");
   new(ARM"darkshirt")->move(this_object());
     force_me("wear shirt");
   new(WEP"toysword")->move(this_object());
     force_me("wield sword");

    add_money("gold", random(200));
    set_spell_chance(25);   
    set_spells(({"slash", "headbutt"}));   
}

