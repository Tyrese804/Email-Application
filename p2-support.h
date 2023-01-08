#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20

#define user_email "whiteheadtj@vcu.edu"


struct Email
{
	char sender[ADDRESS_SIZE];
	char receiver[ADDRESS_SIZE];
	char subject[SUBJECT_SIZE];
	char body[BODY_SIZE];
	int id;
	struct sent_date{
		int month;
		int day;
		int year;
	}sentDate;

};

struct Mailbox
{
	int size;
	struct Email *emails;
	//add other struct members as needed
};

///////////////////////////////////////////////////////////////////////////////

// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void

void initialize(struct Mailbox *ib);

// Function     : display inbox menu
// Description  : displays an interactive menu for navigating the email client
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);

// Function     : create email
// Description  : Creates an Email in the emails array with the given inputs as members
// Inputs       : char *senderEmail(for sender member), char *receiverEmail(for receiver member), char *subject(for subject member), char *body(for body member), int month, day, year(for month, day, and year members), struct Mailbox *ib - pointer to the database
// Outputs      : void
void create_email(char *senderEmail, char *receiverEmail, char *subject, char *body, int month1, int day, int year, struct Mailbox *ib);

// Function     : show inbox
// Description  : prints out the emails in the emails array
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void showInbox(struct Mailbox *ib);

// Function     : show email by ID
// Description  : given an email ID, should print out the email with the matching ID
// Inputs       : struct Mailbox *ib - pointer to the database, int id(ID member to search for)
// Outputs      : void
void showEmailByID(int id, struct Mailbox *ib);

// Function     : exit email
// Description  : exits the program and frees memory
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void exitMail(struct Mailbox *ib);

// Function     : sort by sender
// Description  : sorts the email list lexicographically by the sender's email adress
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void sortBySender(struct Mailbox *ib);

// Function     : sort by ID
// Description  : sorts the email list by the ID from lowest to highest
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void sortByID(struct Mailbox *ib);

// Function     : ID comparator
// Description  : compares 2 IDs and returns an int based on which is greater
// Inputs       : 2 pointers to ID members in the email array
// Outputs      : -1, 1, or 0
int idcomparator(const void *x, const void *y);

// Function     : string comparator
// Description  : compares 2 strings and returns an int based on which is lexicographically greater
// Inputs       : 2 pointers to sender members in the emails array
// Outputs      : -1, 1, or 0
int stringcomparator(const void *x, const void *y);

// Function     : delete email
// Description  : deletes the email with the given ID from the emails array, updates the size of the mailbox and rearranges the emails array
// Inputs       : struct Mailbox *ib - pointer to the database, int id
// Outputs      : void
void deleteEmail(int id, struct Mailbox *ib);

// Function     : search keyword
// Description  : searches emails array and prints all emails that include the keyword within the sender, subject, or body
// Inputs       : struct Mailbox *ib - pointer to the database, shar *s(keyword)
// Outputs      : void
void searchKeyword(char *s, struct Mailbox *ib);
//add other function declarations as needed

#endif // CMSC257_P2SUPPORT_INCLUDED
