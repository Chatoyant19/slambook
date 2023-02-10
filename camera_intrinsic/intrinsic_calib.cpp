#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

std::string input_images_path_ = "/home/wd/projects/camodocal/data/images"; // chessboard file path
bool verbose_ = true; //Verbose output, hahahaha, interesting naming
std::string prefix = "img";  // prefix of images
std::string extension = ".bmp";  // file extension of images
// board_size.width = 9: Number of inner corners on the chessboard pattern in x direction
// board_size.height = 6: Number of inner corners on the chessboard pattern in y direction
cv::Size board_size = cv::Size(9, 6);

// look for images in input directory
bool loadImagesFromDir(std::vector<std::string>& image_file_names);
bool findChessBoard();

int main(int argc, char** argv) {
  // load image from directory
  std::vector<std::string> image_file_names;
  if(!loadImagesFromDir(image_file_names)) {
    std::cerr << "cannot load images from input image directory" << std::endl;
  }

  cv::Mat image = cv::imread(image_file_names.front(), -1);
  const cv::Size frame_size = image.size();
  if (verbose_) {
    std::cout << "frame size: " << frame_size << std::endl;
  }
  return 0;
}

// todo: unorder loading
bool loadImagesFromDir(std::vector<std::string>& image_file_names) {
  if (!boost::filesystem::exists(input_images_path_) && !boost::filesystem::is_directory(input_images_path_))
  {
    std::cerr << "# ERROR: Cannot find input directory: " << input_images_path_ << "." << std::endl;
    return false;
  }

  boost::filesystem::directory_iterator itr;
  for (boost::filesystem::directory_iterator itr(input_images_path_); itr != boost::filesystem::directory_iterator(); ++itr)
  {
    if (!boost::filesystem::is_regular_file(itr->status()))
    {
      continue;
    }

    std::string filename = itr->path().filename().string();
    // std::cout << 
    if (verbose_) { 
      std::cout << "filename: " << filename << std::endl;
    }

    // check if prefix matches
    if (!prefix.empty())
    {
      if (filename.compare(0, prefix.length(), prefix) != 0)
      {
        std::cerr << "prefix is wrong!" << std::endl;
        continue;
      }
    }

    // check if file extension matches
    if (filename.compare(filename.length() - extension.length(), extension.length(), extension) != 0)
    {
        continue;
    }

    image_file_names.push_back(itr->path().string());

    if (verbose_)
    {
      std::cout << "# INFO: Adding " << image_file_names.back() << std::endl;
    }

    if (image_file_names.empty())
    {
      std::cerr << "# ERROR: No chessboard images found." << std::endl;
      return false;
    }

    if (verbose_)
    {
      std::cout << "# INFO: # images: " << image_file_names.size() << std::endl;
    }
  }

  return true;
}

bool findChessboard() {
  std::vector<bool> chessboard_found(image_file_names.size(), false);
  for (size_t i = 0; i < image_file_names.size(); ++i)
  {
    cv::Mat chessboard_image = cv::imread(image_file_names.at(i), -1);

    camodocal::Chessboard chessboard(board_size, chessboard_image);

    chessboard.findCorners(useOpenCV);
    if (chessboard.cornersFound())
    {
        if (verbose)
        {
            std::cerr << "# INFO: Detected chessboard in image " << i + 1 << std::endl;
        }

        calibration.addChessboardData(chessboard.getCorners());

        cv::Mat sketch;
        chessboard.getSketch().copyTo(sketch);

        cv::imshow("Image", sketch);
        cv::waitKey(50);
    }
    else if (verbose)
    {
        std::cerr << "# INFO: Did not detect chessboard in image " << i + 1 << std::endl;
    }
    chessboardFound.at(i) = chessboard.cornersFound();
  }
}