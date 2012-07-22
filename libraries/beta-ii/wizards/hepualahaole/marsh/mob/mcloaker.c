#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
    ::create();
    set_gender("male");
    set_name("cloaker");
    set_id( ({ "cloaker"}) );
    set_short("cloaker");
    set_long("The cloaker gets his name because they resemble so much like a cloak.");
    set_level(45);
    set_body_type("bat");
    set_alignment(-120);
    set_race("bat-like cape");
    set_class("fighter");

}
