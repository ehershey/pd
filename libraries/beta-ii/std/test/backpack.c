//      /std/backpack.c 2:56 PM 4/20/2002
//      allows a wearable bag
//      based on armor.c and bag_logic.c std files
//      a dungeonware.net production in collaberation with Nightshade
#include <teststd.h>
#include <move.h>
inherit CONTAINER;
private mapping armour_save;
private static mapping armour_static;
private static int theft=0;
void unwear();
void unequip();
void set_not_equipped();
void set_ac(int x);
void set_theft(int i);
int query_theft();
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
string open_long_desc;
string closed_long_desc;
mapping lock_data;
void toggle_lock();
void init()
{
    if(environment(this_object()) != this_player()) return;
    add_action("wear", "wear");
    add_action("do_remove", "remove");
    add_action("illuminate", "illuminate");
    add_action("get_from","get");
    add_action("put_into","put");
    add_action("open_container","open");
    add_action("close_container","close");
    add_action("unlock_container", "unlock");
    add_action("lock_container", "lock");
}
int put_into(string str)
{
    int res;
    object ths,tht;
    string this, that;
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-6) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2) {
	if (present(this,this_player())) {
	    if (present(that,this_player()) || present(that,
		environment(this_player()))) {
		ths = present(this,this_player());
		tht = present(that, this_player());
		if(ths == tht) /* Plura 930208 */
		{
		    notify_fail("Get real!\n");
		    return 0;
		}
		if(!tht) tht = present(that, environment(this_player()));
		if(ths->drop()) {
		    notify_fail("You cannot drop that!\n");
		    return 0;
		}
		if (this_player()->query_paralyzed()) {
		    return notify_fail(this_player()->query_paralyze_message());
		}
		if (tht->receive_objects()) {
		    res = (int)ths->move(tht);
		    if (res == MOVE_OK) {
			write("You put "+ths->query_short()+" in "+
			  tht->query_short()+".\n");
			say(this_player()->query_cap_name()+" puts "
			  +ths->query_short()+ " in "+tht->query_short()+".\n");
			return 1;
		    }
		    if (res == MOVE_NO_ROOM) 
			notify_fail("For some reason it does not fit...\n");
		    if (res == MOVE_NOT_ALLOWED)
			notify_fail("You are not allowed to do that...\n");
		    return 0;
		}
		notify_fail("It is closed.\n");
		return 0;
	    }
	    notify_fail(capitalize(that)+" is not here.\n");
	    return 0;
	}
	notify_fail("You are not carrying "+this+".\n");
	return 0;
    }
    return 0;
}
int get_from(string str) {
    int res, i;
    object ob, tmp, *inv;
    string what, where;
    if(!stringp(str)) return 0;
    if(this_player()->query_ghost()) {
	write("You cannot do that as a ghost.");
	return 1;
    }
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(sscanf(str, "%s from %s", what, where) != 2) return 0;
    if(id(where)) tmp = this_object();
    else tmp = parse_objects(environment(this_object()), where);
    if(tmp != this_object()) return 0;
    if(this_object()->receive_objects()) {
	if(what != "all") {
	    ob = present(what, this_object());
	    if(!ob) ob = parse_objects(this_object(), what);
	    if(!ob) {
		write("There is no "+what+" in "+this_object()->query_short()+".");
		return 1;
	    }
	    res = (int)ob->move(this_player());
	    if(res == MOVE_OK) {
		write("You get "+ob->query_short()+" from "+this_object()->query_short()+".");
		say(this_player()->query_cap_name()+" gets "+ob->query_short()+" from "+this_object()->query_short()+".", this_player());
		return 1;
	    }
	    if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
	    if(res == MOVE_NO_ROOM) write("You can't carry that!");
	    return 1;
	}
	inv = all_inventory(this_object());
	if(!sizeof(inv)) {
	    write("There is nothing in "+this_object()->query_short()+".");
	    return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
	    res = (int)inv[i]->move(this_player());
	    if(res == MOVE_OK) {
		write("You get "+inv[i]->query_short()+" from "+this_object()->query_short()+".");
		say(this_player()->query_cap_name()+" gets "+inv[i]->query_short()+" from "+this_object()->query_short()+".", this_player());
	    }
	    if(res == MOVE_NO_ROOM) write(inv[i]->query_short()+": Too heavy.\n");
	}
	return 1;
    }
    write(query_short()+" is closed.");
    return 1;
}
void set_closed_long(string str)
{
    closed_long_desc = str;
}
void set_open_long(string str)
{
    open_long_desc = str;
}
string query_long(string str)
{
    object *inv;
    int i, per;
    string desc;
    string *key=({});
    desc = container::query_long(0);
    if ((int)this_object()->receive_objects() || (int)this_object()->clear()) {
	inv = all_inventory(this_object());

	if (sizeof(inv) > 0 ) {
	    i = sizeof(inv);
	    for(i=0; i<sizeof(inv); i++)
		key += ({ inv[i]->query_short() });
	    key = consolidate_string( key );
	    desc += "  It contains:\n";
	    for(i=0;i<sizeof(key);i++)
		desc += "  "+capitalize((string)key[i])+"\n";
	}
	if( this_object()->query_max_internal_encumbrance() ) {
	    per = to_int(percent(this_object()->query_internal_encumbrance(),
		this_object()->query_max_internal_encumbrance()));
	    desc += "\nThis "+this_object()->query_name()+" is " + per + "%
full.\n";
        }

    if(!this_object()->receive_objects()) desc += "  It is closed.";
    return desc;
}
}
int open_container(string str)
{
    if (stringp(str) && this_object()->id(str)) {
	if(lock_data) {
	    if(lock_data["status"] == "locked") {
		notify_fail("It is locked.\n");
		return 0;
	    }
	}
	if (this_object()->receive_objects()) write("It is already open.");
	else {
	    if (open_long_desc)
		set_long(open_long_desc);
	    this_object()->toggle_closed();
	    write("You open "+this_object()->query_short()+".");
	    say(this_player()->query_cap_name()+
	      " opens "+this_object()->query_short()+ ".");
	}
	return 1;
    }
    return 0;
}
int close_container(string str)
{
    if (stringp(str) && this_object()->id(str)) {
	if (!this_object()->receive_objects()) write("It is already closed.");
	else if (!this_object()->toggle_closed()) write("It cannot be closed.");
	else {
	    if (closed_long_desc)
		set_long(closed_long_desc);
	    write("You close "+this_object()->query_short()+".");
	    say(this_player()->query_cap_name()+" closes "+
	      this_object()->query_short()+".");
	}
	return 1;
    }
    return 0;
}
int lock_container(string str) {
    if(!str) {
	notify_fail("Lock what?\n");
	return 0;
    }
    if(!this_object()->id(str)) {
	notify_fail("That is not here.\n");
	return 0;
    }
    if(!lock_data) {
	notify_fail("You can't lock that!\n");
	return 0;
    }
    if(this_object()->receive_objects()) {
	notify_fail("It must be closed before you can lock it.\n");
	return 0;
    }
    if(lock_data["status"] == "locked") {
	notify_fail("It is already locked!\n");
	return 0;
    }
    if(lock_data["key"]) {
	if (present(lock_data["key"], this_player()) ||
	  present("infmastakey", this_player())) {
	    if (present("infmastakey", this_player()) &&
	      !present(lock_data["key"], this_player()) &&
	      environment(this_player())->query_query_quest_room()) {
		write("The quicksilver melts, but some magic keeps it from reforming.");
		return 1;
	    }
	    write("You lock the "+str+".\n");
	    say(this_player()->query_cap_name()+" locks the "+str+".\n");
	    toggle_lock();
	    return 1;
	}
    }
    else if(!lock_data["key"]) {
	write("You lock the "+str+".\n");
	say(this_player()->query_cap_name()+" locks the "+str+".\n");
	toggle_lock();
	return 1;
    }
    else {
	notify_fail("Lock the "+str+" with what?\n");
	return 0;
    }
}
int unlock_container(string str) {
    if(!str) {
	notify_fail("Unlock what?\n");
	return 0;
    }
    if(!this_object()->id(str)) {
	notify_fail("That is not here!\n");
	return 0;
    }
    if(!lock_data) {
	notify_fail("It does not have a lock.\n");
	return 0;
    }
    if(lock_data["status"] != "locked") {
	notify_fail("It is not locked.\n");
	return 0;
    }
    if(!lock_data["key"]) {
	write("You unlock the "+str+".\n");
	say(this_player()->query_cap_name()+" unlocks the "+str+".\n", this_player());
	toggle_lock();
	return 1;
    }
    if(!present(lock_data["key"], this_player()) &&
      !present("infmastakey", this_player())) {
	notify_fail("Unlock the "+str+" with what?\n");
	return 0;
    }
    if (present("infmastakey", this_player()) &&
      !present(lock_data["key"], this_player()) &&
      environment(this_player())->query_query_quest_room()) {
	write("The quicksilver melts, but some magic keeps it from reforming.");
	return 1;
    }
    write("You unlock the "+str+".\n");
    say(this_player()->query_cap_name()+" unlocks the "+str+".\n", this_player());
    toggle_lock();
    return 1;
}
void toggle_lock() {
    if(!lock_data) return;
    if(lock_data["status"] == "locked") lock_data["status"] = "unlocked";
    else lock_data["status"] = "locked";
}
int query_locked() {
    if(!lock_data) return 0;
    if(lock_data["status"] == "locked") return 1;
    else return 0;
}
int pick_lock() {
    if(!lock_data) return 0;
    toggle_lock();
    return 1;
}
void set_lock(string stat) {
    if(stat != "locked" && stat != "unlocked") {
	if(!lock_data) lock_data = ([ "status": "locked" ]);
	else lock_data["status"] = "locked";
	return;
    }
    if(!lock_data) lock_data = ([ "status": stat ]);
    else lock_data["status"] = stat;
}
void set_key(string str) {
    if(!lock_data) lock_data = ([]);
    lock_data["key"] = str;
}
int is_bag() { return 1; }
void create() {
    ::create();
    armour_save = ([]);
    armour_static = ([]);
    armour_save["ac"] = 1; armour_save["original ac"] = 1; 
    armour_save["possible limbs"] = ({"torso"});
    armour_save["type"] = "backpack";
}

