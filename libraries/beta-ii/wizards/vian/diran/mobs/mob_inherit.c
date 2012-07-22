#include <std.h>
#include <diran.h>

inherit MONSTER;

string faction, status, opposite_faction;

void create(){
::create();
}

void init(){
::init();
    opposite_faction = MOB"factions_d.c"->opposite_faction(faction);
    status = MOB"factions_d.c"->faction_status(opposite_faction, this_player()->query_name());
    if(status == opposite_faction + " revered"){
    this_object()->kill_ob(this_player());}
    if(status == opposite_faction + " exhalted"){
    this_object()->kill_ob(this_player());}
    return;
 }

void set_faction(string str){
    faction = str;
}

void query_faction(){ return faction; }

void die(mixed ob){
    int point;
    if(ob && userp(ob)){ 
        if(faction == "duergar") point = -1;
        else point = 1;
        MOB"factions_d.c"->add_points(ob->query_name(), point);
    }
    if(random(100) < 85){
    if(present("diranweapon")) present("diranweapon", this_object())->remove();
    }
    ::die(ob);
}
