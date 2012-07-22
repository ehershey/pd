//      /std/armour.c
//      from the Nightmare Mudlib
//      the basic inherited armour object
//      created by Descartes of Borg 25 june 1993

#include <teststd.h>
#include <security.h>

#define ELEMENTS ({ "fire", "earth", "ice" })

inherit OBJECT;

private mapping armour_save;
private static mapping armour_static;
private static int theft=0, fingers=0;
private static mapping Elemental;

void unwear();
void extinguish_glow();
void unequip();
void set_not_equipped();
void set_ac(int x);
void set_theft(int i);
int query_theft();
void set_illuminate(int x);
void set_limbs(mixed *borg);
void set_wear(mixed val);
void set_remove(mixed val);
void set_type(string str);
int query_ac();
mixed *query_limbs();
string query_wear_string();
object query_wear_func();
string query_remove_string();
object query_remove_func();
string query_type();
object query_worn();
void set_element(string element, int arm);
int query_element(string element);

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("wear", "wear");
    add_action("do_remove", "remove");
    add_action("illuminate", "illuminate");
}

void create() {
    ::create();
    armour_save = ([]);
    armour_static = ([]);
    Elemental = ([]);
}

void set_element(string element, int arm) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return;

    if(arm > 40)
	arm = 40;
    if(arm < -100)
	arm = -100;

    Elemental[element] = arm;
}

int query_element(string element) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return 0;

    if(!Elemental[element])
	return 0;

    return Elemental[element];
}

