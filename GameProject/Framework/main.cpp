#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "Math.h"
#include "StartScene.h"

int main()
{
	Framework& f = Framework::GetInstance();
	f.Run(new StartScene(),L"아베코베 Re:Dive", 1920, 1080, true);

	return 0;
}
/*
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "stdafx.h"

using namespace std;
using namespace cv;

int main()
{
	for (int i = 0; i < 15; i++)
	{
		string s = "resources/Note/Animation2/before/lightingN-" + to_string(i) + "@2x.png";
		Mat input = imread(s);

		Mat input_bgra;
		cvtColor(input, input_bgra, COLOR_BGR2BGRA);

		// find all white pixel and set alpha value to zero:
		for (int y = 0; y < input_bgra.rows; ++y)
			for (int x = 0; x < input_bgra.cols; ++x)
			{
				Vec4b & pixel = input_bgra.at<Vec4b>(y, x);
				// if pixel is white
				if (pixel[0] <= 80 && pixel[1] <= 80 && pixel[2] <= 80)
				{
					// set alpha to zero:
					pixel[3] = 0;
				}
			}

		// save as .png file (which supports alpha channels/transparency)
		string s2 = "resources/Note/Animation2/after/anim" + to_string(i) + ".png";
		imwrite(s2, input_bgra);
	}
	
}*/