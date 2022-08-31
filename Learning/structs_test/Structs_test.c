#include <stdio.h>
#include <stdlib.h>

struct Room;
struct House;
void print_House (struct House house);

//Room* CreateRoom(char *name , float width , float hight , float length );
typedef struct Room Room;

struct Room {
    float width;
    float length;
    float hight;
    char *name;
};

struct House{
    char *address;
    struct Room *rooms[10];

};


int main()
{
    struct House house1;
    house1.address = "28 Thawra Street";
    int i;
    for ( i=0;i<10;i++){
        house1.rooms[i]= NULL;
    }

    Room room0;
    room0.hight=8;
    room0.width=15;
    room0.length= 20;
    room0.name = "Children`s room";

    house1.rooms[0]= &room0;
    printf(" house room 0 hight width length and name = %f %f %f %s\n",house1.rooms[0]->hight,house1.rooms[0]->width,house1.rooms[0]->length,house1.rooms[0]->name);
    print_House(house1);

    //system("PAUSE");
    return 0;
}

/*
Room* CreateRoom(char *name , float width , float hight , float length ){
    struct Room r;

    r.hight= hight;
    r.length = length;
    r.width = width;
    r.name= name ;

    return &r;
}
*/


void print_House (struct House house){
    int i;
    printf("House address : %s \n",house.address);
    for ( i=0 ; i< 10 ; i++){
        if( house.rooms[i] != NULL);
        {
            Room r = *house.rooms[i];
            //printf("room number %d name is %s size is %f x %f x %f \n ",i+1,r.name,r.width,r.length,r.hight);
            printf("room number %d name is %s \n",i+1,house.rooms[i]->name);
            printf("room size is %f x %f x %f \n",house.rooms[i]->width,house.rooms[i]->length,house.rooms[i]->hight);
        }
    }
 return ;
}
