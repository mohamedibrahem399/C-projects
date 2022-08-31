#include <stdio.h>
#include <stdlib.h>
// defining the structs to be able to be used in any part of the code
struct Room;
struct House;

// defining this function to be able to be used in any part of the code
void print_House (struct House house);

//defining the struct Room and making typedef with it called room
typedef struct Room {
    float width;
    float length;
    float hight;
    char *name;
}room;
// defining the functions create_room with type room to get easer to initialize the rooms easier
room CreateRoom(char *name , float width , float length , float hight );
// defining the struct house and makes it's variables;
struct House{
    char *address;
    struct Room *rooms[10];

};

// our main loop function
int main()
{
    //creating element in house struct it's name is house1 and setting it's arguments with values
    struct House house1;
    house1.address = "28 Thawra Street";

    int number;
    printf("enter the number of rooms\n");
    scanf("%d",&number);
    //setting values of all rooms in house1 to null
    int i;
    for ( i=0;i<10;i++){

        house1.rooms[i]= NULL;
    }

    //creating element in Room struct it's name is room1 and setting it's arguments with values
    struct Room room1;
    room1.name = "Children`s room";
    room1.width=15;
    room1.length= 20;
    room1.hight=8;
    house1.rooms[0]= &room1;

    //making variable room2 with type room and assign it's value with CreateRoom function
    room room2=CreateRoom("devil`s room" , 50 , 50 ,50);
    //linking room2 to the house to room number 1 in the house
    house1.rooms[1] = &room2;


    print_House(house1);

    return 0;
}

// defining the CreateRoom function with it's variables and make them point to the main struct
room CreateRoom(char *name , float width , float length , float hight ){
    room r;
    r.hight= hight;
    r.length = length;
    r.width = width;
    r.name= name ;

    return r;
}


// making the print_house function
void print_House (struct House house){
    int i;
    printf("House address : %s \n",house.address);
    for ( i=0 ; i< 10 ; i++){
        if( house.rooms[i] != NULL);
        {
            struct Room r = *house.rooms[i];
            //printf("room number %d name is %s size is %f x %f x %f \n ",i+1,r.name,r.width,r.length,r.hight); // this line equals to the 2 lines below
            printf("room number %d name is %s \n",i+1,house.rooms[i]->name);
            printf("room size is %f x %f x %f \n",house.rooms[i]->width,house.rooms[i]->length,house.rooms[i]->hight);
        }
    }
 return ;
}

