inherit "/std/vendor";
#include <shadow.h>;
int i;
create() {
    ::create();
   set_name("geften");
   set_id( ({ "geften", "vendor", "shop keeper", "keeper", "shopkeeper" }) );
   set_short("Geften, the Jolly Smithy");
   set("aggressive", 0);
   set_level(12);
   set_long("Geften has taken a break from blacksmithing to attend to the "
        "customers in his shop.");
   set_languages( ({ "eltherian" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "elf");
   set_hp(480);
   add_money("gold", random(100));
    set_storage_room(ROOMS "smithy.c");
   set_body_type("human");
   set_currency("gold");
   set_skill("melee",100);
   set_skill("bargaining", 150);
   set_property("no bump", 1);
        i =0;
}
int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in eltherian Oh my! I'm being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
void catch_tell(string str) {
        string a,b;
        object ob;
    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%syes%s", a, b) == 2) {
        this_object()->force_me("say Then i shall tell you what i know.");
        call_out("constory", 3);
        } else
    if(sscanf(str, "%suest%s", a, b) == 2) {
        this_object()->force_me("say You must be more specific with me "
                                "when asking such questions.");
        return;
    }
    if(sscanf(str, "%sbook%s", a, b)==2) {
        this_object()->force_me("say Ahh did that old man send you to "
        			"talk to me about "
                                "the book?");
        i=1;
        return;
    }
    if(sscanf(str, "%slodos%s", a, b)==2) {
        this_object()->force_me("say I have seen the mist that "
				"inhabits the holy city of Lodos.  "
				"I wish someone could do something "
				"about the comming evil that is about "
				"to enter the world.");
    return;
    }

}

void constory() {
this_object()->force_me("say It has been so long ago.  I dont even remember the "
			"the exact details.  But however i do know that the "
			"task that you wish to undertake.");
call_out("constory2", 4);
}

void constory2() {
this_object()->force_me("say I first heard of the Ancient Book of Spells "
			"from an old trader that i had met in Tirun "
			"on my way to pick some items up from one of the "
			"sea-going vessels.  He told me of a book that contained "
			"much power that many men have sought and died for.  But "
			"There was one catch,  if the demons of the underworld "
			"found the book life on the planet would become evil "
			"and twisted.  It is now thought that the book was held "
			"deep inside of the Tirun Sewers.  Perhaps it is still "
			"there.  Without that book im sorry to say but you "
			"will not be able to re-enter the city of Lodos and more "
			"of the world will become Forsaken.");
}


