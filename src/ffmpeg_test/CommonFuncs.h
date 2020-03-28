/****************************************************************************************
* Copyright 2018 科思创动科技有限公司
*
* @file:CommonFuncs.h
* @author:王启波
* @date:2018-5-18
* @brief:
*
* history:
*
*
*******************************************************************************************/

#ifndef COMMONFUNCS_H
#define COMMONFUNCS_H
#include <QStringList>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTableWidget>
#include "logger.h"
#include <map>

#define ComprehensiveCognition_STR "认知综合测试法"
#define GKT_KNOW_STR "犯罪情节测试法"
#define GKT_KNOW_STR_OLD "GKT已知细节测试法"
#define GKT_UNKNOW_STR "紧张峰测试法"
#define GKT_UNKNOW_STR_OLD "GKT未知细节测试法"
#define SMT_UNKNOW_STR "激励测试法"
#define CQT_STR "唯你测试法"
#define CQT_STR_OLD "CQT测试法(唯你)"
#define CQT_RM_STR "拉斯金测试法"
#define CQT_RM_STR_OLD "CQT测试法(拉斯金)"
#define MGQT_STR "改进的一般问题测试法"
#define AIMLESS_STR "无目标谈话"
#define GSR_STR  "皮电"
#define GSR_STATE_STR "皮电状态"
#define TENSION_STR "紧张值"
#define HR_STR  "心率"
#define HRV_STR  "心率变异"
#define BREATH_STR  "呼吸"
#define BO_STR  "血氧"
#define BP_STR  "血压变化"
#define EYE_STR "眼球"
#define EYE_UD_STR  "眼球上下"
#define EYE_LR_STR  "眼球左右"
#define HEAD_STR "头部"
#define HEAD_UD_STR "头部上下"
#define HEAD_LR_STR "头部左右"
#define EMOTION_STR  "微表情"
#define SNR_STR "信噪比"
#define RELAX_STR "放松值"
#define SHAKE_STR "摇晃"

const QStringList COMMON_QUES_TYPE = QStringList() << "I" << "C" << "R";
const QStringList CQT_RM_QUES_TYPE = QStringList() << "I" << "C" << "R" << "Sc" << "Sy";

#define METHOD_QUES_TYPE(METHOD_TYPE){\
        if(METHOD_TYPE == CQT_RM_STR ||METHOD_TYPE == MGQT_STR )\
        {\
            return CQT_RM_QUES_TYPE;\
        }\
        else\
        {\
            return COMMON_QUES_TYPE;\
        }\
    }


#define  ListLog(str_list) \
    for (auto str : str_list) {\
        LogInfo(str.toUtf8().data());\
    }

#define DBRetCheck(ret,msg_need,msg_parent) \
    if(!ret)\
    {\
        ListLog(DBTool::instance()->errors());\
        if(msg_need)\
        {\
            QMessageBox::critical(msg_parent, QObject::tr("提示"), QObject::tr("数据库访问失败"));\
        }\
        return; \
    }

#define DBRetCheck2(ret) \
    if(!ret)\
    {\
        ListLog(DBTool::instance()->errors());\
    }

#define FreePtr(p) if(p) delete p;p = nullptr;

#define  SINGLETON(T) \
    public: \
    static T* instance(){   \
        static T singleton;\
        return &singleton;\
    }


#define  SINGLETON2(T) \
    private: \
    T(){};    \
    ~T(){};\
    public: \
    static T* instance(){\
        static T singleton;\
        return &singleton;\
    }


#define  SQL_EXEC(mapper_id,params,result) single_db_ptr->sql_exec(#mapper_id,params,result)
#define  SQL_EXEC_2(mapper_id,params_or_result) single_db_ptr->sql_exec(#mapper_id,params_or_result)
#define  SQL_EXEC_3(mapper_id)  single_db_ptr->sql_exec(#mapper_id)

