inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "staff";
    short = "staff";
    long = "staff (PS Your guild leaders are lazy!)";
    id = ({"staff"});
    type = "blade";
    wield = "You wield the staff.";
    unwield = "You unwield the staff.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}
