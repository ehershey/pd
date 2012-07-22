#include <std.h>
#include <sakura.h>
inherit BAG;

object o=new("/std/money");

void create() {
    ::create();
    set_name("a corpse");
    set_id( ({ "body", "corpse" }) );
    set_short("a corpse");
    set_long("This is the corpse of an unfortunate male human of Minori origin, slashed and clawed to death. It has probably been dead for half a day, at least, and it looks like some creature with very large teeth has eaten most of his left leg.");
    set_mass(999);
    set_value(50);
    set_prevent_get("It is very disrespectful to move the bodies of the fallen. No doubt this man's family will send a priest to properly dispose of his remains.");

    o->set_money("gold", random(50)+50); 
    o->move(this_object());

    new(WEP"bomo_katana.c")->move(this_object());
    new(WEP"bomo_wakizashi.c")->move(this_object());
    new(WEP"bomo_tanto.c")->move(this_object());
}

int put() 
{ 

    message(0,"This is the body of a human being, not your personal partially-decomposed storage area.", environment(this_object()));
    return 0;

}
