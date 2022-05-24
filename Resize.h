#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class Resize
{
private:
    double scale;
    int width;
    int height;
    int dim[2];
public:
    Mat resizeImage(Mat image, double scale);
};