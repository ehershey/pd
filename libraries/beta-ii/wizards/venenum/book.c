#include <std.h>
#include <venenum.h>
inherit OBJECT;

// Primal Darkness, 2004.

// This code is copywrited to the Primal Darkness administration. This code 
// is subject to viewing privilage. If you are not a member of the Primal 
// Darkness administration, viewing this code without permission from staff
// will result in severe punishment on any port you play on and may be a
// crime. Cease reading now and report how you found this code to a Primal
// Darkness administrator. Those who view Primal Darkness code criminally 
// will be persecuted to the maximum extent possible by United States law.

// Once again, reading this code without permission MAY BE A CRIME.

// Created by Venenum, 2004.

// Changelog:

// 27/06/2004

// Updated looking at the cover.
// Added set_size routine, allowing for different sized books.
// Added entitle routine, allowing the player to change the title of books.
// The parse_contents routine has been removed as it is no longer needed; 
//   rather, a truncating method was discovered which nicely trims off the 
//   summaries for each page. Examine contents is now fully functional.
// This file completed changeover to an inherit file.
// Added 'examine usage' to the examine command.

// 26/06/2004

// Removed page 0 and page 1 (the cover and contents pages previously) so
//   as to make the page listings less confusing and to cut down on 
//   redundant text (IE text in page 1, contents). Pages now start at 1,
//   with contents and cover not being listed at all.
// Stopped array indexes being strings instead of integers.
// Fixed players being able to write more pages then there were pages in
//   the book.
// Made thumbing pages and reading pages display the page number to prevent 
//   confusion.
// Added an update_info() function, to be called whenever the short or long
//   of the book needs to be changed.
// Made examining add two spaces at the beginning of the first line of
//   written text for asthetic reasons.
// Fixed outdated syntax messages.
// Added a 500 character limit to written messages to prevent abuse.
// Fixed thumbing to pages which were strings, apart from 'back' and 'next'.
// Stopped players indexing values not in the array by disallowing them
//   from turning back from page 0 or forward from the maximum pages and
//   stopping them from reading pages which had nothing in them.
// Some work done on parse_contents. Still nonfunctional. Solution found,
//   however I can't impliment it- The character taken from the array must 
//   be converted into a string before the output string can accept it. How 
//   to do this is unknown to me at the present time.

// Known issues: parse_contents is still nonfunctional.

// 24/06/2004

// Read, write and turn functions renamed to examine, scribe and thumb.
// Functions now work in their basic form. New function added to read the
// contents page. Non functional at this stage (parse function is playing
// up).

// This file will become an inherit file for the MUD-wide book system. An
// example book will be made soon and this book converted into an inherit.
// Several functions added to facilitate this.

// 15/06/2004

// Project commenced. Read, write, turn functions added. Non-functional. 
// Global functions appear to be interfering.


string title = "Book";
string *pages= ({" "});
int currentpage = 1;
int maxpages = 20;

void create() {
    ::create();
    set_name("book");
    set_id( ({"book", title}) );
    set_short("'"+title+"', "+(sizeof(pages)-1)+"/"+maxpages+" pages.");
    set_long(pages[0]+"\n \n 'examine usage' for usage.");
    set_mass(1);
    set_value(0);
}

void init() 

{
    ::init();
    add_action("thumb_page", "thumb");
    add_action("examine_page", "examine");
    add_action("scribe_page", "scribe");
    add_action("entitle_book", "entitle");

}


int thumb_page(string str) {

    int i;

    if (!str || str == "") {write("Thumb what? Book usage: <thumb page>, <thumb back>, <thumb #>"); return 1;}
    if (str == "page" && currentpage == maxpages){write("You are at the end of the book."); return 1;}
    if (str == "page" && currentpage == (sizeof(pages)-1)){write("The rest of the pages are blank."); return 1;}
    if (str == "page" && currentpage < maxpages){currentpage++; write("You thumb the page over to page "+currentpage+"."); return 1;}
    if (str == "back" && currentpage == 1){write("This is the first page in the book."); return 1;}
    if (str == "back" && currentpage > 0){currentpage--; write("You flick back a page to page "+currentpage+"."); return 1;}

    if (atoi(str) != 0)
    {
	if (i <= maxpages && i > 0)
	{
	    i = atoi(str);
	    write("You turn to page "+i+".");
	    currentpage = i;
	    return 1;
	}
	else if (i <= 0)
	{
	    write("That page doesn't exist.");
	    return 1;
	}
	else
	{
	    write("That page is blank.");
	}
    }
    else
    {
	write ("You must thumb to a page number which is an integer or direction. Book usage: <thumb page>, <thumb back>, <thumb #>");
	return 1;
    }
}

