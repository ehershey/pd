#include <std.h>
#include <guild.h>
inherit VENDOR;
void create() {
    ::create();
    set_name("dratatt");
    set_id( ({ "dratatt", "vendor", "shop keeper", "keeper", "shopkeeper", "Dra'tatt the Eternal"}) );
    set_short("%^BOLD%^BLACK%^Dra'tatt the Eternal");
    set_level(1);
    set_long("Dra'tatt is the last member of the original Vorticon family. He was the only ascended one who survived the massacre of Tahgarr for he made a pact with the dark ones which ensured his survival. His physical appearance is quite vague since his body is eternally blurred between human and vapour form. The only part of his body which is visible is his red eyes for the rest of his body is concealed by a black robe.");
    set_languages( ({ "undeadish" }) );
    set_gender("male");
    set_alignment(-600);
    set_race("vampire");
    set_body_type("human");
    set_currency("gold");
    set_storage_room(VORTICON "storage.c");
    set_property("no bump", 1);
}

