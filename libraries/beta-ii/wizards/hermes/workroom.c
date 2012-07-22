#include <std.h>
#include <hermes.h>
inherit ROOM;
object ob;
void init()
{
	::init();
	add_action("dropper","drop");
}
void create()
{
        ::create();
        set_properties
        ( 
        ([ "light" : 2, "night light" : 2, "town" : 1]) 
        );
        set_short("Hermes's Test");
        set_long
        (
                "%^BOLD%^%^CYAN%^That's odd... There's nothing here.  Just a huge, empty room. But wait, what's that up top?"
                "%^BOLD%^%^CYAN%^A %^BLUE%^pale%^CYAN%^, %^YELLOW%^%^CYAN%^thin, %^WHITE%^beam of light%^CYAN%^ coming from the upper streches of "
                "%^BOLD%^%^CYAN%^the massive domed ceiling connects to a series of interlocking mirrors at the bottom of the room. A collective gasp "
                "%^BOLD%^%^CYAN%^as the light seems to litterally %^GREEN%^shatter%^CYAN%^ fragments of pure %^GREEN%^energy%^CYAN%^ thrown everywhere. "
                "%^BOLD%^%^CYAN%^A brilliant light fills the room, blinding all within.  It gradually settles down, the shards of light forming objects "
                "%^BOLD%^%^CYAN%^chairs, a desk, a window that looks onto space infinit�.  This, trully, is the domain of Hermes."
        );
     
        set_items
        (([
                "light" : "The light was used to hide the room? Or maybe to make it?",
                "beam" : "The beam was as perfect as you could imagine.  As would be expected from a pure, raw, energy expansion.",
                ({"domed ceiling", "ceiling", "dome", "domed"}) : "It streches high! Really high, like a cathedral.",
                "mirrors" : "They are perfectly transparant, one would think that would be a scientific impossibility but then again after witnessing the things just seen...",
                "chairs" : "They look comfortable.  Hermes really likes his guests to feel at home.",
                "desk" : "Full of crumpled paper and notes written in blood threatening action against Stormy's pet Cow if he doesn't put in his area.",
                "window" : "Stars...everywhere.  Hermes has always been a scientist and explorer at heart.",
                "Hermes" : "He tries his best."
        ]));
       
        set_exits
        (([
        "distopia" : "/d/distopia/room/startlod",
"disintegrator" : "/wizards/hermes/dis",
"square" : "/d/nopk/tirun/square",
        "elsewhere" : "/d/standard/adv_inner"
        ]));
   
    ob = new(BBOARD);
    ob->set_name("hermes");
    ob->set_location("/wizards/hermes/workroom");
    ob->set_id( ({ "board", "hermes board" }) );
    ob->set_board_id("hermes_idea");
    ob->set_max_posts(99);
    ob->set_short("Hermes's Board");
    ob->set_long("Balance Board.");
    
}
int dropper(string str)
{
    this_player()->force_me("put "+str+" in star");
    return 1;
}
void reset() 
{
	if(!present("star"))
		new("/wizards/hermes/star")->move(this_object());
	if(!present("ilithyd"))
		new("/wizards/hermes/illy")->move(this_object());
	if(!present("box"))
		new("/wizards/hermes/box")->move(this_object());
	
}
