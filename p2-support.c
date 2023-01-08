////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.c
// Description    : File for creating a menu driven email client that can display, sort and and search through given emails 
//         
// Author         : ***Tyrese Whitehead***
// Date           : ***11/5/2022***
// Notes          : ***11/4/2022 - finished writing all functions
//                  ***10/5/2022 - wrote function descriptions in .h file and made sure everything was neat  


////////////////////////////////////////////////////////////////////////




#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////
//
// Function Definitions
// //////////////////////////////////////////

void initialize(struct Mailbox *ib)
{
	//allocate memory for 2000 emails
	ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
	ib->size = 0;

	create_email("asonmez@mail.com", user_email, "Welcome to your inbox.",
			"Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
			11, 20, 2020, ib);
	create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
			"Yet another email just to pad out your inbox, have fun!",
			11, 30, 2020, ib);
	create_email("dboyle@mail.com", user_email, "3rd email!",
			"Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
			12, 2, 2020, ib);
	create_email("cbluer@mail.com", user_email, "4th email!",
			"Content of fourth email. More coding, more fun!",
			12, 8, 2020, ib);
	create_email("cboyle@mail.com", user_email, "5th email!",
			"Content of fifth email. Coding is fun-tastic!",
			12, 18, 2020, ib);
	create_email("sblack@mail.com", user_email, "6th email!",
			"Content of sixth email. Coding is fun-tastic!",
			1, 1, 2021, ib);
	create_email("sblack@mail.com", user_email, "7th email!",
			"Body of seventh email. Coding is fun-tastic!",
			1, 5, 2021, ib);
	create_email("sblack@mail.com", user_email, "8th email!",
			"Body of eighth email. Coding is fun-tastic!",
			2, 15, 2021, ib);
	create_email("sblack@mail.com", user_email, "9th email!",
			"Body of ninth email. Coding is fun-tastic!",
			2, 25, 2021, ib);
	create_email("dboyle@mail.com", user_email, "Last email!",
			"Body of tenth email. Coding is fun-tastic!",
			3, 15, 2021, ib);
}

//Other function definitions go below
//

void display_inbox_menu(struct Mailbox *ib){
	int loop;
	loop = 1;
	while(loop == 1){


		printf("***************   %s   ***************\n", user_email);
		printf("***************    Total Inbox: %04d    ***************\n", ib->size);
		printf("\n");
		printf("1. Show Inbox\n");
		printf("2. Show Email by ID\n");
		printf("3. Sort Inbox by Sender\n");
		printf("4. Sort Inbox by ID\n");
		printf("5. Search Inbox by Keyword\n");
		printf("6. Delete\n");
		printf("7. Exit Inbox\n\n");

		int option;
		scanf("%d", &option);
		printf("\n");

		switch(option){
			case 1:

				showInbox(ib);

				loop = 1;
				break;
			case 2:
				printf("Enter the ID of the email you want to read:\n");
				int userID;
				scanf("%d", &userID);
				showEmailByID(userID, ib);
				loop = 1;
				break;
			case 3:

				sortBySender(ib);

				loop = 1;
				break;
			case 4:
				sortByID(ib);
				loop = 1;
				break;
			case 5:
				printf("Enter the keyword you are searching for:\n");
				char key[BODY_SIZE];
				scanf("%s", key);
				printf("\n");
				searchKeyword(key, ib);
				loop = 1;
				break;
			case 6: 

				printf("Enter the ID of the e-mail you want to delete:\n");
				int case6;				
				scanf("%d", &case6);
				printf("\n");

				deleteEmail(case6, ib);
				loop = 1;
				break;
			case 7:
				exitMail(ib);
				loop = 0;

		}
	}
}


