#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class OpenCV
{
    private:
        Mat image;
    public:
        ~OpenCV();
        void setDataPath(string path);
        Mat setImage(string name);
        void displayImage(string windowName);
};
