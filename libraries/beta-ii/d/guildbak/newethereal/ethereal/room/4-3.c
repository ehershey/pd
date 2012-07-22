#include <daemons.h>
#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ETHERSTD;
int uncovered;
int markingsc;
int gender;
int soul;
object oi;
void init() {
     ::init();
     add_action("cmd_kick", "kick");
     add_action("cmd_hide", "hide");
     add_action("cmd_wipe", "wipe");
     add_action("cmd_whistle", "whistle");
     add_action("cmd_read", "read");
     add_action("cmd_pray", "pray");
     add_action("cmd_sacrifice", "sacrifice");
     add_action("cmd_love", "love");
}

void create() {
::create();
        oi = new("/std/bboard");
        oi->set_name("Area Board");
        oi->set_id( ({ "board","wall" }) );
        oi->set_board_id("Area_Board");
        oi->set_max_posts(99);
        oi->set_edit_ok(({ "evolution" }));
        oi->set_location(ROOMS"4-3.c");
        oi->set("short", "Bloody rock wall.");
        oi->set("long", "This wall has been written to with blood.");

   set_properties( ([ 
        "light" : 0,
        "outdoors" : 1,
        "no attack"   : 1,
        "no magic"    : 1,
        "no steal"    : 1,
        "no bump"     : 1,
        "no scry"     : 1,
        "no teleport" : 1
]) );
    set_short("Evo's mausoleum");
    set_long(
	"%^BOLD%^%^BLACK%^The area that surrounds you radiates an intense %^RESET%^%^RED%^evil%^BOLD%^%^BLACK%^.  "
	"%^RESET%^%^WHITE%^Stalagmites%^BOLD%^%^BLACK%^ can be seen spiraling upward from the cold stone ground, "
	"indicating decades gone by.  A large %^WHITE%^support%^BLACK%^ structure, engulfed by a thick gray fog "
	"can be see in the distance.  You notice a %^RESET%^%^WHITE%^%^BOLD%^%^BLACK%^stone well%^BLACK%^ near the "
	"middle of the cavern.  A colony of hanging %^RESET%^%^RED%^vampiric bats%^BOLD%^%^BLACK%^ line the walls, they "
	"appear to be sleeping at the moment. Hundreds of headstones line the ground."
   );
    set_items(([
        "room" : "%^BOLD%^%^BLACK%^The cavern has numer of %^RESET%^%^WHITE%^%^BOLD%^%^BLACK%^"
		"headstones%^BLACK%^ lining the ground.",
        "well" : "%^BOLD%^%^BLACK%^You cannot see to the bottom of the well.  "
		"You notice markings on the well.",
        "markings" : "%^BOLD%^%^BLACK%^The initials %^BLUE%^BS%^BLACK%^ can be seen, "
		"There appears to be more, but you cant make it out.",
        "bats" : "%^BOLD%^%^BLACK%^You see a glint in the eye of a large bat "
		"(%^RED%^o.o%^BLACK%^).  You decide its better to not bring attention to yourself here.",
        "headstones" : "%^BOLD%^%^BLACK%^You see thousands of headstones of various designs, "
		"One of them catches your eye, Perhaps you could read it?",
        "headstone" : "%^BOLD%^%^BLACK%^You see thousands of headstones of various designs, "
		"One of them catches your eye, Perhaps you could read it?",
        "stalagmites" : "%^BOLD%^%^BLACK%^Many stalagmites line the ground, some reach "
		"as high as the cavern ceiling.",
        "support" : "%^BOLD%^%^BLACK%^The support structure is surrounded by stalagmites, "
		"blocking your path.  They appear to be very fragile.",
        "support structure" : "%^BOLD%^%^BLACK%^The support structure is surrounded by "
		"stalagmites, blocking your path.  They appear to be very fragile.",
    ]) );
    set_smell("default", "A thick musty smell hangs in the air");
    set_listen("default", "Water droplets from stalagtites can be heard");
    set_exits( ([
        "north" :  ROOMS"4-1.c",
    ]) );
 
}
void reset()

