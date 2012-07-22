#include <clock.h>
#include <daemons.h>
#include <bank.h>
#include <dirs.h>
#include <security.h>

#define TREASURY_D "/daemon/treasury.c"
#define SAVE_FILE DIR_DAEMONS_SAVE + "/guild_dues"
#define BUG_FILE DIR_DAEMONS_SAVE + "/guild_dues_bugs"
#define DUES_AMOUNT 10000

#define ALIGN_LEFT 0
#define ALIGN_CENTER 1
#define ALIGN_RIGHT 2

#define BU "%%^BLUE%%^"
#define RT "%%^RESET%%^"
#define GR "%%^BOLD%%^%%^GREEN%%^"
#define RD "%%^BOLD%%^%%^RED%%^"

mapping payments;

int organize_records();
int purge_records();
int list_guilds(string);

int cmd_guilddues(string str)
{
    string dummy;
    
    if( !wizardp(this_player()) )
        return 0;
    
    if( !str || (str != "organize" && str != "purge" && str[0..3] != "list") )
    {
        return notify_fail("Syntax:\n" +
                "guilddues list [guild]\n" +
                "Lists payments for the current mud month for all guilds, " +
                "or payments for the last mud year for the specified guild.\n" +
                "\n" +
                "guildues organize\n" +
                "Fills in missing months for the current year and last mud " +
                "year with 0's.\n" +
                "\n" +
                "guilddues purge\n" +
                "Purges records for nonexistent guilds, and all years beyond " +
                "the current and last mud years for existing guilds.\n");
    }
    
    if( str == "organize" )
        return organize_records();
    else if( str == "purge" )
        return purge_records();
    else
    {
        sscanf(str, "list %s", dummy);
        return list_guilds(dummy);
    }
    
    return notify_fail("Something went horribly wrong.\n");
}

int organize_records()
{
    message("info", "This aspect of the command is not yet coded.",
            this_player());
    return 1;
}

int purge_records()
{
    message("info", "This aspect of the command is not yet coded.",
            this_player());
    return 1;
}

int list_guilds(string guild)
{
    int year = EVENTS_D->query_year(time());
    int mo = EVENTS_D->query_month(time()) - 1;
    
    if( !wizardp(this_player()) )
        return 0;
    
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
    
    if( !sizeof(guild) )
    {
        string* guilds = keys(payments);
        int i = sizeof(guilds);
        //string amt;
        int amt;
        string tmp = "" + EVENTS_D->query_day_of_month(time()) + " " +
                MONTHS[mo] + " " + year;
        
        if( !i )
            return notify_fail("No guilds have made payments.\n");
        
        message("info", sprintf(BU "+%26'-'s+" RT, "", ""), this_player());
        message("info", sprintf(BU "|" RT "%|26s" BU "|" RT, tmp),
                this_player());
        message("info", sprintf(BU "+%15'-'s+%10'-'s+" RT, "", ""), this_player());
        
        while( i-- )
        {
            if( !payments[guilds[i]] || !payments[guilds[i]][year] ||
                    !payments[guilds[i]][year][mo] )
            {
                amt = 0;
            }
            else
            {
                amt = payments[guilds[i]][year][mo];
            }

            
            if( amt )
                message("info", sprintf(BU "|" RT "%-15s" BU "|" GR "%10d" RT
                        BU "|", capitalize(guilds[i]), amt), this_player());
            else
                message("info", sprintf(BU "|" RT "%-15s" BU "|" RD "%10d" RT
                        BU "|", capitalize(guilds[i]), amt), this_player());
        }
        
        message("info", sprintf(BU "+%15'-'s+%10'-'s+" RT, "", ""),
                this_player());
    }
    else
    {
        int i;
        
        if( !payments || !payments[guild] )
            return notify_fail("There is no information for that guild.\n");
        
        if( !(payments[guild][year-1]) )
        {
            message("info", "No payments made for the year " + (year-1) + ".",
                    this_player());
        }
        else
        {
            int amt = 0;
            
            message("info", sprintf(BU "+%26'-'s+" RT, "", ""), this_player());
            message("info", sprintf(BU "|" RT "%|26s" BU "|" RT,
                    "Year " + (year-1)), this_player());
            message("info", sprintf(BU "+%15'-'s+%10'-'s+" RT, "", ""),
                    this_player());
            
            for(i = 0; i < 10; i++)
            {
                amt = payments[guild][year-1][i];
                if( amt )
                {
                    message("info", sprintf(BU "|" RT "%-15s" BU "|" GR "%10d"
                            RT BU "|", MONTHS[i], amt), this_player());
                }
                else
                {
                    message("info", sprintf(BU "|" RT "%-15s" BU "|" RD "%10d"
                            RT BU "|", MONTHS[i], amt), this_player());
                }
            }
            
            message("info", sprintf(BU "+%15'-'s+%10'-'s+\n" RT, "", ""),
                    this_player());
        }
        
        if( !(payments[guild][year]) )
        {
            message("info", "No payments made for the year " + year + ".",
                    this_player());
        }
        else
        {
            int amt = 0;
            
            message("info", sprintf(BU "+%26'-'s+" RT, "", ""), this_player());
            message("info", sprintf(BU "|" RT "%|26s" BU "|" RT,
                    "Year " + year), this_player());
            message("info", sprintf(BU "+%15'-'s+%10'-'s+" RT, "", ""),
                    this_player());
            
            for(i = 0; i < (mo+1); i++)
            {
                amt = payments[guild][year][i];
                if( amt )
                {
                    message("info", sprintf(BU "|" RT "%-15s" BU "|" GR "%10d"
                            RT BU "|", MONTHS[i], amt), this_player());
                }
                else
                {
                    message("info", sprintf(BU "|" RT "%-15s" BU "|" RD "%10d"
                            RT BU "|", MONTHS[i], amt), this_player());
                }
            }
            
            message("info", sprintf(BU "+%15'-'s+%10'-'s+\n" RT, "", ""),
                    this_player());
        }
    }
    
    return 1;
}

