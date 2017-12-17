#include <jni.h>
#include <opencv2/opencv.hpp>
#include <fastguidedfilter.h>
#include "dehaze.h"
#include "darkchannel.h"

using namespace cv;
using namespace std;

extern  "C" {
/*
 * Class:     cn_scut_dongxia_hazeremove_CameraFragment
 * Method:    nativeProcessFrame
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeProcessFrame
        (JNIEnv *, jobject, jlong);

/*
 * Class:     cn_scut_dongxia_hazeremove_CameraFragment
 * Method:    nativeProcessFrame
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeProcessFrame__JJ
        (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     cn_scut_dongxia_hazeremove_CameraFragment
 * Method:    nativeCreateHazeRemoveModel
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeCreateHazeRemoveModel
        (JNIEnv *, jobject);

/*
 * Class:     cn_scut_dongxia_hazeremove_CameraFragment
 * Method:    nativedeleteHazeRemoveModel
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeDeleteHazeRemoveModel
        (JNIEnv *, jobject);

}

DeHaze *deHaze;


JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeProcessFrame
        (JNIEnv *env, jobject, jlong addrRgba){
    Mat &mRgb = *(Mat *) addrRgba;

//    DeHaze deHaze(7,0.1,0.95,10E-6);
//    mRgb = deHaze.imageHazeRemove(mRgb);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);
//    cv::cvtColor(mRgb,mRgb,COLOR_BGRA2RGBA);
//    cv::cvtColor(mRgb,mRgb,COLOR_RGBA2BGRA);


    mRgb = (*deHaze).videoHazeRemove(mRgb);
}

JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeCreateHazeRemoveModel
        (JNIEnv *, jobject){
    if (deHaze != NULL){
        delete deHaze;
    }
    deHaze = new DeHaze(7,0.1,0.95,10E-6);
    deHaze->setFPS(15);
}


JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeDeleteHazeRemoveModel
        (JNIEnv *, jobject){
    if (deHaze != NULL){
        delete deHaze;
    }
}

/*
 * Class:     cn_scut_dongxia_hazeremove_CameraFragment
 * Method:    nativeProcessFrame
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cn_scut_dongxia_hazeremove_CameraFragment_nativeProcessFrame__JJ
        (JNIEnv *, jobject, jlong origAddr, jlong resultAddr){
//    Mat &orig = *(Mat *) origAddr;
//    Mat &result = *(Mat *) resultAddr;
//
//    DeHaze deHaze(7,0.1,0.95,10E-6);
//    result = (deHaze).videoHazeRemove(orig);
////    result = (*deHaze).videoHazeRemove(orig);
}


//Vec3f estimateAtmosphericLight(const cv::Mat& I, int r){
//    double start = clock();
//    Vec3f atmosphericLight(0,0,0);
//
//    Mat minChannel = calcMinChannel(I);
//
//    double maxValue = 0;
//    Mat aimRoi;
//
////    #pragma omp parallel for
//    for (int i = 0; i < minChannel.rows; i+=r) {
//        for (int j = 0; j < minChannel.cols; j+=r) {
//            int w = (j+r < minChannel.cols) ? r : minChannel.cols-j;
//            int h = (i+r < minChannel.rows) ? r : minChannel.rows-i;
//            Mat roi(minChannel,Rect(j,i,w,h));
//            cv::Scalar mean, std, score;
//            meanStdDev(roi,mean,std);
//            score = mean -std;
//            if (score.val[0] > maxValue){
//                maxValue = score.val[0];
//                aimRoi = Mat(I,Rect(j,i,w,h));
//            }
//        }
//    }
//
//    cv::Scalar mean,std;
//    meanStdDev(aimRoi,mean,std);
//
//    atmosphericLight[0] = static_cast<float > (mean.val[0]);
//    atmosphericLight[1] = static_cast<float> (mean.val[1]);
//    atmosphericLight[2] = static_cast<float> (mean.val[2]);
//
//    double stop = clock();
//    LOGD("估计大气光耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
////    cout<<"atmosphericLight" << atmosphericLight << endl;
////    cout<<"估计大气光耗时："<<(stop - start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
//
//    return atmosphericLight;
//}
//
//cv::Mat estimateTransmission(const cv::Mat& I, Vec3f atmosphericLight,
//                             double omega, double eps, int r){
//
//    double start = clock();
//    double stop;
//
////    CV_Assert(I.channels() == 3);
//    Mat I_YUV;
//    cvtColor(I,I_YUV,COLOR_BGR2YUV);
//
//    vector<Mat> channels;
//    split(I_YUV,channels);
//
//    channels[0] = channels[0]/(atmosphericLight[0]*0.114 +
//            atmosphericLight[1]*0.587 + atmosphericLight[2]*0.299);
//
////    vector<Mat> channels;
////    split(I,channels);
//
////    channels[0] = channels[0]/atmosphericLight[0];
////    channels[1] = channels[1]/atmosphericLight[1];
////    channels[2] = channels[2]/atmosphericLight[2];
//
////    Mat normalized;
////    merge(channels,normalized);
//
//    start = clock();
//    Mat darkChannel = calcDarkChannel(channels[0],r);
//    Mat transmission = 1.0 - omega * darkChannel;
//    stop = clock();
//    LOGD("粗略透射率计算耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    start = clock();
//    //透射率修正
//    float k = 0.3;
//    transmission = min(max(k/abs(1-darkChannel),1).mul(transmission),1);
//    stop = clock();
//    LOGD("透射率修正耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
////    Mat gray;
////    cvtColor(I,gray,CV_BGRA2GRAY);
//    //10ms左右
//    start = clock();
//    transmission = fastGuidedFilter(channels[0], transmission, 8*r, 4, eps);
//    stop = clock();
//    LOGD("快速导向滤波耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    return transmission;
//}
//
//cv::Mat DeHaze::recover(const cv::Mat& I, const cv::Mat& transmission,
//                        Vec3f atmosphericLight){
//
//    double start;
//    double stop;
//
//    start = clock();
//    vector<Mat> channels;
//    split(I,channels);
//    stop = clock();
//    LOGD("分离原始图像耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    start = clock();
//    Mat t = transmission;
//
//    channels[0] = (channels[0]-atmosphericLight[0])/t + atmosphericLight[0];
//    channels[1] = (channels[1]-atmosphericLight[1])/t + atmosphericLight[1];
//    channels[2] = (channels[2]-atmosphericLight[2])/t + atmosphericLight[2];
//    Mat recover;
//    merge(channels,recover);
//
//    stop = clock();
//    LOGD("粗略恢复图像耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
////    start = clock();
////    pow(recover,0.7,recover);//3ms gamma矫正
//////    LUT(recover,lookUpTable,recover);
////    stop = clock();
////    LOGD("gamma矫正耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    start = clock();
//    recover.convertTo(recover,CV_8U);
//    stop = clock();
//    LOGD("转化成8位图像耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    start = clock();
//    //pow(recover,0.7,recover);//3ms gamma矫正
//    LUT(recover,lookUpTable,recover);
//    stop = clock();
//    LOGD("gamma矫正耗时：%.2f ms", (stop-start)/CLOCKS_PER_SEC*1000);
//
//    return recover;
//}