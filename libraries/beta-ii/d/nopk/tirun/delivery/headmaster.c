// Drackypoo.  The headmaster for the delivery system.
#include <std.h>
#include "deliv.h"
inherit MONSTER;
int jobapp(string str);
create() {
    ::create();
    set_property("no bump", 1);
    set_name("Headmaster");
    set_id( ({ "headmaster", "boss", "manager", "delivery lord", "delivery headmaster" }) );
    set_short("The Headmaster of the warehouse");
    set_level(100);
    set_long("This is the headmaster of the delivery service of Tirun. "
      " Although stern and fair looking, he is quite worried that all of his delivery "
      " boys quit the job.  He now must find someone to take his packages to the people "
      " of the world, or else his business will be ruined.\n\n"
      "If you want to take a job delivering something, try: accept job.");
    set_gender("male");
    set_alignment(1250);
    set_race("human");
    set_body_type("human");
    new(DEL"robes.c");
    command("wear robes");
}
void init(){
    ::init();
    add_action("jobapp", "accept");
}
int jobapp(string str){
    int x;
    if(!str) return notify_fail("Accept what");
    if(this_object()->query_property(this_player()->query_name()+"late")==1) return notify_fail("I am very angered with your work.  You may not deliver packages for awhile.\n");
    if(str!="job") return notify_fail("You can only accept jobs.\n");
    if(this_object()->query_property(this_player()->query_name()+"recout")==1) return notify_fail("You have not turned in your last receipt, so I cannot give you another package!\n");
    write_file(DEL"delivlog", ""+this_player()->query_name()+" - "+time()+"\n", 0);
    write("%^CYAN%^The headmaster says:%^RESET%^ Ahh, so you wish to take a job for me.  Well.."
      " I have a package that needs delivering right now.");
    write("You must realize, it is no easy task.  These customers are ruthless, and demand "
      "quick service.  Be fast.");
    say("The headmaster utters a few words to "+this_player()->query_cap_name());
    x=random(7);
    switch(x){
    case 0:
	new(DEL"armour.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Drendun.");
	break;
    case 1:
	new(DEL"lars.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Lars, the Barkeep.");
	break;
    case 2:
	new(DEL"light.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Morian, the light expert.");
	break;
    case 3:
	new(DEL"oil.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Patrick, the oil seller.");
	break;
    case 4:
	new(DEL"tanner.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Garon, the master tanner.  It is slightly perishable, so delivery quickly.");
	break;
    case 5:
	new(DEL"sage.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to The Sage of Tirun.");
	break;
    case 6:
	new(DEL"weapon.c")->move(this_object());
	write("%^CYAN%^The headmaster says:%^RESET%^ This must be delivered to Xor, the old.");
	break;
    }
    force_me("resetclockdevob");
    force_me("give package to "+this_player()->query_name());
    this_object()->set_property(this_player()->query_name()+"recout", 1);
    write("The headmaster rushes you along.  Hurry!");
    return 1;
}
void catch_tell(string str) {
    object ob, obbit;
    string abba, bobo, cats;
    if(sscanf(str, "%s gives you %sreceipt%s", abba, bobo ,cats) == 3) {
	if(!(ob=present((abba=lower_case(abba)), environment(this_object())))) return;
	if(!present("receipt", this_object())) return;
	obbit = present("receipt", this_object());
	if(obbit->query_property("late")==1){
	    write("%^CYAN%^The headmaster says:%^RESET%^ What!?  You did not make the delivery on time!  How dare you make a mockery of my business!");
	    write("In fact, I shall not let you deliver packages for me for awhile.  I'm not sure I can trust you now.");
	    this_object()->set_property(this_player()->query_name()+"recout", -1);
	    this_object()->set_property(this_player()->query_name()+"late", 1);
	    return;
	}
	else{
	    write("%^CYAN%^The headmaster says:%^RESET%^ Good, I see my delivery was made on time.  I am most grateful.  You may make another delivery whenever you wish.");       
	    this_object()->set_property(this_player()->query_name()+"recout", -1);
	    return;
	}
    }
}