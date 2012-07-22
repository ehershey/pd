#include <std.h>
#include <durst.h>

inherit MONSTER;

int xran = random(200);
int yran = random(100);

void create()
{
    ::create();
    set_name("parched nomad");
    set_id(({"nomad", "parched nomad", "man", "parched man" }));
    set_short("A parched nomad");
    set_long("A very old looking nomad of the desert. He is very thirsty.");
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_level(30);
    set_heart_beat(5);
    set_moving(1);
    set_speed(1);
    
    if (yran < 5)
        {
            new(ARM"md-thick_body_armour.c")->move(this_object());
            force_me("wear armour");
        }
        else
        {
            new(ARM"md-body_armour.c")->move(this_object());
            force_me("wear armour");
        }
        if(xran < 2)
        {
            new(WEP"mystic_mace.c")->move(this_object());
            force_me("wield axe");
        }
        else if(xran > 2 && xran < 20)
        {
            new(WEP"md-flail.c")->move(this_object());
            force_me("wield flail");
        }
        else if(xran > 19)
        {
            new(WEP"md-spear.c")->move(this_object());
            force_me("wield spear");
        }
    
}

void heart_beat()
{
    ::heart_beat();
}