#define OPT_WIDGET_STYLE "QWidget{										\
						background-color:								\
						transparent;									\
						}												\
																		\
						QPushButton#editBtn{							\
   							background-color:#004acc;					\
						}												\
						QPushButton#delBtn{								\
   							background-color:black;						\
						}												\
						QPushButton#optBtn{								\
   							background-color:#004acc;					\
						}												\
						QPushButton{									\
							border-radius:5px;							\
							font:16px;									\
						}												\
						QPushButton:pressed								\
						{												\
							color:white;								\
							padding-top: -15px;							\
							padding-bottom: -17px;						\
}"


/*
@brief 由于对话框，默认按下esc会退出，为了方便，不用重载按键事件的类可使用该宏屏蔽esc键
*/
#define DISABLE_ESC_QUIT(BASECLASS) void keyPressEvent(QKeyEvent*event)\
    {\
        if (event->key() == Qt::Key_Escape)\
        {\
            return;\
        }\
        return BASECLASS##::keyPressEvent(event); \
    }



/*
@brief 清空tabelwidget表格控件
*/
template <class T>
void raw_clear_table(QTableWidget* table) {
    if (!table) {
        return;
    }
    int row_count = table->rowCount();
    for (int i = 0; i < row_count; i++) {
        table->removeRow(0);
    }
}

inline void clear_table(QTableWidget* table) {
    raw_clear_table<bool>(table);
}

template<class T>
std::map<std::string, int>  raw_pick_options_id(int type, const QVariantMap& data) {
    std::map<std::string, int>  prop;
    auto insert_id = [&](std::string str) {
        QString qstr = QString::fromStdString(str);
        if (data.contains(qstr)) {
            prop[str] = data[qstr].toInt();
        }

    };


    if (type >= 3/*UIMsg::AddCase*/) {
        insert_id("CASE_ID");
    }
    if (type >= 6 /*UIMsg::AddPerson*/) {
        insert_id("PERSON_ID");
    }
    if (type >= 9/*UIMsg::AddQuesList*/) {
        insert_id("QUES_LIST_ID");
    }
    if (type >= 12 /*UIMsg::AddOrderList*/) {
        insert_id("ORDER_ID");
    }
    return prop;
};

inline std::map<std::string, int>  pick_options_id(int type, const QVariantMap& data) {
    return raw_pick_options_id<bool>(type, data);
}

class line_color {
public:
    static QColor get_line_color(QString line_name) {
        QColor tem_color;
        if (line_name == SNR_STR) {
            tem_color = QColor(0, 184, 229);
        } else if (line_name == TENSION_STR) {
            tem_color = Qt::red/*QColor(255, 197, 58)*/;
        } else if (line_name == RELAX_STR) {
            tem_color = QColor(245, 108, 74);
        } else if (line_name == HR_STR) {
            tem_color = Qt::blue/*QColor(228, 86, 28)*/;
        } else if (line_name == HRV_STR) {
            tem_color = QColor(252, 141, 98);
        } else if (line_name == BREATH_STR) {
            tem_color = Qt::green/*QColor(205, 121, 255)*/;
        } else if (line_name == HEAD_UD_STR) {
            tem_color = QColor(205, 121, 255);
        } else if (line_name == HEAD_LR_STR) {
            tem_color = QColor(228, 86, 28);
        } else if (line_name == HEAD_STR) {
            tem_color = QColor(228, 86, 28);
        } else if (line_name == EYE_UD_STR) {
            tem_color = QColor(205, 121, 255);
        } else if (line_name == EYE_LR_STR) {
            tem_color = QColor(228, 86, 28);
        } else if (line_name == EYE_STR) {
            tem_color = QColor(205, 121, 255);
        } else if (line_name == EMOTION_STR) {
            tem_color = Qt::white;
        } else if (line_name == BO_STR) {
            tem_color = QColor(255, 55, 155);
        } else if (line_name == BP_STR) {
            tem_color = QColor(255, 128, 128);
        } else if (line_name == GSR_STR) {
            tem_color = Qt::cyan;
        } else if (line_name == GSR_STATE_STR) {
            tem_color = Qt::yellow;
        } else if (line_name == SHAKE_STR) {
            tem_color = QColor(166, 86, 40);
        }

        return tem_color;
    }
};
#endif // COMMONFUNCS_H
