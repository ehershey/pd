
#include <std.h>

inherit WEAPON;


int special1(object atk);
int special2(object atk);
int special3(object atk);


void create() {
    ::create();
    set_id( ({ "spear", "lava spear", "lavaspear" }) );
    set_name("Lava Spear");
    set_short("%^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a %^RED%^S%^ORANGE%^p%^RED%^e%^ORANGE%^a%^RED%^r%^RESET%^");
    set_long(
      "This is the famed %^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a %^RED%^S%^ORANGE%^p%^RED%^e%^ORANGE%^a%^RED%^r%^RESET%^. You feel proud to be holding this weapon....."
    );
   set_mass(4);
    set_value(1000);
    set_type("projectile");
    set_wc(15);
    set_ac(1);
    set_hit((:this_object(),"weapon_hit":));  
}

int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    switch(random(3)) {
    case(0) : return special1(atk);
	break;
    case(1) : return special2(atk);
	break;
    case(2) : return special3(atk);
	break;
    }
    return result;
}

int special1(object atk) {
    int result;
    if(random(100) > 60) {
	write("Your spear burns "+atk->query_cap_name()+" badly.");
	say((string)this_player()->query_cap_name()+
	  "'s spear burns "
	  +atk->query_cap_name()+".");
	result=(random(60+random(40)-random(30))*((this_player()->query_level()/20)+1));
	result=random(result)+10;
	return result;
    }
}
int special2(object atk) {
    int result;
    if(random(100) > 75) {
	write("Your spear sucks the power from "+atk->query_cap_name()+". ");
	say((string)this_player()->query_cap_name()+
	  " seems to grow stronger as "+this_player()->query_possessive()+" spear sinks into "+
	  atk->query_cap_name()+"'s skin");
	result=(random(60+random(40)-random(30))*((this_player()->query_level()/20)+1));
	result=random(result)+10;
	this_player()->add_hp(result/2);
	return result;
    }
}
int special3(object atk) {
    int result;
    if(random(100) > 80) {
	write("Your spear sends "+atk->query_cap_name()+" gasping for air. ");
	say((string)this_player()->query_cap_name()+
	  " smites "+atk->query_cap_name()+" knocking the wind out of "+objective(atk)+".");
	result=(random(60+random(40)-random(30))*((this_player()->query_level()/20)+1));
	result=random(result)+10;

	atk->set_paralyzed(result/10, "Your stomach hurts! You cant't breathe!", "You regain your breath.");
	return result;
    }
}
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }