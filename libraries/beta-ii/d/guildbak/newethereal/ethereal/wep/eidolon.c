inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "eidolon";
    short = "eidolon";
    long = "eidolon (PS Your guild leaders are lazy!)";
    id = ({"eidolon"});
    type = "blade";
    wield = "You wield the eidolon.";
    unwield = "You unwield the eidolon.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}
