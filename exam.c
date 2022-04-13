#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE 100
#define MAX_CC_SIZE 10
#define MAX_EC_SIZE 5

typedef struct {
    char name[MAX_ARRAY_SIZE];
    long int mobile;
}CC;

typedef struct {
    char name[MAX_ARRAY_SIZE];
    long int mobile;
    char food;
}EC;

typedef struct CCCoach* cc_coach_pointer;
typedef struct CCCoach {
    CC seats[MAX_CC_SIZE];
    cc_coach_pointer ccpointer;
    ec_coach_pointer ecpointer;
    char cc_coachnumber[MAX_ARRAY_SIZE];
    int occupied_cc_seats;
}CCCoach;

typedef struct ECCoach* ec_coach_pointer;
typedef struct ECCoach {
    EC seats[MAX_EC_SIZE];
    cc_coach_pointer ccpointer;
    ec_coach_pointer ecpointer;
    char ec_coachnumber[MAX_ARRAY_SIZE];
    int occupied_ec_seats;
}ECCoach;

typedef struct Engine* engine_pointer;
typedef struct Engine {
    char name[MAX_ARRAY_SIZE];
    long int regno;
    int cc_avail_coaches;
    int ec_avail_coaches;
    cc_coach_pointer ccpointer;
    ec_coach_pointer ecpointer;
}Engine;

int main() {

    engine_pointer head_engine;
    head_engine = (engine_pointer)malloc(sizeof(*head_engine));
    head_engine->name = "RYAN SOJAN";
    head_engine->regno = 200905396;
    head_engine->cc_avail_coaches = 3;
    head_engine->ec_avail_coaches = 2;

    cc_coach_pointer cc1;
    cc1 = (cc_coach_pointer)malloc(sizeof(*cc1));
    cc_coach_pointer cc2;
    cc2 = (cc_coach_pointer)malloc(sizeof(*cc2));
    cc_coach_pointer cc3;
    cc3 = (cc_coach_pointer)malloc(sizeof(*cc3));

    ec_coach_pointer ec1;
    ec1 = (ec_coach_pointer)malloc(sizeof(*ec1));
    ec_coach_pointer ec2;
    ec2 = (ec_coach_pointer)malloc(sizeof(*ec2));

    head_engine->ccpointer = cc1;
    head_engine->ecpointer = NULL;
    cc1->ccpointer = cc2;
    cc1->ecpointer = NULL;
    cc1->cc_coachnumber = "CC1";
    cc1->occupied_cc_seats = -1;
    cc2->ccpointer = cc3;
    cc2->ecpointer = NULL;
    cc2->cc_coachnumber = "CC2";
    cc2->occupied_cc_seats = -1;
    cc3->ccpointer = NULL;
    cc3->ecpointer = ec1;
    cc3->cc_coachnumber = "CC3";
    cc3->occupied_cc_seats = -1;
    ec1->ccpointer = NULL;
    ec1->ecpointer = ec2;
    ec1->ec_coachnumber = "EC1";
    ec1->occupied_ec_seats = -1;
    ec2->ccpointer = NULL;
    ec2->ecpointer = NULL;
    ec2->ec_coachnumber = "EC2";
    ec2->occupied_ec_seats = -1;

    int choice;
    int num;
    while(1) {
        printf("\n1: Chair Car Entry\n2: Executive Chair Car Entry\n3: Departure\n4: Charting");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            char name[MAX_ARRAY_SIZE];
            int mobile;
            printf("Enter number of entries: ");
            scanf("%d",&num);
            for(int i=0;i<num;i++) {
                if(cc1->occupied_cc_seats<MAX_CC_SIZE-1) {
                    printf("Enter name: ");
                    scanf("%s",name);
                    printf("Enter mobile number: ");
                    scanf("%ld",&mobile);
                    cc1->occupied_cc_seats = cc1->occupied_cc_seats + 1;
                    cc1->seats[cc1->occupied_cc_seats].name = name;
                    cc1->seats[cc1->occupied_cc_seats].mobile = mobile;
                }
                else {
                    if(cc2->occupied_cc_seats<MAX_CC_SIZE-1) {
                        printf("Enter name: ");
                        scanf("%s",name);
                        printf("Enter mobile number: ");
                        scanf("%ld",&mobile);
                        cc2->occupied_cc_seats = cc2->occupied_cc_seats + 1;
                        cc2->seats[cc2->occupied_cc_seats].name = name;
                        cc2->seats[cc2->occupied_cc_seats].mobile = mobile;
                    }
                    else {
                        if(cc3->occupied_cc_seats<MAX_CC_SIZE-1) {
                            printf("Enter name: ");
                            scanf("%s",name);
                            printf("Enter mobile number: ");
                            scanf("%ld",&mobile);
                            cc3->occupied_cc_seats = cc3->occupied_cc_seats + 1;
                            cc3->seats[cc3->occupied_cc_seats].name = name;
                            cc3->seats[cc3->occupied_cc_seats].mobile = mobile;
                        }
                        else {
                            printf("All the chair car seats have been occupied. No more left!");
                            break;
                        }
                    }
                }
            }
        case 2:
            char name[MAX_ARRAY_SIZE];
            int mobile;
            char food;
            printf("Enter number of entries: ");
            scanf("%d",&num);
            for(int i=0;i<num;i++) {
                if(ec1->occupied_cc_seats<MAX_EC_SIZE-1) {
                    printf("Enter name: ");
                    scanf("%s",name);
                    printf("Enter mobile number: ");
                    scanf("%ld",&mobile);
                    printf("Enter food type: ");
                    scanf("%c",&food);
                    ec1->occupied_cc_seats = ec1->occupied_cc_seats + 1;
                    ec1->seats[ec1->occupied_cc_seats].name = name;
                    ec1->seats[ec1->occupied_cc_seats].mobile = mobile;
                    ec1->seats[ec1->occupied_ec_seats].food = food;
                }
                else {
                    if(ec2->occupied_cc_seats<MAX_EC_SIZE-1) {
                        printf("Enter name: ");
                        scanf("%s",name);
                        printf("Enter mobile number: ");
                        scanf("%ld",&mobile);
                        printf("Enter food type: ");
                        scanf("%c",&food);
                        ec2->occupied_cc_seats = ec2->occupied_cc_seats + 1;
                        ec2->seats[ec2->occupied_cc_seats].name = name;
                        ec2->seats[ec2->occupied_cc_seats].mobile = mobile;
                        ec2->seats[ec2->occupied_ec_seats].food = food;
                    }
                    else {
                        printf("All the chair executive car seats have been occupied. No more left!");
                        break;
                    }
                    }
                }
            }
        }
    }

    return 0;
}