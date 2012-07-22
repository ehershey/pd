inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "tetsubo";
    short = "%^BOLD%^%^RED%^Te%^CYAN%^ts%^RED%^ub%^CYAN%^o%^RESET%^";
    long = "%^BOLD%^An Ancient Tetsubo from the Quing Dynasty. It has been modified %^BOLD%^with %^YELLOW%^golden-tipped spikes%^RESET%^%^BOLD%^ on the upper half, with the insignia of %^RED%^Forsaken";
    id = ({ "tetsubo", "blunt" });
    type = "blunt";
    wield = "%^BOLD%^%^YELLOW%^You're astounded that the Tetsubo weighs so much!%^RESET%^";
    unwield = "%^BOLD%^%^YELLOW%^You drop the Tetsubo with haste. Your wrists sting.%^RESET%^";
    guild = "forsaken";
    playerm = "%^BOLD%^%^YELLOW%^The spikes on the Tetsubo sinks into "+ob->query_cap_name()+"'s back!%^RESET%^";
    targetm = "%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+" roars as the spikes on "+this_player()->query_possessive()+"Tetsubo punctures your back down to the spine!%^RESET%^";
    roomm = "%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+" roars as the spikes on "+this_player()->query_possessive()+"Tetsubo punctures "+atk->query_cap_name()+"'s back down to the spine!%^RESET%^";
    return 1;
}
