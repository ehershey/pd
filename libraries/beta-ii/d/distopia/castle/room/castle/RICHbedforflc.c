#include <discastle.h>
inherit ROOM;
void create()
{
        ::create();
        set_properties
        (
                (["light" : 2, "night light" : 1, "inside" : 1])
        );
        set_short("Mad Cow Tavern.");
        set_day_long
        (
        	"This bedroom is elaborate. Fine carpets and rugs are everywhere. "
        	"The plush, persian bed looks incredibly comfortable and certainly "
        	"very elaborate.  The room itself is painted in a splended green tint "
        	"that completes its royal treatment.  The only thing missing is the wealthy "
        	"occupant"
        );
        set_night_long
        (
			"The pale moonlight casts a glow through the curtains on the window "
			"the rythmic snoring of the merchant in bed is the only sound to be heard. "
			"He must have only recently gone to bed, a thin wisp of smoke marks a smoldering "
			"candle and a great ledger beside it probably filled with figures."
		);
        if (query_night())            
        {
	        set_listen("default", "Light snoring can be heard");
        }
        else
        {
        	set_listen("default", "Birds chirping can be faintly heard");
        }
        set_items
        (
                ([
                        "bed" : "Looks comfortable",
                        "windows" : "It's a window alright",
                        "window" : "Yup, still a window",
                        "curtains" : "Heavy curtains to block sunlight",
                        "candle" : "It's used to help people see better",
                        "dresser" : "It contains clothes and other worthless items",
                        "ledge" : "You're not a merchant, it means nothing to you",
                        "door" : "Good quailty oak"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innforflc2",
        ]));

}
void reset() 
{
	::reset();
		if(!present("merforfl") && query_night())
	{
		new(MOB"merforfl")->move(this_object());
	}
}
