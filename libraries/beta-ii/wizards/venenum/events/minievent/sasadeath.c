#include <std.h>
inherit OBJECT;

string destination = users();

void create() {
    ::create();
    set_name("body");
    set_id( ({ "sasayaki", "body of sasayaki", "sasayakis body", "sasayaki's body"}) );
    set_short("The kneeling form of Sasayaki");
    set_long("Sasayaki The Slayer. %^BOLD%^%^RED%^Seth. Scoff. Scamp. Autema. Agent. Byblos.%^RESET%^");
    set_mass(100);
    set_prevent_get("What?");
}

int death_scene(){
    message("say", "%^BOLD%^%^BLACK%^Sasayaki's dark blood stains the ground as he props himself up with his lightning blade. Asmodeus snarls angrily.%^RESET%^", destination);
    call_out("kill3", 10);
}

int kill3(){
    message("say", "%^BOLD%^%^BLACK%^Asmodeus strides past the kneeling Sasayaki, glaring about. '%^CYAN%^You fools,%^BLACK%^' he growls, his shadowy form waving behind him, '%^CYAN%^You think you can stop me? My spirit is bound to his, and I can simply heal him with a thought. Observe.%^BLACK%^'%^RESET%^", destination);
    call_out("kill4", 10);
}

int kill4(){
    message("say", "%^BOLD%^%^BLACK%^Sasayaki's wounds close and he appears completely rejuveniated. The translucent form of Asmodeus seems to shrink some, while the body of Sasayaki grows larger. Asmodeus is clearly gaining full control of Sasayaki's body.", destination);
    call_out("kill5", 10);
}

int kill5(){
    message("say", "%^BOLD%^%^BLACK%^Asmodeus emits a laugh, shaking his head. '%^CYAN%^You see? He is restored. And soon he will be me... and then my plan may begin.%^BLACK%^'%^RESET%^", destination);
    call_out("kill6", 10);
}

int kill6(){
    message("say", "%^BOLD%^%^BLACK%^Sasayaki seems suddenly smaller. His body shrinks slightly, growling as simply utters one simple word. '%^CYAN%^No.%^BLACK%^'%^RESET%^", destination);
    call_out("kill7", 10);
}


int kill7(){
    message("say", "%^BOLD%^%^BLACK%^Asmodeus turns to face his possession, raising an eyebrow curiously. '%^CYAN%^No?%^BLACK%^' he echos, seeming suprised, apart from the grin stamped on his face. '%^CYAN%^You have *no choice*. You surrendered your soul to me. You gave your body to me as my vassel. You have *no will*.%^BLACK%^'%^RESET%^", destination);
    call_out("kill8", 10);
}

int kill8(){
    message("say", "%^BOLD%^%^BLACK%^Sasayaki adopts a calm smile. '%^CYAN%^Even the worst of us can change.%^BLACK%^' He raises the sword of lightning high above his head, then plunges it into his belly. Bolts of lightning arc forth from the weapon, Asmodeus' face showing concern for the first time.%^RESET%^", destination);
    call_out("kill9", 10);
}

int kill9(){
    message("say", "%^BOLD%^%^BLACK%^The sword does it's work, draining the soul out of the body; which in Sasayaki's case, is Asmodeus. Sasayaki tears the weapon from his gut, smashing it against the ground. The weapon explodes with the sheer force of the blow, bolts of lighting backlashing into Sasayaki's body. Scorched to ashes by the powerful electricity, he crumples over onto his side, dead.%^RESET%^", destination);
    set_short("The body of Sasayaki");
    set_long("Sasayaki's body lies here, the broken sword of Asmodeus laying at his side.");
    set_prevent_get("It is very disrespectful to move the bodies of the dead.");
    call_out("kill10", 10);
}

int kill10(){
    message("say", "%^BOLD%^%^BLACK%^With a scream of rage, Asmodeus's spirit is blown away by the wind, scattered as his power is lost.%^RESET%^", destination);  call_out("kill11", 10);
    present("asmodeus", environment(this_object()))->move("/d/nopk/standard/void.c");
}

int kill11(){
    message("say", "%^BOLD%^%^BLACK%^All is quiet for a time. Then a very faint light shines from the hilt of the broken weapon.%^RESET%^", destination);
    call_out("kill12", 10);
}

int kill12(){
    message("say", "%^BOLD%^%^YELLOW%^The light grows in intensity, reaching almost blinding levels. Then, as abrumptly as it began, it stops. Two ghostly figures hover above the broken blade; a dragon-shaped spectre, clearly Venenum, and another; a human with a pair of large eagle wings, beautiful pale skin, and a bright gold halo above his head. And Sasayaki's face. The former drifts slowly back towards the centre of the city, while the latter slowly disappears, returning to the heavens where he belongs.%^RESET%^", destination);
    call_out("kill13", 10);
}

int kill13(){
    message("say", "%^BOLD%^%^WHITE%^A bright white light shines down upon the body of Venenum. His spirit hovers nearby, observing the proceedings. A kind, female voice echos throughout the realm, her soft voice seeming to come from everywhere and nowhere at once; '%^GREEN%^Venenum the Red...%^WHITE%^' Venenum's body does not stir. '%^GREEN%^You escaped the Evil One's clutches, but his demise creates a power vacuum. Someone must step up and take his place. Your body will soon rise again, and you will live out your life... as an immortal.%^WHITE%^' There is a brief pause. '%^GREEN%^Venenum? Good luck.%^WHITE%^'%^RESET%^", destination);
    call_out("kill14", 10);
}

int kill14(){
    message("say", "%^BOLD%^%^WHITE%^Venenum's spirit slowly fades away, preparing to live his life as an immortal dragon.", destination);
}
