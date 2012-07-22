#include <std.h>
#include <move.h>
#include <illuminati.h>

inherit OBJECT;

void create() {
   ::create();
     set_name("crest");
     set_short("%^YELLOW%^Go%^WHITE%^ld%^YELLOW%^en Cr%^WHITE%^e%^YELLOW%^st");
     set_long("This crest is made of gold and shows the sun rising over the horizon.");
     set_id(({ "crest", "golden crest" }));
     set_weight(1);
     set_curr_value("gold", 200000);
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}

int move(mixed dest) {
    if(!objectp(dest)) return ::move(dest);
    if(!dest->is_player()) return ::move(dest);
    new(ILARMOUR"crest.c")->move(dest);
    this_object()->remove();
}
