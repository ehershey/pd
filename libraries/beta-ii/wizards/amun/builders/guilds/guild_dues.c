#include <std.h>
#include <clock.h>
#include <bank.h>
#include <daemons.h>
#include <security.h>
#include <dirs.h>

#define TREASURY_D "/daemon/treasury.c"
#define SAVE_FILE DIR_DAEMONS_SAVE + "/guild_dues"
#define BUG_FILE DIR_DAEMONS_SAVE + "/guild_dues_bugs"
#define DUES_AMOUNT 2000
#define WITHDRAW 2

mapping payments;

int cmd_pay(string str)
{
    int year;
    int mo;
    string month;
    string guild;
    int error;

    if( !this_player()->query_guild() )
	return 0;

    if( this_player()->query_guild_position() != "main" )
    {
	return 0;
    }

    if( !str || str != "dues" )
	return notify_fail("Pay what?\n");

    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());

    year = EVENTS_D->query_year(time());
    mo = EVENTS_D->query_month(time()) - 1;
    month = MONTHS[mo];
    guild = (string)(environment(this_player())->query_guild());

    if( !sizeof(guild) )
	return notify_fail("You must be in your treasury to do that.\n");

    if( !payments )
	payments = ([]);

    if( !payments[guild] )
	payments[guild] = ([]);

    if( !payments[guild][year] )
	payments[guild][year] = ([]);

    if( !payments[guild][year][mo] )
    {
	error = TREASURY_D->withdraw(this_player()->query_name(), guild,
	  DUES_AMOUNT, "gold");
	switch( error )
	{
	case INSF:
	    return notify_fail("You need at least " + DUES_AMOUNT
	      + " gold in your treasury.\n");
	    break;
	case NO_ACCOUNT:
	    return notify_fail("Your guild doesn't have a treasury!\n");
	    break;
	case BAD_ACCESS:
	    return notify_fail("You don't have access to the guild's " +
	      "treasury!\n");
	    break;
	case TRANSACTION_OK:
	    payments[guild][year][mo] = DUES_AMOUNT;
	    message("info", "You have paid your dues for " +
	      capitalize(month) + ".", this_player());
	    seteuid(UID_DAEMONSAVE);
	    save_object(SAVE_FILE);
	    seteuid(getuid());
	    TREASURY_D->update_summary(
	      this_player()->query_original_guild(),
	      "Guild dues", "gold", DUES_AMOUNT);
	    environment(this_player())->do_scroll_write(
	      capitalize(this_player()->query_name()) + " (dues)",
	      WITHDRAW, DUES_AMOUNT, "gold");
	    return 1;
	    break;                
	default:
	    /* Edit eventually to log the error */
	    return notify_fail("An error occured; please contact an " +
	      "Admin.\n");
	    break;
	}
    }
    else
    {
	return notify_fail("Your dues have already been paid for this month.\n");
    }
    return 0;
}
