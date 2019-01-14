#include"cv_helper.h"
#include <fstream>
#include <time.h>

CV_TimeSpan::CV_TimeSpan() :_start(0)
{
	start();
}

void CV_TimeSpan::start()
{
	_start = cv::getTickCount();
}

double CV_TimeSpan::stop()
{
	return (cv::getTickCount() - _start) / cv::getTickFrequency();
}


bool cv_helper::get_imgPath(const std::string &name, std::string &img)
{

	std::ifstream ifs(name, std::ios::binary);
	if (ifs) { img = name; return true; };

	std::string folder(getenv("IMG_FOLDER"));
	if (folder.empty())
	{
		return false;
	}

	img = folder + name;
	ifs.clear(); ifs.close();
	ifs.open(img,std::ios::binary);

	auto func_open_with_appendix = [&](const std::string &app)
	{
		std::string temp = img + app;
		ifs.close();
		ifs.open(temp, std::ios::binary);
		if (ifs) { img=temp; return true; }

		return false;
	};

	if (!ifs)
	{	
		//try to add some common appendix
		if (img.rfind('.') == std::string::npos)
		{
			if (!func_open_with_appendix(".png"))
			{
				func_open_with_appendix(".jpg");
			}
		}
	}

	if (!ifs)
	{
		std::cerr << "img " << name << " not exits.\n";
		return false;
	}

	return true;
}

bool cv_helper::get_imgPathEx(const std::string &name, cv::String &img)
{
	std::string _img;
	bool b = get_imgPath(name, _img);
	img = _img;

	return b;
}

std::string cv_helper::get_localTimeStr(const std::string &format)
{
	time_t t;
	time(&t);
	tm *ptm = localtime(&t);
	char buf[50] = { 0 };
	strftime(buf, sizeof(buf), format.c_str(), ptm);
	return std::string(buf);
}

CerrRdWrapper::CerrRdWrapper(std::ostream &os)
{
	pbuf = (void*)std::cerr.rdbuf();
	std::cerr.rdbuf(os.rdbuf());
}

CerrRdWrapper::~CerrRdWrapper()
{
	std::cerr.rdbuf((decltype(std::cerr.rdbuf()))pbuf);
	pbuf = nullptr;
}

bool cv_helper::compare(const cv::Mat &m1, const cv::Mat &m2)
{
	if (m1.empty() || m2.empty()) return false;
	cv::Mat com = m1 != m2;
	bool eq = cv::countNonZero(com) == 0;
	return eq;

}