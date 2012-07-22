#include <std.h>
#include <waterworld.h>

inherit MONSTER;


int counter,x;

void create() {
    ::create();
    set_name("blueboy");
    set_id(({"blue whale","blueboy","whale"}));
    set_short("%^BLUE%^BOLD%^Blueboy%^RESET%^, the blue whale.");
    set_long("This is %^BLUE%^BOLD%^Blueboy%^RESET%^, the blue whale. He is patiently awaiting his turn to get his skin cleaned of
barnacles and oil.");
    set_level(60);
    set_body_type("fish");
    set_race("blue whale");
    set_gender("male");
    set_class("clergy");
    set_subclass("monk");
    set_emotes(1,({
        "%^BLUE%^%^BOLD%^Blueboy%^RESET%^ tilts his head to see if the dispatcher has called his name yet.",
        "%^BLUE%^BOLD%^Blueboy%^RESET%^ exhales through his blowhole, spraying everyone in the cavern!!",
        "%^BLUE%^BOLD%^Blueboy%^RESET%^ shifts his wieght at the dock, causing a moderate wave to ripple through the cavern."
      }),0);
/// blubber loader
          counter=(1 +(random(random(5))) );

           for(x;x<counter;x++)
                {
                   new(ITEMS1+"blubber.c")->move(this_object());
                   }
}
//// quest routines

void catch_tell(string recieved) {
    string pname;

    if(sscanf(recieved,"%s tells you: where%*s manatee mike%*s",pname)>=1){
        call_out("response",2,pname);
        return;
    }
}

void response(string pname){
    if(!present(pname))
    {
        force_me("tell "+pname+" I'm an old whale and don't hear so well. Can you come to me so we can talk
easier?");
    }
    else {
        force_me("tell "+pname+" Manatee Mike should be in his office. It's over there through that
passageway.\n\n");
        force_me("emote waves his head towards the east, knocking someone into the water.....");

    }
}
string affect_environment() { return " Perhaps one of these guys knows where Manatee Mike is?"; }
