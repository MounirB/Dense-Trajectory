#include "opencv2/opencv.hpp" // opencv2 headers !
using namespace cv;           // c++ namespaces !

#include <iostream>
#include <stdio.h>
using namespace std;

int main( int argc, char** argv )
{
	int frameNum = 0;

	VideoCapture capture;         // c++ classes !

	char* video = argv[1];
	capture.open(video);

    if (! capture.isOpened())     // you have to CHECK this !
    {
        cout << "could not open the VideoCapture !" << endl;
        return -1;
    }

    while(true)
    {
        Mat frame;
        bool ok = capture.read(frame);
        if (! ok)             // also, mandatory CHECK !
             break; 
        imshow("ocv",frame);
        int k = waitKey(10);
        if (k==27) break;     // esc. pressed
    }
    return 0;
}