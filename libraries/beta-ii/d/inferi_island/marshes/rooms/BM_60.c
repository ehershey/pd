#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Broken trees and crushed shrubs show signs of something big having recently traveled through this way. The path of destruction thankfully heads away from the main trail. More sporadic %^RED%^f%^BOLD%^%^RED%^i%^BLACK%^r%^RED%^e%^RESET%^%^RED%^s %^ORANGE%^make the air thick with %^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^. Laying forgotten on the ground, a small rusty blade sits embedded in the soft earth.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"BM_66", "southwest" : MARSHROOM+"BM_50" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("southwest", "sp_sap");
}
