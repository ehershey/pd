#include <std.h>
#include <tirun.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;

void create() {
    ::create();
    set_no_clean(1);
    set_name("storage room");
    set_short("storage room");
    set_long("This room holds the stuff for the Guild Town general shop.");
    set_exits((["north" : GROOM "miscshop"]) );     
}
void reset(){
    ::reset();
    if (!present("tirun seal")) 
	new("/d/nopk/tirun/obj/misc/tirun_seal_new.c")->move(this_object());
    if (!present("tirun seal 2")) 
	new("/d/nopk/tirun/obj/misc/tirun_seal_new.c")->move(this_object());
    if(random(100) < 50) {
	if (!present("wax")) 
	    new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_object());  
	if(!random(65)) {
	    if (!present("wax 2")) 
		new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_object());
	}  
    }
}
