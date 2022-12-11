#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 1080;
const float SCREEN_HEIGHT = 900;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;


const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;


const int CMD_ZOOM_IN = 80;
const int CMD_ZOOM_OUT = CMD_ZOOM_IN +1;
const int CMD_PAN_LEFT = CMD_ZOOM_OUT + 1;
const int CMD_PAN_RIGHT = CMD_PAN_LEFT + 1;





const int NUM_OF_POINTS = 300;
const double MIN_DOMAIN = -10;
const double MAX_DOMAIN = 10;


    // int numOfPoints = 200;
    // double minDomain = -10;
    // double maxDomain = 10;


#endif // CONSTANTS_H
