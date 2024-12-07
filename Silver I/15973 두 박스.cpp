#include<iostream>
using namespace std;
struct coord{
    int x1,y1;
    int x2,y2;
};
bool checkPoint(coord box1,coord box2){
    if(box1.x1 == box2.x2 && box1.y1 == box2.y2) return true;
    if(box1.x1 == box2.x2 && box1.y2 == box2.y1) return true;
    if(box1.x2 == box2.x1 && box1.y2 == box2.y1) return true;
    if(box1.x2 == box2.x1 && box1.y1 == box2.y2) return true;
    return false;
}

bool checkLine(coord box1, coord box2){
    if(box1.x1 == box2.x2) return true;
    if(box1.x2 == box2.x1) return true;
    if(box1.y1 == box2.y2) return true;
    if(box1.y2 == box2.y1) return true;
    return false;
}

bool checkNull(coord box1, coord box2){
    if(box1.y2 < box2.y1) return true;
    if(box1.x2 < box2.x1) return true;
    if(box1.y1 > box2.y2) return true;
    if(box1.x1 > box2.x2) return true;
    return false;
}
int main()
{
    coord box[2]={};
    cin>>box[0].x1>>box[0].y1>>box[0].x2>>box[0].y2;
    cin>>box[1].x1>>box[1].y1>>box[1].x2>>box[1].y2;

    if(checkNull(box[0],box[1])){
        printf("NULL");
    }
    else if(checkPoint(box[0],box[1])){
        printf("POINT");
    }
    else if(checkLine(box[0],box[1])){
        printf("LINE");
    }
    else{
        printf("FACE");
    }

    return 0;
}