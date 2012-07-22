#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ROOM;

void create() {
    ::create();
    set_name("weapon storage");
    set_short("weapon");
    set_long("This is the weapon storage room to Ethereal.  You shouldnt be in
here.");
    set_exits((["west":ROOMS"2-1.c"]));
}

void reset() {
    ::reset();
    if(!present("eidolon", this_object())) {
        new(WEP"eidolon")->move(this_object());
        new(WEP"eidolon")->move(this_object());
    }
    if(!present("alchymia", this_object())) {
        new(WEP"alchymia")->move(this_object());
        new(WEP"alchymia")->move(this_object());
    }
    if(!present("stave", this_object())) {      
        new(WEP"staff")->move(this_object());
        new(WEP"staff")->move(this_object());
    }
    if(!present("dragonaxe",this_object())) {
        new(WEP"el_axe")->move(this_object());
        new(WEP"el_axe")->move(this_object());
    }
    if(!present("falcate", this_object())) {
        new(WEP"el_knife")->move(this_object());
        new(WEP"el_knife")->move(this_object());

    }
    if(!present("star", this_object())) {
        new(WEP"ninja_star")->move(this_object());
        new(WEP"ninja_star")->move(this_object());
    }
    if(!present("fleshrender", this_object())) {
        new(WEP"el_flail")->move(this_object());
        new(WEP"el_flail")->move(this_object());
    }
    if(!present("gabul", this_object())) {
        new(WEP"hm_flail")->move(this_object());
        new(WEP"hm_flail")->move(this_object());
    }
    if(!present("mightyaxe", this_object())) {
        new(WEP"hm_axe")->move(this_object());
        new(WEP"hm_axe")->move(this_object());
    }

}
