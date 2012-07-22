// Nesoo, 05/02/2005
// beta verion :)

#include <std.h>

inherit DAEMON;

int help();

int cmd_equipment(string str)
{
    string msg = "";
    
    if( !str )
    {
        object* weps = ({});
        string* limbs = ({});
        object* inv = all_inventory(this_player());
        
        for(int i = 0; i < sizeof(inv); i++)
        {
            if( inv[i]->query_worn() )
                msg += (inv[i]->query_short() + "\n");
        }
        
        if( msg != "" )
            msg = "You are wearing:\n" + msg;
        
        limbs = this_player()->query_limbs();
        
        for(int i = 0; i < sizeof(limbs); i++)
        {
            if( this_player()->query_weapon(limbs[i]) )
                weps += ({ this_player()->query_weapon(limbs[i]) });
        }
        
        if( sizeof(weps) > 0 )
        {
            if( msg != "" )
                msg += "\n";
            msg += "You are wielding:\n";
            for(int i = 0; i < sizeof(weps); i++)
            {
                msg += weps[i]->query_short() + "\n";
            }
        }
        
        if( msg == "" )
            msg = "You aren't wearing anything!";
    }
    else if( str == "limbs" )
    {
        string* limbs = this_player()->query_limbs();
        string* tmp = ({ });
        object* arms;
        
        for(int i = 0; i < sizeof(limbs); i++)
        {
            arms = this_player()->query_armour_ob(limbs[i]);
            tmp = ({ });
            
            for(int j = 0; j < sizeof(arms); j++)
            {
                tmp += ({ arms[j]->query_short() });
            }
            
            if( sizeof(tmp) > 0 )
            {
                msg += ("%^BOLD%^%^RED%^[" + capitalize(limbs[i]) +
                        "]%^RESET%^\n");
                if( sizeof(tmp) > 1 )
                    msg += (implode(tmp, ", "));
                else if( sizeof(tmp) == 1 )
                    msg += (tmp[0]);
                msg += "\n\n";
            }
        }
        
        if( msg == "" )
            msg = "You aren't wearing anything!";
    }
    else if( member_array(str, this_player()->query_limbs()) != -1 )
    {
        object* arms = ({ });
        string* tmp = ({ });
        
        arms = this_player()->query_armour_ob(str);
        
        for(int i = 0; i < sizeof(arms); i++)
        {
            tmp += ({ arms[i]->query_short() });
        }
        
        if( sizeof(tmp) > 0 )
            msg = "%^BOLD%^%^RED%^[" + capitalize(str) +
                    "]%^RESET%^\n" + implode(tmp, ", ") + "\n";
        else
            msg = "You aren't wearing anything on that limb.";
    }   
    else
    {
        return notify_fail("Syntax: <equipment>, <equipment limbs>, or <equipment [limb]>\n");
    }
    
    message("info", msg, this_player());

    return 1;
}

int help()
{
    message("info", "Command: equipment\n\n" +
        "Syntax: <equipment>\n" +
        "Displays a list of all worn and wielded equipment.\n\n" +
        "Syntax: <equipment limbs>\n" +
        "Displays all armour worn on each limb.\n\n" +
        "Syntax: <equipment [limb]>\n" +
        "Displays all armour worn on the specified limb.\n", this_player());
    return 1;
}

