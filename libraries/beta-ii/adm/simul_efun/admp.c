//      /adm/simul_efun/archp.c
//      from the Nightmare mudlib
//      returns true if a player is an arch
//      created by Descartes of Borg 18 february 1993

int admp(object ob) {
    string who;

    if(!ob) return 0;

    if(!userp(ob)) return 0;
    who = (string)ob->query_name();
    if(!objectp(ob)) return 0;
    if(!wizardp(ob)) return 0;
    return (member_group(who, "superuser"));
}

object *wizards() {
   object *o = users(), *out=({});
   int i;
   i=sizeof(o);
   while(i--)
     if(wizardp(o[i])) out += ({ o[i] });
   return out;
}

