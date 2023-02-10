#pragma once

#include <boost/shared_ptr.hpp>
#include <opencv2/core/core.hpp>

namespace intrinsic_calib
{
// forward declarations
class ChessboardCorner;
typedef boost::shared_ptr<ChessboardCorner> ChessboardCornerPtr;
class ChessboardQuad;
typedef boost::shared_ptr<ChessboardQuad> ChessboardQuadPtr;

class Chessboard
{
public:
    Chessboard(cv::Size board_size, cv::Mat& image);

    void find_corners(bool use_openCV = false);
    const std::vector<cv::Point2f>& get_corners(void) const;
    bool corners_found(void) const;

    const cv::Mat& get_image(void) const;
    const cv::Mat& get_sketch(void) const;

private:
    bool find_chessboard_corners(const cv::Mat& image,
                               const cv::Size& patternSize,
                               std::vector<cv::Point2f>& corners,
                               int flags, bool useOpenCV);

    bool find_chessboard_corners_improved(const cv::Mat& image,
                                       const cv::Size& patternSize,
                                       std::vector<cv::Point2f>& corners,
                                       int flags);

    void clean_found_connected_quads(std::vector<ChessboardQuadPtr>& quadGroup, cv::Size patternSize);

    void findConnectedQuads(std::vector<ChessboardQuadPtr>& quads,
                            std::vector<ChessboardQuadPtr>& group,
                            int group_idx, int dilation);

//    int checkQuadGroup(std::vector<ChessboardQuadPtr>& quadGroup,
//                       std::vector<ChessboardCornerPtr>& outCorners,
//                       cv::Size patternSize);

    void labelQuadGroup(std::vector<ChessboardQuadPtr>& quad_group,
                        cv::Size patternSize, bool firstRun);

    void findQuadNeighbors(std::vector<ChessboardQuadPtr>& quads, int dilation);

    int augmentBestRun(std::vector<ChessboardQuadPtr>& candidateQuads, int candidateDilation,
                       std::vector<ChessboardQuadPtr>& existingQuads, int existingDilation);

    void generateQuads(std::vector<ChessboardQuadPtr>& quads,
                       cv::Mat& image, int flags,
                       int dilation, bool firstRun);

    bool checkQuadGroup(std::vector<ChessboardQuadPtr>& quads,
                        std::vector<ChessboardCornerPtr>& corners,
                        cv::Size patternSize);

    void getQuadrangleHypotheses(const std::vector< std::vector<cv::Point> >& contours,
                                 std::vector< std::pair<float, int> >& quads,
                                 int classId) const;

    bool checkChessboard(const cv::Mat& image, cv::Size patternSize) const;

    bool checkBoardMonotony(std::vector<ChessboardCornerPtr>& corners,
                            cv::Size patternSize);

    bool matchCorners(ChessboardQuadPtr& quad1, int corner1,
                      ChessboardQuadPtr& quad2, int corner2) const;

    cv::Mat image_;
    cv::Mat sketch_;
    std::vector<cv::Point2f> corners_;
    cv::Size board_size_;
    bool corners_found_;
};

} // namespace intrinsic_calib


