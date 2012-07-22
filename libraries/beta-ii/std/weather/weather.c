// Carnage weather daemon, by Inferno
#include <std.h>
#include <daemons.h>
#define PER 100

inherit ROOM;
inherit DAEMON;

string *MESSAGE = ({ "Thunder cracks off in the distance.",
"You see the flicker of lightning out of the corner of your eye.",
"A mighty boom of thunder rattles your bones.",
"The rumble of thunder rolls across the land.",
"The sizzle-CRASH of lightning sounds nearby.",
"The thunder rolled, and the lightning crashed...",
"A jag of lightning tears the sky asunder.",
"A distant lightning bolt is followed by a rippling wave of thunder."
});
string *HEAT_MESS = ({ "A wave of heat comes over you.",
"The air begins to wave and flicker in the heat.",
"The sun beats down upon your body.",
"The dry air chokes you."
});
string *RAIN_MESS = ({ "A light drizzle of rain patters down about you.",
"The rain stops for a brief moment, then starts back up.",
"The cool rain drenches your body.",
"Rain falls down on your head.",
"The warm humidity of the rain presses confortingly against you."
});
string *COLD_MESS = ({ "Cold winds chill your blood.",
"The horrid frost nips at your skin.",
"Your body goes numb for a minute from the cold.",
"The wind blows across you like a whip.",
"The air seems to grow even colder!"
});
string *CLOUDY_MESS = ({ "A cool wind blows refreshingly past you.",
"The clouds cast a temporary shadow over you.",
"A warm breeze blows through your hair."
});
string *CHAOS_MESS = ({ "A tornado suddenly appears, then blows out of the room!",
"A mighty earthquake shakes the land!",
"Drops of blood fall from the sky.",
"You suddenly become very dizzy.",
"A mighty hurricane throws you to the ground!",
"You become very hot, then suddenly very cold.",
"The air begins to fly about you, like a whirlpool!"
});

private static int going;

void do_weather();
void stop_weather();
void set_weather(string str, int i);
void start_weather();

void set_weather(string str, int i) {
   if (!i || !str) return;
   set_property(str, i);
}

void create() {
 ::create();
   set_no_clean(1);
   if (!going) {
      going = 1;
//      call_out("start_weather",TIME);
   set_heart_beat(5);
    }
}

void do_weather() {
   int i, x;
    for(i = 0;i < sizeof(users());i++) {
        if((environment(users()[i])->query_property("thunder"))) {
            if (random(PER) < 
                environment(users()[i])->query_property("thunder")) {
              x = random(sizeof(MESSAGE)-1);
              message("info","%^YELLOW%^"+MESSAGE[ x ],users()[i]);
            }
        }
        if((environment(users()[i])->query_property("heat")) &&
           (interactive(users()[i]))) {
            if (random(PER) <
                environment(users()[i])->query_property("heat")) {
              x = random(sizeof(HEAT_MESS)-1);
              message("info","%^ORANGE%^"+HEAT_MESS[ x ],users()[i]);
            }
        }
        if((environment(users()[i])->query_property("rain")) &&
           (interactive(users()[i]))) {
            if (random(PER) <
                environment(users()[i])->query_property("rain")) {
              x = random(sizeof(RAIN_MESS)-1);
              message("info","%^BOLD%^%^CYAN%^"+RAIN_MESS[ x ],users()[i]);
            }
        } 
        if((environment(users()[i])->query_property("cold")) &&
           (interactive(users()[i]))) {
            if (random(PER) <
                environment(users()[i])->query_property("cold")) {
              x = random(sizeof(COLD_MESS)-1);
              message("info","%^BLUE%^"+COLD_MESS[ x ],users()[i]);
            }
        }
        if((environment(users()[i])->query_property("cloudy")) &&
           (interactive(users()[i]))) {
            if (random(PER) < 
                environment(users()[i])->query_property("cloudy")) {
              x = random(sizeof(CLOUDY_MESS)-1);
              message("info","%^BLUE%^"+CLOUDY_MESS[ x ],users()[i]);
            }
        }
        if((environment(users()[i])->query_property("chaos")) &&
           (interactive(users()[i]))) {
            if (random(PER) <
                environment(users()[i])->query_property("chaos")) {
              x = random(sizeof(CHAOS_MESS)-1);
              message("info","%^BOLD%^%^BLACK%^"+CHAOS_MESS[ x ],users()[i]);
            }
        }
    }
}

void heart_beat() {
   do_weather();
}

/*
void weather_timer() {
    if(going == 0) {
        do_weather();
        call_out("weather_timer", TIME);
    }
}

void stop_weather() {
    going = 1;
}

void start_weather() {
    if(going) {
        going = 0;
        call_out("weather_timer",TIME);
    }
}
*/
