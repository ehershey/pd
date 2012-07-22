//  Shipcombat Module
#define OCEAN_D  "/wizards/whit/ocean/ocean.c"
#define DEFAULT_HP 100
int damaged, speed;
mapping upgrades;
mapping hp_data;
void create() {
    upgrades=([]);
    hp_data=([]);
}
int *get_xy() { return this_object()->query_xy(); }
void echo(string str) { message("environment", str, this_object()); }
int query_hp() { if(!hp_data) create(); return hp_data["hp"]; }
void set_hp(int i) { if(!hp_data) create(); hp_data["hp"]=i; }
int add_hp(int i) { if(!hp_data) create(); hp_data["hp"]=hp_data["hp"]+i; }
int query_speed() { return speed; }
int add_speed(int i) { speed=speed-i; }
void do_damage_to_boat(int i);
void destroy_ship();
int shoot(string str) {
    string to, msg;
    object *s, o;
    int i, x1,y1,x2,y2, X, Y;
    X=get_xy()[0];
    Y=get_xy()[1];
    if(sscanf(str, "%s at %s", msg, to)!=2) return notify_fail("Shoot cannons at who?\n");
    if(msg != "cannons") return notify_fail("Shoot cannons at who?\n");
    s=OCEAN_D->get_room_ships(this_object(), X, Y);
    s -= ({this_object()});
    i=sizeof(s);
    if(lower_case(to) == this_player()->query_name()) {
	write("It would not be wise to shoot yourself.\n");
	return 1;
    }
    if(!o=OCEAN_D->get_boat(to)) {
	write("You do not notice that ship here.\n");
	return 1;
    }
    x1=get_xy()[0];
    y1=get_xy()[1];
    x2=o->get_xy()[0];
    y2=o->get_xy()[1];
    if(x1 != x2 || y1 != y2) {
	write("You do not notice that ship here.\n");
	return 1;
    }
    if(!find_player(o->query_owner())) {
	write("You may not attack an unmaned ship.\n");
	return 1;
    }
    o->do_damage_to_boat(upgrades["cannon"]+random(5));
    return 1;
}
int get_armour() { 
    if(!upgrades["armour"]) upgrades["armour"]=1;
    return upgrades["armour"]; 
}
void add_armour(int amt) {
    upgrades["armour"]=upgrades["armour"]+amt;
}
void do_damage_to_boat(int i) {
    object at
    ;
    at=previous_object();
    if(i>=20) return echo("Your...000000000 ship is dicimated by "+
	  capitalize(at->query_owner())+"'s cannons!");
    if(i>=15) return echo("Your ship is severely damaged badly by "+
	  capitalize(at->query_owner())+"'s cannons!");
    if(i>=10) return echo("Your ship is damaged by "+
	  capitalize(at->query_owner())+"'s cannons!");
    if(i>=5) return echo("Your ships is hit by "+
	  capitalize(at->query_owner())+"'s cannons!");
    if(i>1) return echo("Your ship is barely tapped by "+
	  capitalize(at->query_owner())+"'s cannons.\n");
    if(i==1) {
	echo("Your ship is narrowly missed by "+capitalize(at->query_name())+"'s cannons!\n");
	message("", "You miss "+capitalize(this_object()->query_name())+"'s ship.", at);
    } else {
	add_hp(-i);
	message("", "You hit "+this_object()->query_owner()+"'s ship!\n", at);
    }
    if(query_hp() < 1) destroy_ship();
}
int query_damage() { return damaged; }
int query_max_hp() { 
    int i;
    i=DEFAULT_HP/3*(int)get_armour();
    return i;
}
void destroy_ship() {
    object at;
    at=previous_object();
    message("environment", 
      capitalize(this_object()->query_owner())+"'s ship is "
      "destroyed by your cannons!\n", at);
    echo("Your ship is destroyed!\n");
}
int view_status() {
    int i, spare;
    string tmp;
    write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*");
    write("Armour Level:  "+get_armour()+"");
    write("Speed Level:   "+query_speed()+"");
    tmp=percent(query_hp(), query_max_hp())+"";
    sscanf(tmp, "%d.%d", i, spare);
    write("Ships Damage:  "+i+"%");
    write("\nFor ship repairs or upgrades, please see John "
      "in Tirun.");
    write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*");
    return 1;
}
