#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passengerCC
{
    char name[100];
    long int mobNo;
};

struct passengerEC
{
    char name[100];
    long int mobNo;
    char foodType;
};

struct CCcoach
{
    struct passengerCC passengerCCArray[10];
    int seatsFullCC;
    int vacantCC;
    struct CCcoach *nextCC;
    struct ECcoach *nextEC;
    char coachName[10];
};

struct ECcoach
{
    struct passengerEC passengerECArray[5];
    int seatsFullEC;
    int vacantEC;
    struct CCcoach *nextCC;
    struct ECcoach *nextEC;
    char coachName[10];
};

struct head
{
    char name[20];
    long int regNo;
    int ccNos;
    int ecNos;
    struct CCcoach *nextCC;
    struct ECcoach *nextEC;
};

int main()
{
    // making the structre of the train and linking the coaches

    // making and initializing the engine node
    struct head *engine = (struct head *)malloc(sizeof(struct head));
    strcpy(engine->name, "Ajay Rajendra Kumar");
    engine->regNo = 200905390;
    engine->ccNos = 3;
    engine->ecNos = 2;
    engine->nextCC = NULL;
    engine->nextEC = NULL;

    // first CC node
    struct CCcoach *cc1 = (struct CCcoach *)malloc(sizeof(struct CCcoach));
    // initializing
    cc1->seatsFullCC = 0;
    cc1->vacantCC = 10;
    cc1->nextCC = NULL;
    cc1->nextEC = NULL;
    strcpy(cc1->coachName, "CC1");
    // link the engine with cc1
    engine->nextCC = cc1;
    // fill the passengers

    // second CC node
    struct CCcoach *cc2 = (struct CCcoach *)malloc(sizeof(struct CCcoach));
    // initializing
    cc2->seatsFullCC = 0;
    cc2->vacantCC = 10;
    cc2->nextCC = NULL;
    cc2->nextEC = NULL;
    strcpy(cc1->coachName, "CC2");
    // link cc2 with cc1
    cc1->nextCC = cc2;
    // fill the passengers

    struct CCcoach *cc3 = (struct CCcoach *)malloc(sizeof(struct CCcoach));
    // initializing
    cc3->seatsFullCC = 0;
    cc3->vacantCC = 10;
    cc3->nextCC = NULL;
    cc3->nextEC = NULL;
    strcpy(cc3->coachName, "CC3");
    // link the cc3 with cc2
    cc2->nextCC = cc3;
    // fill the passengers

    struct ECcoach *ec1 = (struct ECcoach *)malloc(sizeof(struct ECcoach));
    // initializing
    ec1->seatsFullEC = 0;
    ec1->vacantEC = 5;
    ec1->nextCC = NULL;
    ec1->nextEC = NULL;
    strcpy(ec1->coachName, "EC1");
    cc2->nextEC = ec1;

    struct ECcoach *ec2 = (struct ECcoach *)malloc(sizeof(struct ECcoach));
    // initializing
    ec1->seatsFullEC = 0;
    ec1->vacantEC = 5;
    ec1->nextCC = NULL;
    ec1->nextEC = NULL;
    strcpy(ec1->coachName, "EC2");
    ec1->nextEC = ec2;

    // take the passenger details
    while (1)
    {
        int choice;
        printf("Enter choice: \n");
        printf("1. Add passenger\n");
        printf("2. Departure\n");
        printf("3. Charting\n");
        printf("4. exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int compChoice;
            printf("Enter compartment type: cc(1)/ec(2): ");
            scanf("%d", &compChoice);
            if (compChoice == 1)
            {
                // ask for cc
                char name[100];
                long int mob;
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the mobile number: ");
                scanf("%ld", &mob);
                if (cc1->seatsFullCC != 9)
                {
                    strcpy(cc1->passengerCCArray[cc1->seatsFullCC].name, name);
                    cc1->passengerCCArray[cc1->seatsFullCC].mobNo = mob;
                    cc1->seatsFullCC++;
                    cc1->vacantCC--;
                }
                else if (cc1->seatsFullCC == 9 && cc2->seatsFullCC != 9)
                {
                    strcpy(cc2->passengerCCArray[cc2->seatsFullCC].name, name);
                    cc2->passengerCCArray[cc2->seatsFullCC].mobNo = mob;
                    cc2->seatsFullCC++;
                    cc2->vacantCC--;
                }
                else if (cc1->seatsFullCC == 9 && cc2->seatsFullCC == 9 && cc3->seatsFullCC != 9)
                {
                    strcpy(cc3->passengerCCArray[cc3->seatsFullCC].name, name);
                    cc3->passengerCCArray[cc3->seatsFullCC].mobNo = mob;
                    cc3->seatsFullCC++;
                    cc3->vacantCC--;
                }
                else
                {
                    printf("No seats empty in Chair Car");
                    exit(0);
                }
            }
            if (compChoice == 2)
            {
                // ask for cc
                char name[100];
                long int mob;
                char food;
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the mobile number: ");
                scanf("%ld", &mob);
                printf("Enter food type: ");
                scanf("%c", &food);
                if (ec1->seatsFullEC != 4)
                {
                    strcpy(ec1->passengerECArray[ec1->seatsFullEC].name, name);
                    ec1->passengerECArray[ec1->seatsFullEC].mobNo = mob;
                    ec1->seatsFullEC++;
                    ec1->vacantEC--;
                }
                else if (ec1->seatsFullEC == 4 && ec2->seatsFullEC != 4)
                {
                    strcpy(ec2->passengerECArray[ec2->seatsFullEC].name, name);
                    ec2->passengerECArray[ec2->seatsFullEC].mobNo = mob;
                    ec2->seatsFullEC++;
                    ec2->vacantEC--;
                }
                else
                {
                    printf("Executive Chair Car is empty.");
                }
            }
        }
    }
    return 0;
}