int wear(string str) {
    mixed *limbs;
    mapping all;
    string ret, what, where, *id, tmp;
    int i, j, n;
    object *inv;

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
		if (!present(tmp, this_player())->query_worn()) {
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
    if(ret = (string)this_player()->equip_armour_to_limb(this_object(),limbs)){
	if(ret == "NO") return 1;
	message("my_action", ret, this_player());
	return 1;
    }
    //Added to prevent dragons from wearing armour
    if(this_player()->query_race() == "dragon" && this_object()->query_type() != "ring") {
	write("The pack is to small for you!");
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
    return 1;
}

int do_remove(string str) {
    if(!str) return notify_fail("Remove what?\n");
    if(!id(str) && parse_objects(this_player(), str) != this_object()) {
	notify_fail("You don't have that!\n");
	return 0;
    }
    if(!query_worn()) {
	message("my_action", "You are not wearing that!", this_player());
	return 1;
    }
    if(functionp(armour_static["unwear"])){
	if(!((*armour_static["unwear"])())) return 1;
    }
    unwear();
    return 1;
}

void unwear() {
    if(stringp(armour_static["unwear"]))
	message("my_action", armour_static["unwear"], armour_static["worn by"]);
    else 
    if (!query_theft())
	message("my_action", "You remove your "+query_short()+".",
	  armour_static["worn by"]);
    armour_static["worn by"]->remove_armour_from_limb(this_object(),
      armour_static["actual limbs"]);
    if (!query_theft())
	message("other_action", (string)armour_static["worn by"]->query_cap_name()+
	  " removes "+(string)armour_static["worn by"]->query_possessive()
	  +" "+query_name()+".", environment(armour_static["worn by"]),
	  ({ armour_static["worn by"] }));
    map_delete(armour_static, "worn by");
    map_delete(armour_static, "actual limbs");
}

void unequip() { if(armour_static["worn by"]) unwear(); }

void set_not_equipped() {
    if(query_worn()) map_delete(armour_static, "worn by");
    if(armour_static["actual limbs"]) map_delete(armour_static, "actual limbs");}

void set_wear(mixed val) {

    armour_static["wear"] = val;
}

void set_remove(mixed val) {

    armour_static["unwear"] = val;
}

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
