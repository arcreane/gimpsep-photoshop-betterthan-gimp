#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class Resize
{
private:
    double scale;
    Mat resizedImage;
public:

    void resizeImage(string path, Mat image);

};