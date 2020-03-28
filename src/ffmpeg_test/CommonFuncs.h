/****************************************************************************************
* Copyright 2018 ��˼�����Ƽ����޹�˾
*
* @file:CommonFuncs.h
* @author:������
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

#define ComprehensiveCognition_STR "��֪�ۺϲ��Է�"
#define GKT_KNOW_STR "������ڲ��Է�"
#define GKT_KNOW_STR_OLD "GKT��֪ϸ�ڲ��Է�"
#define GKT_UNKNOW_STR "���ŷ���Է�"
#define GKT_UNKNOW_STR_OLD "GKTδ֪ϸ�ڲ��Է�"
#define SMT_UNKNOW_STR "�������Է�"
#define CQT_STR "Ψ����Է�"
#define CQT_STR_OLD "CQT���Է�(Ψ��)"
#define CQT_RM_STR "��˹����Է�"
#define CQT_RM_STR_OLD "CQT���Է�(��˹��)"
#define MGQT_STR "�Ľ���һ��������Է�"
#define AIMLESS_STR "��Ŀ��̸��"
#define GSR_STR  "Ƥ��"
#define GSR_STATE_STR "Ƥ��״̬"
#define TENSION_STR "����ֵ"
#define HR_STR  "����"
#define HRV_STR  "���ʱ���"
#define BREATH_STR  "����"
#define BO_STR  "Ѫ��"
#define BP_STR  "Ѫѹ�仯"
#define EYE_STR "����"
#define EYE_UD_STR  "��������"
#define EYE_LR_STR  "��������"
#define HEAD_STR "ͷ��"
#define HEAD_UD_STR "ͷ������"
#define HEAD_LR_STR "ͷ������"
#define EMOTION_STR  "΢����"
#define SNR_STR "�����"
#define RELAX_STR "����ֵ"
#define SHAKE_STR "ҡ��"

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
            QMessageBox::critical(msg_parent, QObject::tr("��ʾ"), QObject::tr("���ݿ����ʧ��"));\
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
@brief ���ڶԻ���Ĭ�ϰ���esc���˳���Ϊ�˷��㣬�������ذ����¼������ʹ�øú�����esc��
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
@brief ���tabelwidget���ؼ�
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