int examine_page(string str) {

    int i;
    int length;
    string output = "   |";
    string temp;

    if (!str || str == "") {write("Examine what?"); return 1;}
    if (str == "book"){write("Useage: <examine page>, <examine cover>, <examine contents>"); return 1;}
    if (str == "usage")
    {    if (!str || str == "") {write("Thumb what? Book usage: <thumb page>, <thumb back>, <thumb #>"); return 1;}
	write("       Usage: \n");
	write("   <examine page> - This reads the page the book is open to.");
	write("   <examine cover> - This reads the cover of the book.");
	write("   <examine contents> - This displays the contents of the book with a summary of the pages within.\n");
	write("   <thumb page> - This turns to the next page in the book. You cannot turn to blank pages.");
	write("   <thumb back> - This turns to the previous page in the book. You cannot turn beyond the first page (obviously).");
	write("   <thumb #> - This takes you to the page number specified. \n");
	write("   <scribe (text)> - This writes the text onto a fresh page of the book. Note that there are limited pages for each book. \n");
	write("   <entitle (text)> - This sets the title of the book.");
    }
    if (str == "cover")
    {

	message("cover", "\n    ___________________________", this_player());
	message("cover", "   |    _                      |\\", this_player());
	message("cover", "   |__.' |                     ||\\", this_player());
	message("cover", "   |    O \\                    |||\\", this_player());
	message("cover", "   |__  O /                    |||||", this_player());
	message("cover", "   |  '._|                     |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());

	temp = strlen(title)/2;

	if (temp*2 == strlen(title))
	{
	    output += " ";
	}

	for(i=0;i<((25-strlen(title))/2);i++)
	{
	    output += " ";
	}

	output += "'"+title+"'";

	for(i=0;i<((25-strlen(title))/2);i++)
	{
	    output += " ";
	}
	output += "|||||";
	message("cover", output, this_player());                     
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |                           |||||", this_player());
	message("cover", "   |    _                      |||||", this_player());
	message("cover", "   |__.' |                     |||||", this_player());
	message("cover", "   |    O \\                    |||||", this_player());
	message("cover", "   |__  O /                    |||||", this_player());
	message("cover", "   |  '._|                     |||||", this_player());
	message("cover", "   |___________________________|||||", this_player());
	message("cover", "    \\===========================\\|||", this_player());
	message("cover", "     \\===========================\\||", this_player());
	message("cover", "      '============================'", this_player());
	return 1;
    }
    if (str == "contents")
    {
	read_contents();
	return 1;
    }
    else if (str == "page")
    {
	message("page", "Page ("+currentpage+"), '"+title+"' \n", this_player());
	message("page", "  "+pages[currentpage], this_player());
	return 1;
    }
    else
    {
	write("Examine what?"); return 1;
    }
}

int read_contents() {

    int i;
    string temp;

    message("title", "     '"+title+"'\n \n", this_player());
    message("contents", "  ( ) - Cover Page", this_player());
    message("contents", "  ( ) - Contents Page", this_player());
    for (i=1;i<sizeof(pages);i++)
    {
	temp = pages[i][0..24];
	message("contents", "  ("+i+") - "+temp, this_player());
    }
    message("end", "    -----", this_player());
    message("end", "\n  "+(sizeof(pages)-1)+" of "+maxpages+" used.", this_player());
    return 1;
}

int scribe_page(string str) {

    if (!str || str == "") {write("Write what? Book usage: <scribe (text)>. Text is automatically appended to the last page of the book."); return 0;}
    if ((sizeof(pages)-1) == maxpages) {write("There are no pages left in this book, it is full."); return 1;}
    if (strlen(str) > 500) {write("Your pages are not that large! Try a smaller message, or break up the message into several pages. The maximum number of characters on a page is five hundred, including spaces and punctunation."); return 1;}
    message("writing", "You write "+str+" into the book.", this_player());
    pages += ({str});
    update_info();
}

int entitle_book(string str) {

    if (!str || str == "") {write("Title your book what? Entitle usage: <entitle (title)>."); return 0;}
    if (strlen(str) > 25) {write("You cannot title a book that long."); return 1;}
    message("titling", "You title your book, '"+str+"'.", this_player());
    title = str;
    update_info();
}

int set_title(string str) {

    title = str;
    update_info();

}

int add_page(string str) {

    pages += ({str});
    update_info();

}

int update_info() {

    set_short("'"+title+"', "+(sizeof(pages)-1)+"/"+maxpages+" pages.");
    set_long(pages[0]+"\n \n 'examine usage' for usage.");
    set_id( ({"book", title}) );

}

int set_size(string str) {

    if (str == "tiny")
    {
	if ((sizeof(pages)-1) > maxpages)
	{
	    return 0;
	}
	else
	{
	    int maxpages = 5;
	    update_info();
	    return 1;
	}
    }

    if (str == "small")
    {
	if ((sizeof(pages)-1) > maxpages)
	{
	    return 0;
	}
	else
	{
	    int maxpages = 20;
	    update_info();
	    return 1;
	}
    }

    if (str == "medium")
    {
	if ((sizeof(pages)-1) > maxpages)
	{
	    return 0;
	}
	else
	{
	    int maxpages = 50;
	    update_info();
	    return 1;
	}
    }

    if (str == "large")
    {
	if ((sizeof(pages)-1) > maxpages)
	{
	    return 0;
	}
	else
	{
	    int maxpages = 100;
	    update_info();
	    return 1;
	}
    }

    if (str == "tome")
    {
	if ((sizeof(pages)-1) > maxpages)
	{
	    return 0;
	}
	else
	{
	    int maxpages = 150;
	    update_info();
	    return 1;
	}
    }
}