void create_email(char *senderEmail, char *receiverEmail, char *subject, char *body, int month1, int day, int year, struct Mailbox *ib){

	strcpy(ib->emails[ib->size].sender, senderEmail);
	strcpy(ib->emails[ib->size].receiver, receiverEmail);
	strcpy(ib->emails[ib->size].subject, subject);
	strcpy(ib->emails[ib->size].body, body);

	ib->emails[ib->size].sentDate.month = month1;
	ib->emails[ib->size].sentDate.day = day;
	ib->emails[ib->size].sentDate.year = year;

	ib->emails[ib->size].id = ib->size;
	ib->size += 1;
}


void showInbox(struct Mailbox *ib){
	printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   --------------------   --/--/----   ---------------\n");
	int i;
	for(i = 0; i < ib->size; i++){
		printf("%02d - %-20s - %02d/%02d/%04d - %.15s\n", ib->emails[i].id, ib->emails[i].sender, ib->emails[i].sentDate.month, ib->emails[i].sentDate.day, ib->emails[i].sentDate.year, ib->emails[i].subject);
	}
	printf("\n");
}


void showEmailByID(int id, struct Mailbox *ib){
	int i;
	for(i = 0; i < ib->size; i++){
		if(ib->emails[i].id == id){
			printf("%s - %s\n", ib->emails[i].sender, ib->emails[i].subject);
			printf("Email Received on: %02d/%02d/%04d\n\n", ib->emails[i].sentDate.month, ib->emails[i].sentDate.day, ib->emails[i].sentDate.year);
			printf("%s\n", ib->emails[i].body);
		}
	}



}


void exitMail(struct Mailbox *ib){
	free(ib->emails);
	printf("Exiting e-mail client - Good  Bye!\n");

}


int idcomparator(const void *x, const void *y){

	int x1 = ((struct Email *)x)->id;
	int y1 = ((struct Email *)y)->id;

	if(x1 < y1)
		return -1;
	if(x1 > y1)
		return 1;
	else
		return 0;


}


int stringcomparator(const void *x, const void *y){

	struct Email *x1 = (struct Email*)x;
	struct Email *y1 = (struct Email*)y;
	return strcmp(x1->sender, y1->sender);

}


void sortBySender(struct Mailbox *ib){

	qsort(ib->emails, ib->size, sizeof(struct Email), stringcomparator);
}


void sortByID(struct Mailbox *ib){

	qsort(ib->emails, ib->size, sizeof(struct Email), idcomparator);

}


void deleteEmail(int id, struct Mailbox *ib){

	int found;
	found = 0;
	int i;
	int j;

	for(i = 0; i < ib->size; i++){
		if(ib->emails[i].id == id){
			found++;
			for(j = i; j < ib->size-1; j++){

				ib->emails[j].id = ib->emails[j+1].id;
				strcpy(ib->emails[j].sender, ib->emails[j+1].sender);
				strcpy(ib->emails[j].receiver, ib->emails[j+1].receiver);
				strcpy(ib->emails[j].body, ib->emails[j+1].body);
				strcpy(ib->emails[j].subject, ib->emails[j+1].subject);

				ib->emails[j].sentDate.day = ib->emails[j+1].sentDate.day;
				ib->emails[j].sentDate.month = ib->emails[j+1].sentDate.month;
				ib->emails[j].sentDate.year = ib->emails[j+1].sentDate.year;
			}
			ib->size = ib->size-1;
		}
	}

	if(found == 0)
		printf("Email with ID = %d does not exist.\n\n", id);
	else
		printf("Email with ID = %d is deleted\n\n", id);

}


void searchKeyword(char *s, struct Mailbox *ib){
	int i;

	printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   --------------------   --/--/----   ---------------\n");
	for(i = 0; i < ib->size; i++){

		if(strstr(ib->emails[i].sender, s) != NULL || strstr(ib->emails[i].subject, s) != NULL || strstr(ib->emails[i].body, s) != NULL){

			printf("%02d - %-20s - %02d/%02d/%04d - %.15s\n", ib->emails[i].id, ib->emails[i].sender, ib->emails[i].sentDate.month, ib->emails[i].sentDate.day, ib->emails[i].sentDate.year, ib->emails[i].subject);
		}
	} 

}
