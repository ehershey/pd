#include <std.h>
#include <move.h>
#include <illuminati.h>

inherit OBJECT;

void create() {
   ::create();
     set_name("Illuminati band");
     set_short("Member's Band");
     set_long("If you are a part of the Illuminati you may wear this as a show of rank. You can only wear one at a time.");
     set_id(({ "metal band", "bronze band", "silver band", "gold band", "band"}));
     set_weight(2);
     set_curr_value("gold", 250);
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}    

int move(mixed dest) {
    if(!objectp(dest)) return ::move(dest);
    if(!dest->is_player()) return ::move(dest);
    new(ILARMOUR"ilband.c")->move(dest);
    this_object()->remove();
}
