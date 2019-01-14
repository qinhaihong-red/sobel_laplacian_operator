#pragma once
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <iostream>

#define PRINTMAT(_M) \
std::cerr << #_M <<" is:\n" <<_M<< std::endl;

#define NPF cv::Formatter::FMT_NUMPY
#define SRC_WIND "src_wind"
#define DST_WIND "dst_wind"

//can not output matrix that dims>2,
//and when dims>2,nros=ncols=-1.
#define PRINTMAT_F(_M,_F) \
if(_M.dims>2){std::cerr<<_M.size;}\
else{std::cerr << #_M <<" is:\n" <<format( _M ,_F)<<", "<<"["<<_M.rows<<","<<_M.cols<<"]" << std::endl;}

#define EXCEPTION_INFO(err) \
std::cerr<<"Exception occur:\n"<<__FILE__<<":"<<__LINE__<<"\n"<<err<<std::endl;

#define _EXIT_FAILURE \
exit(EXIT_FAILURE);

#define _CHECK_FAILURE(call) \
if(!call)\
{std::cerr<<"Error occur:\n"<<__FILE__<<":"<<__LINE__<<"\n";\
_EXIT_FAILURE;}

#define CV_TRY_CATCH(call) \
try\
{call;}\
catch(const cv::Exception& e)\
{EXCEPTION_INFO(e.what());_EXIT_FAILURE;}


#define PRINT_SZ(_M) \
if(_M.dims>2){std::cerr<<_M.size<<std::endl;}\
else{std::cerr << "["<<_M.rows<<","<<_M.cols<<"]" << std::endl;}

#define PRINT_SHAPE(_M) (PRINT_SZ(_M))

#define COND_BEGIN_ONCE do{
#define COND_END_ONCE }while(false);

#define COND_BEGIN_LOOP do{
#define COND_END_LOOP }while(true);

#define COND_PRED_BREAK(COND,PRED) \
if(COND){PRED;break;}

#define COND_PRED(COND,PRED) \
if(COND){PRED;}

#define _MAIN_ARGS int argc,char **argv

#define CV_CVT2GRAY(src,dst) \
cv::Mat dst;cv::cvtColor(src,dst,cv::COLOR_BGR2GRAY);




class CV_TimeSpan
{
public:
	CV_TimeSpan();
	~CV_TimeSpan() {}
	void start();
	double stop();

	CV_TimeSpan(const CV_TimeSpan&) = delete;
	CV_TimeSpan& operator=(const CV_TimeSpan&) = delete;

private:
	int64 _start;
};

class CerrRdWrapper
{
	public:
		CerrRdWrapper(std::ostream &os);
		~CerrRdWrapper();

		CerrRdWrapper(const CerrRdWrapper&) = delete;
		CerrRdWrapper& operator=(const CerrRdWrapper&) = delete;

private:
	void *pbuf;
};

namespace cv_helper
{
	typedef void(*bar_func)(int, void*);

	namespace err
	{
#define ERR_CODE_FILESYSTEM 1
	}

	bool get_imgPath(const std::string &name,std::string &img);
	bool get_imgPathEx(const std::string &name,cv::String &img);
	bool compare(const cv::Mat &m1,const cv::Mat &m2);
	std::string get_localTimeStr(const std::string &format="%Y_%m_%d_%H_%M_%S");
}