{
    if (!present(MOB"doll")) {
         new(MOB"jen.c")->move(this_object());
    }
}
int cmd_kick(string str) {
     if(str != "stalagmites") {
         notify_fail("What is it you're trying to kick?");
         return 0;
     }
     if(uncovered) {

         write("%^BOLD%^%^BLACK%^You kick, but miss the stalagmites.. It seems they are all broken!");
         say("%^BLACK%^%^BOLD%^"+(string)this_player()->query_cap_name()+" kicks at "
		"the stalagmites but misses like a fool.");
         return 1;
     }
     else {
         write("%^CYAN%^You take a deep breath, and kick the stalagmites with such tremendous force, "
	 "that they %^BOLD%^crumble%^RESET%^%^CYAN%^ to the ground, revealing a hole with hanging vines. "
	 "It seems this support beam reaches much further than you had imagined."
	 );
         say("%^BLACK%^%^BOLD%^"+(string)this_player()->query_cap_name()+" kicks at the stalagmites "
		"that were blocking the support structure.");
         add_exit(ROOMS"4-2.c","vines" );
         add_item("vines","These vines lead downward, you cannot see that far down.  Perhaps "
		"you could try hide them somehow, so no one else notices them.");
         add_item("support","%^BOLD%^%^BLACK%^The support structure is surrounded by shatterd "
		"stalagmites.  You notice some vines near by.");
         add_item("support structure","%^BOLD%^%^BLACK%^The support structure is surrounded by "
		"shatterd stalagmites.  You notice some vines near by.");
         set_pre_exit_functions( ({"vines"}), ({"hidden_room_pre"}) );
         add_item("stalagmites","%^BOLD%^%^BLACK%^The stalagmites appear to be shattered into "
		"thousands of pieces!");
         uncovered = 1;
         return 1;
     }
}
int cmd_hide(string str) {
        if(str == "vines") {
                write("%^BOLD%^%^BLACK%^You replace the shards of stalagmite to block the path to the vines.");
                say("%^BLACK%^%^BOLD%^You see "+(string)this_player()->query_cap_name()+" rummaging "
			"around near the support structure.");
                add_item("stalagmites","%^BOLD%^%^BLACK%^Many stalagmites line the ground, some "
			"reach as high as the cavern ceiling. They appear to be very fragile.");
                remove_exit("vines");
                remove_item("vines");
                uncovered = 0;
                return 1;
        }
        if(str == "markings") {
                write("%^BOLD%^%^BLACK%^You smother dirt across the markings so no one else may read it.");
                add_item("markings","%^BOLD%^%^BLACK%^The initials %^BLUE%^BS%^BLACK%^ can be seen, "
			"There appears to be more, but you cant make it out.");
                add_item("support","%^BOLD%^%^BLACK%^The support structure is surrounded by stalagmites, "
			"blocking your path.  They appear to be very fragile.");
                add_item("support structure","%^BOLD%^%^BLACK%^The support structure is surrounded by "	
			"stalagmites, blocking your path.  They appear to be very fragile.");
                return 1;
        }
        else {
                write("%^BOLD%^%^BLACK%^What exactly are you trying to hide?");
                return 0;
        }
}
int hidden_room_pre() {
	string mf;
	if (this_player()->query_gender() == "male") mf = "he";
	else mf = "she";
        write("%^BOLD%^%^BLACK%^You replace the shards of stalagmite to block the path to the vines.\n");
        say("%^BLACK%^%^BOLD%^You see "+this_player()->query_cap_name()+" rummaging around near the support "
		"structure, "+ mf +" then %^BOLD%^%^CYAN%^dissapears%^BLACK%^!%^RESET%^\n");
        remove_exit("vines");
        uncovered = 0;
        this_player()->move(ROOMS"4-2.c");
	this_player()->describe_current_room(1);
        message(
		"environment", this_player()->query_cap_name()+
		" appears from nowhere.",environment(this_player()), 
		({ this_player()})
	);
        return 0;
}