int wear(string str) {
    mixed *limbs;
    mapping all;
    string ret, what, where, *id, tmp, *rings, *left;
    int i, j, n, counter;
    object *inv;

    if(member_array(query_type(), ({"helmet", "mask", "body armour", "armour", "cloak", 
	"saddle", "blanket", "shield", "robes", "ring", "belt", "pants", "boots", "leggings", 
	"tunic", "bracelet", "necklace", "vest", "bracers", "gloves", "halo", "badge", 
	"quiver", "backpack", "earrings", "wing armour", "chainmail", "shirt", "dress", 
	"sash", "hat", "garter", "cape", "clasp", "coat", "collar", "amulet" })) == -1) {
	write("This peice of armour is bugged.  It has been reported.  "
	  "We appreciate your patience.");
	seteuid(UID_LOG);
	if(base_name(this_object()) != file_name(this_object())) 
	    log_file("balarm",base_name(this_object())+" set_type() out of bounds.\n");
	seteuid(geteuid());
	return 1;
    }

    if(this_player()->query("bear") || this_player()->query("lion") || this_player()->query("wolf")) return notify_fail("Your armor will not fit in this form.\n");
    if(!str) return notify_fail("Wear what?\n");
    if (str=="all")
    {
	inv = all_inventory(this_player());
	if (!inv)
	{
	    write("You have nothing to wear.");
	    return 1;
	}
	i = sizeof(inv);
	all = ([]);
	while(i--)
	{
	    id = inv[i]->query_id();
	    if (inv[i]->is_armour())
	    {
		if (!all[ id[0] ]) all[ id[0] ] = ({ id[0] });
		else all[ id[0] ] += ({ id[0] });
		n = sizeof( all[ id[0] ]);

		tmp = sprintf("%s %d", id[0], n);
		if (present(tmp, this_player()) && !present(tmp, this_player())->query_worn()) {
		    if(n > 1)
			this_player()->force_me("wear "+id[0]+" "+n);
		    else
			this_player()->force_me("wear "+id[0]);
		}
	    }
	}
	return 1;
    }
    if(!id(what = str) && sscanf(str, "%s on %s", what, where) != 2) {
	if(parse_objects(this_player(), str) != this_object()) {
	    notify_fail("You don't have that!\n");
	    return 0;
	}
    }
    else if(!id(what) && parse_objects(this_player(), what) != this_object()) {
	notify_fail("You don't have that!\n");
	return 0;
    }
    if(query_worn()) {
	message("my_action", "You are already wearing that!", this_player());
	return 1;
    }
    if(fingers) {
	if (fingers != this_player()->query_fingers()) {
	    message("info", "The "+query_name()+" was made for "+fingers+" fingers.", this_player());
	    return 1;
	}
    }
    if(this_object()->query_type() == "ring") {
	switch(this_player()->query_race()) {
	case "dragon":
	    rings = this_player()->query_armour("front right claw");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 3) {
		this_object()->set_limbs(({"front left claw"}));
		break;
	    }
	    rings = this_player()->query_armour("front left claw");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 3) {
		this_object()->set_limbs(({"front right claw"}));
		break;
	    }
	    if(random(2) == 0)
		this_object()->set_limbs(({"front right claw"}));
	    else
		this_object()->set_limbs(({"front left claw"}));
	    break;
	case "bastet":
	    rings = this_player()->query_armour("right paw");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 3) {
		this_object()->set_limbs(({"left paw"}));
		break;
	    }
	    rings = this_player()->query_armour("left paw");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 3) {
		this_object()->set_limbs(({"right paw"}));
		break;
	    }
	    if(random(2) == 0)
		this_object()->set_limbs(({"right paw"}));
	    else
		this_object()->set_limbs(({"left paw"}));
	    break;
	case "raknid":
	    left = ({"first hand", "second hand", "third hand", "fourth hand"});
	    rings = this_player()->query_armour("first hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 2)
		left -= ({"first hand"});
	    rings = this_player()->query_armour("second hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 2)
		left -= ({"second hand"});
	    rings = this_player()->query_armour("third hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 2)
		left -= ({"third hand"});
	    rings = this_player()->query_armour("fourth hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= 2)
		left -= ({"fourth hand"});
	    if(sizeof(left) == 0)
		left = ({"first hand"});
	    this_object()->set_limbs(({left[random(sizeof(limbs))]}));
	    break;
	default:
	    rings = this_player()->query_armour("right hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= this_player()->query_fingers()) {
		this_object()->set_limbs(({"left hand"}));
		break;
	    }
	    rings = this_player()->query_armour("left hand");
	    i = sizeof(rings);
	    counter = 0;
	    while(i--) {
		if(rings[i] == "ring")
		    counter++;
	    }
	    if(counter >= this_player()->query_fingers()) {
		this_object()->set_limbs(({"right hand"}));
		break;
	    }
	    if(random(2) == 0)
		this_object()->set_limbs(({"right hand"}));
	    else
		this_object()->set_limbs(({"left hand"}));
	    break;
	}
    }
    i = sizeof(limbs = query_limbs());
    while(i--) {
	if(stringp(limbs[i])) continue;
	if((j=member_array(where, limbs[i])) != -1) limbs[i] = limbs[i][j];
	else if(where) {
	    message("my_action", "You cannot wear this on your "+where+".",
	      this_player());
	    return 1;
	}
	else {
	    message("my_action", "You must specify which limb you want this "
	      "on.", this_player());
	    return 1;
	}
    }
    //Added to prevent dragons from wearing armour
    if(this_player()->query_race() == "dragon" && this_object()->query_type() != "ring" && !this_object()->query("dragon wear")) {
	write("Your scales are armour enough!");
	return 1;
    }
    if(ret = (string)this_player()->equip_armour_to_limb(this_object(),limbs)){
	if(ret == "NO") return 1;
	message("my_action", ret, this_player());
	return 1;
    }
    if(stringp(armour_static["wear"]))
	message("my_action", armour_static["wear"], this_player());
    else message("my_action", "You wear "+query_short()+".", this_player());
    if (environment(this_player()))
	message("other_action", (string)this_player()->query_cap_name()+
	  " wears "+(string)this_player()->query_possessive()+" "+query_short()+
	  ".", environment(this_player()), ({ this_player() }));
    armour_static["worn by"] = this_player();
    armour_static["actual limbs"] = limbs;
    id = ELEMENTS;
    for(i = 0;i < sizeof(id);i++) {
	if(!Elemental[id[i]])
	    continue;
	if(Elemental[id[i]] < 0)
	    write("You feel more vulnerable to "+id[i]+".");
	else if(Elemental[id[i]] > 0)
	    write("You feel protected against "+id[i]+".");
        this_player()->add_element_armor(id[i], Elemental[id[i]]);
    }
    return 1;
}

int do_remove(string str) {
    object *inve;
    int a;
    if (str=="all")
    {
	inve = all_inventory(this_player());
	for(a=0;a<sizeof(inve);a++) {
	    if(inve[a]->is_armour()&&inve[a]->query_worn())
		inve[a]->unwear();
	}
	return 1;
    }
    if(!str) return notify_fail("Remove what?\n");
    if(!id(str) && parse_objects(this_player(), str) != this_object()) {
	notify_fail("You don't have that!\n");
	return 0;
    }
    if(!query_worn()) {
	message("my_action", "You are not wearing that!", this_player());
	return 1;
    }
    /*
	    if(functionp(armour_static["unwear"])){
		    if(!((*armour_static["unwear"])())) return 1;
	    }
    */
    unwear();
    return 1;
}

int illuminate(string str) {
    int heure;

    if(!query_property("magic item") || 
      member_array("illuminate", query_property("magic item")) == -1) return 0;
    if(!str || !id(str)) {
	notify_fail("Illuminate what?\n");
	return 0;
    }
    heure = 5*((int)this_player()->query_stats("wisdom")) +
    (int)this_player()->query_skill("conjuring");
    if(heure < 20) heure = 20;
    if((int)this_player()->query_mp() < heure/10) {
	write("Too low on magic power.\n");
	return 1;
    }
    this_player()->add_mp(-(heure/10));
    write("Your "+query_name()+" begins to glow.\n");
    say(this_player()->query_cap_name()+"'s "+query_name()+" begins to
glow.\n");
    environment(this_object())->set_property("light",
      (armour_static["lit"] = 1+random(3)));
    call_out("extinguish_glow", heure);
    return 1;
}
 
void unwear() {
    string *id;
    if(functionp(armour_static["unwear"])){
       if(!((*armour_static["unwear"])())) return;
    }
    if(stringp(armour_static["unwear"]))
      message("my_action", armour_static["unwear"], armour_static["worn by"]);
    else 
      if (!query_theft())
       message("my_action", "You remove your "+query_short()+".",
      armour_static["worn by"]);
    armour_static["worn by"]->remove_armour_from_limb(this_object(),
      armour_static["actual limbs"]);
  if (!query_theft())
    if(environment(armour_static["worn by"]))
    message("other_action", (string)armour_static["worn by"]->query_cap_name()+
      " removes "+(string)armour_static["worn by"]->query_possessive()
      +" "+query_name()+".", environment(armour_static["worn by"]),
      ({ armour_static["worn by"] }));
    map_delete(armour_static, "worn by");
    map_delete(armour_static, "actual limbs");
    id = ELEMENTS;
    for(int i = 0;i < sizeof(id);i++) {
      if(!Elemental[id[i]])
        continue;
      if(Elemental[id[i]] < 0)
        write("You feel less vulnerable to "+id[i]+".");
      else if(Elemental[id[i]] > 0)
        write("You feel less protected against "+id[i]+".");
      this_player()->set_element_armor(id[i], Elemental[id[i]] - this_player()->query_element_armor(id[i]));
    }
}
 
void extinguish_glow() {
    if(!this_object()) return;
    if(!armour_static["lit"]) return;
    if(living(environment(this_object()))) {
        tell_object(environment(this_object()),"The magic glow of your
"+query_name()+" fades away.\n");
        tell_room(environment(environment(this_object())),
environment(this_object())->query_cap_name()+"'s "+query_name()+
          "magic glow fades away.\n", ({environment(this_object()) }) );
    }
    else tell_room(environment(this_object()), "The magic glow of the "+
      query_name()+" fades away.\n");
    environment(this_object())->set_property("light", -armour_static["lit"]);
    map_delete(armour_static, "lit");
}
 
void unequip() { if(armour_static["worn by"]) unwear(); }
 
void set_not_equipped() {
    if(query_worn()) map_delete(armour_static, "worn by");
    if(armour_static["actual limbs"]) map_delete(armour_static, "actual limbs");}
 
int remove() {
    if(armour_static && armour_static["lit"]) {
      if(environment(this_object()))
        environment(this_object())->set_property("light",-armour_static["lit"]);
        map_delete(armour_static, "lit");
    }
    return ::remove();
}
 
int move(mixed dest) {
    int x;
 
    if(armour_static["lit"])
      environment(this_object())->set_property("light", -armour_static["lit"]);
    x = ::move(dest);
    if(armour_static["lit"])
      environment(this_object())->set_property("light", armour_static["lit"]);
    return x;
}
 
void set_ac(int x) { armour_save["ac"] = x; armour_save["original ac"] = x; }
 
void set_illuminate(int x) { set_property("magic item", ({ "illuminate" })); }
 
void set_limbs(mixed *borg) { armour_save["possible limbs"] = borg; }
 
void set_wear(mixed val) {
    
    armour_static["wear"] = val;
}
 
void set_remove(mixed val) {
    
    armour_static["unwear"] = val;
}
 
void set_type(string str) { armour_save["type"] = str; }
 
int query_ac() { return armour_save["ac"] + query_property("enchantment"); }
 
mixed *query_limbs() { return armour_save["possible limbs"]; }
 
mixed query_wear() { return armour_static["wear"]; }
 
mixed query_unwear() { return armour_static["unwear"]; }
 
string query_type() { return armour_save["type"]; }
 
object query_worn() { return armour_static["worn by"]; }
 
 
string query_short() {
    if(!armour_static["worn by"]) return ::query_short();
    else return ::query_short()+" (worn)";
}
 
string query_long(string str) {
    string ret;
    int i;
    if(!armour_static["worn by"]) return ::query_long(str);
    else {
        ret = ::query_long(str);
        i = sizeof(armour_static["actual limbs"]);
        ret += "\nWorn on: "+armour_static["actual limbs"][--i];
        if(i>-1) while(i--) ret += ", "+armour_static["actual limbs"][i];
        ret += ".\n";
        return ret;
    }
}
 
string *query_actual_limbs() { return armour_static["actual limbs"]; }
 
int is_armour() { return 1; }
 
void set_struck(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    armour_static["struck"] = val;
}

mixed query_struck() { return armour_static["struck"]; }

void set_theft(int i) { theft = i; }

int query_theft() { return theft; }

void force_decay()
{
    if(!armour_save["ac"]) return;
    armour_save["ac"]--;
    set("value",20+query("value")*armour_save["ac"]/armour_save["original ac"]);
    message("environment", "You notice some wear on your "+
      query_short()+".", armour_save["worn"]);
}

int query_fingers() { return fingers; }

void set_fingers(int x) { fingers = x; }
