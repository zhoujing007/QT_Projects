/****************************************************************************************
* Copyright 2018
*
* 文件名： logger.h
* 作者：王启波
* 时间：2018-1-19
* 摘要：该文件定义了基于c++的日志类，以及便于调用的日志宏函数
*
* 历史记录
*
*
*******************************************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>

/**@brief单例模板宏定义*/
#define  SINGLETON_OBJ(T) \
    private: \
    T();    \
    public: \
    static T* instance(){\
        static T singleton;\
        return &singleton;\
    }

/**@brief多线程支持宏定义，当不要多线程支持，注释掉该宏即可，（如果使用库需要重新编译）*/
#define ENABLE_MULTI_THREAD

//多线程支持  头文件包含
#ifdef ENABLE_MULTI_THREAD
#include <queue>
#include <thread>
#include<mutex>
#endif


namespace Log {

/**@brief 日志级别枚举体定义*/
enum LogLevel {
    Debug = 0,      ///< 调试
    Info = 1,       ///< 信息
    Warning = 2,    ///< 警告
    Error = 3,      ///< 错误，但不影响运行
    Fatal = 4       ///< 严重错误，程序可能出现崩溃
};

enum LogCodeType {
    UTF8,
    GBK
};

/**@brief 日志类定义*/
class Logger {
    /**使用单例宏，将日志类定义为单例类*/
    SINGLETON_OBJ(Logger)
public:

    ~Logger();


    /**
    * @brief 写日志接口
    * @param level 日志级别
    * @param format 日志信息格式
    * @param ... 不定长度的日志具体信息参数
    */
    void write_log(const LogLevel& level, const char* format, ...);

    /**
    * @brief 设置日志文件路径，即日志保存目录，如果不设置，将在exe目录下保存
    * @param path 日志保存路径
    */
    void set_log_name(std::string file_name);

    /*
    * @brief:    禁止写日志
    * @Returns:   void
    */
    void disable_log();
private:
    /*
    * @brief:    init_log
    * @Returns:   void
    */
    void init_log();

    /**将最终日志信息写入文件*/
    void write_file(const char* buf);

private:
    /**@brief 时间字符串类型枚举体定义*/
    enum DateTimeStringType {
        DateStr,            ///< 日期
        TimeStr,            ///< 时间
        DateTimeStr,        ///< 日期时间
    };

    /**@brief 获取时间字符串*/
    std::string get_time_str(const DateTimeStringType& type);

    /**@brief 获取日志级别字符串*/
    std::string get_level_str(const LogLevel& level);



private:
    std::ofstream           file_out_;              ///< 文件流
    std::string             log_file_name_;         ///< 日志文件名称
    bool                    enable_log_ = true;     ///< 是否写日志
    ///多线程支持
#ifdef ENABLE_MULTI_THREAD
    /**@brief 使用子线程写日志*/
    static  void thread_write_file();
    std::queue<std::string> log_queque_;            ///< 日志缓冲队列
    std::thread             out_queque_thread_;     ///< 出队列写入文件线程
    std::mutex              mutex_;                 ///< 队列操作互斥锁
    bool                    exit_ = false;          ///< 线程退出标志
    bool                    thread_run_;
#endif
};

/*
* @brief:       设置是否启用控制台输出
* @Parameter:   enable 启用标志
* @Returns:   void
*/
void enable_console_print(bool enable);

/*
* @brief:    设置日志字符编码格式，默认为gbk，可设置为utf8格式
* @Parameter: LogCodeType type
* @Returns:   void
*/
void set_code_type(LogCodeType type);

}


#define LogWrite(level,fmt,...)\
    {\
        std::string str_fmt = fmt;\
        str_fmt += " ---called by file:%s at line %d";\
        Log::Logger::instance()->write_log(level, str_fmt.c_str(), __VA_ARGS__, __FILE__, __LINE__);\
    }

/**@brief 日志使用宏定义*/
#define  SetLogName(file_name) Log::Logger::instance()->set_log_name(file_name);
#define  LogDebug(fmt, ...) LogWrite(Log::Debug,fmt, __VA_ARGS__)
#define  LogInfo(fmt, ...)  LogWrite(Log::Info,fmt, __VA_ARGS__)
#define  LogWarn(fmt, ...)  LogWrite(Log::Warning,fmt, __VA_ARGS__)
#define  LogError(fmt, ...) LogWrite(Log::Error,fmt, __VA_ARGS__)
#define  LogFatal(fmt, ...) LogWrite(Log::Fatal,fmt, __VA_ARGS__)
#define  DiabelConsolePrint() Log::enable_console_print(false)
#define  LogUseUtf8() Log::set_code_type(Log::UTF8)
#define  DisableLog() Log::Logger::instance()->disable_log()
/***samples*****
LogInfo("hello world");
LogWarn("hello wolrd %d",2018);
LogInfo("2.1*2.1 = %.2f",2.1*2.1);
LogInfo("%s万岁","中国");
***************/


#endif // LOGGER_H