int cmd_wipe(string str) {
        if(str != "markings") {
                notify_fail("What exactly are you trying to wipe?");
                return 0;
        }
        write("%^BOLD%^%^BLACK%^You gently wipe the dirt away from the markings on the well, you uncover more wording!");
        say("%^BLACK%^%^BOLD%^You notice "+(string)this_player()->query_cap_name()+" doing something by the well.");
        add_item("markings", "%^BOLD%^%^BLACK%^The markings read: %^BLUE%^BS%^BLACK%^ %^RED%^<3 %^BLUE%^JN");
        return 1;
}
int cmd_whistle() {
    if (!present("cerberus")) {
         write("%^BOLD%^%^BLACK%^You whistle loudly! %^RED%^Cerberus%^BLACK%^ charges at you, and then stops.\n");
         say("%^BLACK%^%^BOLD%^You notice "+(string)this_player()->query_cap_name()+" call for a mount.  "
		"%^RED%^Cerberus %^BLACK%^appears!\n");
         new(MOB"cerberus.c")->move(this_object());
	 this_player()->force_me("ride cerberus");
    }
        return 1;
}

int cmd_read(string str) {
int month;
int year;
int name;
int day;
int blah;
    if (str == "headstone") {
    write("%^BLACK%^%^BOLD%^ Here lays %^ORANGE%^"+this_player()->query_cap_name()+"%^BLACK%^, the "+this_player()->query_race()+".\n");
    month = EVENTS_D->query_month_name(this_player()->query_birthday());
    year = EVENTS_D->query_year(this_player()->query_birthday());
    name = EVENTS_D->query_day_name(this_player()->query_birthday());
    day = EVENTS_D->query_day(this_player()->query_birthday());
    blah = ordinal(EVENTS_D->query_day(this_player()->query_birthday()));
    write(" %^BOLD%^%^WHITE%^ "+name+" the "+day+blah+" of "+month+".\n");
    month = EVENTS_D->query_month_name(time());
    year = EVENTS_D->query_year(time());
    name = EVENTS_D->query_day_name(time());
    day = EVENTS_D->query_day(time());
    blah = ordinal(EVENTS_D->query_day(time()));
    write("              -\n");
    write(" %^BOLD%^%^WHITE%^ "+name+" the "+day+blah+" of "+month+".\n");
    say("%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" is reading a headstone.\n");
    return 1;
    }
}
int cmd_pray() {
        write("%^RED%^The ground begins to tremble.\n");
        say("%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" is mumbling to himself.\n");
        write("%^BOLD%^%^BLACK%^Beelzebub%^CYAN%^: %^RED%^YOU HAVE DISTURBED MY  SLEEP! I am tempted to "
		"DESTROY YOU!  Unless you hand me your soul, I will devour you!");
        soul = 1;
        return 1;
}
int cmd_sacrifice(string str) {

        if (str != "soul") {
                write("%^BOLD%^BLACK%^Sacrifice what?%^");
                return 1;
        }
        if (soul == 1) {
                soul = 0;
                write("%^BLACK%^%^BOLD%^A%^RESET%^ %^RED%^Sa%^BOLD%^ta%^BLACK%^nic %^RED%^Ri%^RESET%^%^RED%^ng%^RESET%^%^BOLD%^%^BLACK%^ "
		"falls from the air, and %^RED%^singes%^BLACK%^ your palm as you grab it."
		);
                say("%^BOLD%^%^BLACK%^You see something drop into "+this_player()->query_cap_name()+"'s hand!");
                new(OBJ"evilring.c")->move(this_player());
		this_player()->force_me("wear satanic ring");
                return 1;
        }
}
int cmd_love() {
	if (this_player()->query_name() == "evolution") {
		write("Your love for Kumi produced a beautiful heart!");
		new(OBJ"heart")->move(this_player());
		this_player()->force_me("wear heart");
		return 1;
	}	
	if (this_player()->query_name() == "kumi") {
		write("Your love for Evolution produced a beautiful heart!");
		new(OBJ"heart")->move(this_player());
		this_player()->force_me("wear heart");
		return 1;
	}
	return 0;
}
