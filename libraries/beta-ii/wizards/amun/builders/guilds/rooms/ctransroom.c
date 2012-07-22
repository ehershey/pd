#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("Inside a Coach");
    set_long("%^RESET%^%^ORANGE%^The coach is small but can comfortably sit one passenger. The sound of the horse pulling the coach fills the enclosed room. Bits and pieces of the land being passed can be seen through the small windows on each side of the coach.%^RESET%^");
    set_smell("default", "The smell of nature watfs through the room.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"no magic" : 1,
	"indoors" : 1,
	"outdoors" : 0,
	"no kill" : 1,
	"no attack" : 1,
	"no bump" : 1,
	"no steal" : 1
      ]));
}

int start_fmv(string str)
{
    write("The coach driver hops up onto his seat and takes off down the path.");
    destination = str;
    switch (destination) {
    case "town":
	time = 9;
	call_out("town1", time);
	break;
    case "helgrath":
	time = 9;
	call_out("helgrath1", time);
	break;
    case "tenebrae":
	time = 9;
	call_out("tenebrae1", time);
	break;
    case "lodos":
	time = 10;
	call_out("lodos1", time);
	break;
    case "roston":
	time = 10;
	call_out("roston1", time);
	break;
    case "citrin":
	time = 17;
	call_out("citrin1", time);
	break;
    case "desert":
	time = 9;
	call_out("desert1", time);
	break;
    }


}
int town1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("town2", time);
}

int town2()
{
    write("%^ORANGE%^Animals run along the path as the coach moves on along the path.%^RESET%^");
    call_out("town3", time);
}

int town3()
{
    write("%^ORANGE%^The animals run into the depths of the forest as the Town comes into view.%^RESET%^");
    call_out("town4", time);
}

int town4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"coaches.c");
    return 1;
}
int helgrath1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("helgrath2", time);
}

int helgrath2()
{
    write("%^ORANGE%^The forest path is hard to see, it's as if the path is not even there.%^RESET%^");
    call_out("helgrath3", time);
}

int helgrath3()
{
    write("%^ORANGE%^The path clears slightly, showing the city of Helgrath just up ahead. %^RESET%^");
    call_out("helgrath4", time);
}

int helgrath4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"hel_holding.c");
    return 1;
}

int tenebrae1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("tenebrae2", time);
}

int tenebrae2()
{
    write("%^ORANGE%^The sky above begins to blacken as if a curse has been placed upon them. The horses begin to buck, but the drivers gets control of them.%^RESET%^");
    call_out("tenebrae3", time);
}

int tenebrae3()
{
    write("%^ORANGE%^With not a cloud in the sky, the sky grows a deeper black as the city of Tenebrae comes into view.%^RESET%^");
    call_out("tenebrae4", time);
}

int tenebrae4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"tene_holding.c");
    return 1;
}

int lodos1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("lodos2", time);
}

int lodos2()
{
    write("%^ORANGE%^The neat path widens into a comfortable, roomy, street. A soft breeze flows through the window.%^RESET%^");
    call_out("lodos3", time);
}

int lodos3()
{
    write("%^ORANGE%^As the city of Lodos comes into view, the coach begins to slow down.%^RESET%^");
    call_out("lodos4", time);
}

int lodos4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"lodos_holding.c");
    return 1;
}

int roston1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("roston2", time);
}

int roston2()
{
    write("%^ORANGE%^Patches of snow lay across the path. A chilly breeze flows through the coach.%^RESET%^");
    call_out("roston3", time);
}

int roston3()
{
    write("%^ORANGE%^Large mountains topped with snow can be seen in the distance. Just below it, the city of Roston sits.%^RESET%^");
    call_out("roston4", time);
}

int roston4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"roston_holding.c");
    return 1;
}

int citrin1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("citrin2", time);
}

int citrin2()
{
    write("%^ORANGE%^The forest closes in on the coach, leaving the path small and hard to move on.%^RESET%^");
    call_out("citrin3", time);
}

int citrin3()
{
    write("%^ORANGE%^The driver snaps his reigns wanting the horses to speed up. The city of Citrin is just ahead.%^RESET%^");
    call_out("citrin4", time);
}

int citrin4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"citrin_holding.c");
    return 1;
}
int desert1()
{
    write("%^ORANGE%^The coach takes off at a brisk pace, as if trying to get rid of it's contents quickly.%^RESET%^");
    call_out("desert2", time);
}

int desert2()
{
    write("%^ORANGE%^The path becomes sandy as a scorpion climbs up the side of the carriage.%^RESET%^");
    call_out("desert3", time);
}

int desert3()
{
    write("%^ORANGE%^The horses speed up on their own accord, wanting to leave this area quickly.  Just up ahead is the Desert.%^RESET%^");
    call_out("desert4", time);
}

int desert4()
{
    write("%^ORANGE%^The coach pulls into the station and you are politely escorted from your seat.%^RESET%^");
    this_player()->move(GROOM"desert_holding.c");
    return 1;
}
